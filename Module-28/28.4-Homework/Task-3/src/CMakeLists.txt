cmake_minimum_required (VERSION 3.8)

add_executable ("Task-3" "main.cpp" "${MY_INCLUDE_DIR}/Order.h" "Order.cpp")
target_include_directories(Task-3 PUBLIC ${MY_INCLUDE_DIR})
