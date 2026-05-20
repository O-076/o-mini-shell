cmake_minimum_required(VERSION 3.10)
project(o-mini-shell)

add_executable(o-mini-shell src/main.cpp src/executer.cpp src/parser.cpp src/builtins.cpp)
target_include_directories(o-mini-shell PRIVATE include)