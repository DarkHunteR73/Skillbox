cmake_minimum_required (VERSION 3.8)

add_executable ("Task-1" "main.cpp" "${MY_INCLUDE_DIR}/Swimmer.h" "Swimmer.cpp")
target_include_directories(Task-1 PUBLIC ${MY_INCLUDE_DIR})
