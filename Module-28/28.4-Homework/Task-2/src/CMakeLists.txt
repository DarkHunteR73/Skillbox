cmake_minimum_required (VERSION 3.8)

add_executable ("Task-2" "main.cpp" "${MY_INCLUDE_DIR}/Train.h" "Train.cpp")
target_include_directories(Task-2 PUBLIC ${MY_INCLUDE_DIR})
