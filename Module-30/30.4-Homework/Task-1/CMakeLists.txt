﻿cmake_minimum_required (VERSION 3.8)

project ("Task-1" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335) # The commit hash for 1.7.2. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

cmake_policy(SET CMP0079 NEW)
add_subdirectory(src)

target_link_libraries(Task-1 PRIVATE cpr::cpr)