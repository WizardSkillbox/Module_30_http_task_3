cmake_minimum_required(VERSION 3.16)
project(Module_30_http_task_3)

set(CMAKE_CXX_STANDARD 11)

option(ENABLE_TESTING "Enable test emulation" OFF)

set(CPR_BUILD_TESTS OFF)
set(CPR_BUILD_TESTS_SSL OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr
        GIT_REPOSITORY https://github.com/whoshuu/cpr.git
        GIT_TAG 1.6.2
        )
FetchContent_MakeAvailable(cpr)

add_executable(Module_30_http_task_3)

target_sources(Module_30_http_task_3
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
        )

target_include_directories(Module_30_http_task_3
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(Module_30_http_task_3
        PRIVATE
        ENABLE_TESTING=$<BOOL:${ENABLE_TESTING}>
        )

target_link_libraries(Module_30_http_task_3
        PRIVATE
        cpr::cpr)
