cmake_minimum_required(VERSION 3.20)
project(Homework16)

set(CMAKE_CXX_STANDARD 11)

add_executable(Homework16 main.cpp src/main/FigureComponents/Figure.cpp src/main/FigureComponents/Figure.h src/main/Figures/Rectangle.cpp src/main/Figures/Rectangle.h src/main/Figures/Triangle.cpp src/main/Figures/Triangle.h src/main/FigureComponents/Point.cpp src/main/FigureComponents/Point.h src/main/Figures/Polygon.cpp src/main/Figures/Polygon.h src/main/FigureComponents/Line.cpp src/main/FigureComponents/Line.h src/main/Figures/Pentagon.cpp src/main/Figures/Pentagon.h)
