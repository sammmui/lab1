cmake_minimum_required(VERSION 3.10)

project(lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    cards.cpp
    stack.cpp
    main.cpp
)
add_executable(lab1 ${SOURCES})
