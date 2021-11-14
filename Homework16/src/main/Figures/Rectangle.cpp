//
// Created by Alex on 14.11.2021.
//
#include "../FigureComponents/Point.h"
#include "Rectangle.h"
#include "iostream"

Rectangle::Rectangle(Point leftBottom, Point rightTop){
    this->x1=leftBottom.getX();
    this->y1=leftBottom.getY();
    this->x2=rightTop.getX();
    this->y2=rightTop.getY();
}

RectangleEdgesLength Rectangle::getEdgesLength() {
    double edge1 = std::abs(x1-x2);
    double edge2 = std::abs(y1-y2);

    RectangleEdgesLength length = RectangleEdgesLength(std::min(edge1, edge2), std::max(edge1, edge2));

    return length;
}

double Rectangle::area() {
    return std::abs(x1-x2)*std::abs(y1-y2);
}

double Rectangle::perimeter(){
    RectangleEdgesLength edgesLength = getEdgesLength();

    return 2*(edgesLength.getShortEdge()+edgesLength.getLongEdge());
}

bool Rectangle::isConvex() {
    if (area()!=0){
        return true;
    }
    return false;
}

Rectangle::~Rectangle() = default;

