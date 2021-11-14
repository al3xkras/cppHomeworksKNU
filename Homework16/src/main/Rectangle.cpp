//
// Created by Alex on 14.11.2021.
//

#include "Rectangle.h"
#include "iostream"

Rectangle::Rectangle(double x1, double y1, double x2, double y2){
    this->x1=x1;
    this->y1=y1;
    this->x2=x2;
    this->y2=y2;
}

EdgesLength Rectangle::getEdgesLength() const{
    double edge1 = std::abs(x1-x2);
    double edge2 = std::abs(y1-y2);

    EdgesLength length = EdgesLength(std::min(edge1,edge2),std::max(edge1,edge2));

    return length;
}

double Rectangle::area() const {
    return std::abs(x1-x2)*std::abs(y1-y2);
}

double Rectangle::perimeter() const{
    EdgesLength edgesLength = getEdgesLength();

    return 2*(edgesLength.getShortEdge()+edgesLength.getLongEdge());
}

