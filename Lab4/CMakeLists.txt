cmake_minimum_required(VERSION 3.10)
project(Lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3 main.cpp BruteForce.h BruteForce.cpp GenerateFiles.h GenerateFiles.cpp DynamicProgramming.h DynamicProgramming.cpp Graph.h Graph.cpp interfaceInterface.h TSPInterface.h Factory.h Factory.cpp TSPInterface.cpp Solution.h Solution.cpp Tabu.h Tabu.cpp Genetic.h Genetic.cpp)