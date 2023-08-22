cmake_minimum_required(VERSION 3.23)
project(Metodik_labb2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Metodik_labb2 main.cpp shape.cpp shape.h Rectangle.cpp Rectangle.h Circle.cpp Circle.h Cylinder.cpp Cylinder.h Parallelepiped.cpp Parallelepiped.h RoundedRectangle.cpp RoundedRectangle.h Square.cpp Square.h)
