cmake_minimum_required(VERSION 3.10)
project(DateClass LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
add_executable(main main.cpp AdjacencyLists.cpp)
add_executable(shortest shortest.cpp AdjacencyLists.cpp)
