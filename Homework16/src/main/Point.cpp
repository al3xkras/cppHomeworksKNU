//
// Created by Alex on 14.11.2021.
//

#include "cmath"
#include "Point.h"

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double X) {
    Point::x = X;
}

void Point::setY(double Y) {
    Point::y = Y;
}

double Point::distanceTo(Point other) {
    double dist = sqrt(
            pow(getX()-other.getX(),2)+
            pow(getY()-other.getY(),2));
    return dist;
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "x: " << point.x << " y: " << point.y;
    return os;
}
