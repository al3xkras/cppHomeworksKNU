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

RectangleEdgesLength Rectangle::getEdgesLength() const{
    double edge1 = std::abs(x1-x2);
    double edge2 = std::abs(y1-y2);

    RectangleEdgesLength length = RectangleEdgesLength(std::min(edge1, edge2), std::max(edge1, edge2));

    return length;
}

double Rectangle::area() const {
    return std::abs(x1-x2)*std::abs(y1-y2);
}

double Rectangle::perimeter() const{
    RectangleEdgesLength edgesLength = getEdgesLength();

    return 2*(edgesLength.getShortEdge()+edgesLength.getLongEdge());
}

Rectangle::~Rectangle() = default;

