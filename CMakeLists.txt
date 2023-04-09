cmake_minimum_required(VERSION 3.25)
project(Physics)
set(CMAKE_CXX_STANDARD 17)
add_executable(script "src/script.cpp" "includes/gates.hpp" "includes/conv.hpp" logos/logo.hpp)