//
// Created by Alex on 14.11.2021.
//

#include "Point.h"

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double x) {
    Point::x = x;
}

void Point::setY(double y) {
    Point::y = y;
}
