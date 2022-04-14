cmake_minimum_required (VERSION 3.8)
project ("Task-2" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(src)
cmake_policy(SET CMP0079 NEW)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(Task-2 PRIVATE nlohmann_json::nlohmann_json)
