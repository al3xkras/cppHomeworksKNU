//
// Created by Alex on 14.11.2021.
//

#include "Line.h"
#include "cmath"

Line::Line(const Point &a, const Point &b) : a(a), b(b) {}

double Line::angleWithPoint(Point point) {
    Point lineVector1(b.getX()-a.getX(),b.getY()-a.getY());
    Point lineVector2(point.getX()-a.getX(),point.getY()-a.getY());

    double det = (lineVector1.getX()*lineVector2.getY()-lineVector2.getX()*lineVector1.getY());

    det = (det<=0)?1.0:-1.0;

    double cosine = lineVector1.dotWith(lineVector2)/(a.distanceTo(b)+a.distanceTo(point));
    double angle = acos(cosine);

    return det*angle;
}

std::ostream &operator<<(std::ostream &os, const Line &line) {
    os << "a: " << line.a << " b: " << line.b;
    return os;
}
