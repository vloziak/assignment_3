cmake_minimum_required(VERSION 3.29)
project(assignment_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment_3
    Board.cpp
    Board.h
    Circle.cpp
    Circle.h
    Line.cpp
    Line.h
    main.cpp
    Shape.cpp
    Shape.h
    Square.cpp
    Square.h
    Triangle.cpp
    Triangle.h)
