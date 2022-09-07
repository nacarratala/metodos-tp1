cmake_minimum_required(VERSION 3.23)
project(pagerank)

set(CMAKE_CXX_STANDARD 14)

add_executable(pagerank main/main.cpp main/model/DOKMatrix.cpp main/model/DOKMatrix.h main/model/LILMatrix.cpp main/model/LILMatrix.h main/model/COOMatrix.cpp main/model/COOMatrix.h)
