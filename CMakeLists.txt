cmake_minimum_required(VERSION 3.10)

project(astar)

# ���Ӿ�̬��
add_library(astar_demo STATIC "A_star.cpp" "A_star.h")

add_executable(astar "A_star_main.cpp")

target_link_libraries(astar astar_demo)