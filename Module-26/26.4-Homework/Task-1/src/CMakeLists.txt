cmake_minimum_required (VERSION 3.8)

add_executable ("Task-1" "main.cpp" "${MY_INCLUDE_DIR}/Player.h" "${MY_INCLUDE_DIR}/Track.h" "Player.cpp" "Track.cpp")
target_include_directories(Task-1 PUBLIC ${MY_INCLUDE_DIR})
