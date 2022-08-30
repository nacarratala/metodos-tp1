cmake_minimum_required(VERSION 3.23)
project(pagerank)

set(CMAKE_CXX_STANDARD 14)

# tp1 implementation
include_directories(main/)
#include_directories(main/model)

# Google test engine 
include_directories(test/google-test)
add_subdirectory(test/google-test)

# tp1 implementation
file(GLOB HEADERS_TP main/model/*.h)			
file(GLOB SOURCES_TP main/model/*.cpp)
add_executable(pagerank main/main.cpp ${HEADERS_TP} ${SOURCES_TP})


# Google test engine 
file(GLOB TEST_SOURCES test/*.cpp)
add_executable(run_tests ${TEST_SOURCES} ${HEADERS_TP} ${SOURCES_TP})
target_link_libraries(run_tests gtest gtest_main)
