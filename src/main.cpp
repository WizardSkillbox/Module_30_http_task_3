#include <iostream>
#include <string>
#include <map>

#include <cpr/cpr.h>

using namespace std;

static string GetStringFromStream(const string &message) {
    string str;
    while (true) {
        cout << message << endl;
        while (str.empty()) {
            getline(cin, str);
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(LLONG_MAX, '\n');
        } else {
            break;
        }
    }
    return str;
}

static string PerformGetRequest(const map<string, string> & args) {
    cpr::Parameters parameters({});
    for(const auto & arg : args) {
        parameters.Add({arg.first, arg.second});
    }

    return cpr::Get(cpr::Url("http://httpbin.org/get"), parameters).text;
}

static string PerformPostRequest(const map<string, string> & args) {
    cpr::Payload payload({});
    for(const auto & arg : args) {
        payload.Add({arg.first, arg.second});
    }

    return cpr::Post(cpr::Url("http://httpbin.org/post"), payload).text;
}

int main() {
    map<string, string> args;
    string key, val;
    string (*PerformRequestFunc)(const map<string, string> & args) = nullptr;

    while (true){
        key = GetStringFromStream("Enter name of argument or a type of request (get| post): ");
        if(key =="get"){
            PerformRequestFunc = PerformGetRequest;
            break;
        } else if (key == "post") {
            PerformRequestFunc = PerformPostRequest;
            break;
        }

        val = GetStringFromStream(string("Enter value of argument " + key + ":"));
        args[key] = val;
    }

    cout << PerformRequestFunc(args) << endl;
    return 0;
}
