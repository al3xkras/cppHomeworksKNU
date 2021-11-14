//
// Created by Alex on 14.11.2021.
//

#include "Triangle.h"
#include "cstdlib"
#include "cmath"

Triangle::Triangle(const Point &a,const Point &b,const Point &c){
    points = (Point*)calloc(3,sizeof(Point));
    points[0] = a;
    points[1] = b;
    points[2] = c;
}

Triangle::~Triangle() {
    delete[](&points);
}

TriangleEdgesLength Triangle::getEdgesLength() {
    double AB = points[0].distanceTo(points[1]);
    double BC = points[1].distanceTo(points[2]);
    double AC = points[0].distanceTo(points[2]);

    TriangleEdgesLength length = TriangleEdgesLength(AB,BC,AC);
    return length;
}

double Triangle::area() {
    TriangleEdgesLength length = getEdgesLength();
    double p = (length.getAb()+length.getBc()+length.getAc())/2;
    return sqrt(p*(p-length.getAb())*(p-length.getBc())*(p-length.getAc()));
}

double Triangle::perimeter() {
    TriangleEdgesLength length = getEdgesLength();
    return (length.getAb()+length.getBc()+length.getAc());
}

std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
    os << "Triangle: ";
    for (int i=0; i<3; i++){
        os<<'('<<triangle.points[i]<<"), ";
    }
    return os;
}

TriangleEdgesLength::TriangleEdgesLength(double ab, double bc, double ac) : AB(ab), BC(bc), AC(ac) {}

double TriangleEdgesLength::getAb() const {
    return AB;
}

double TriangleEdgesLength::getBc() const {
    return BC;
}

double TriangleEdgesLength::getAc() const {
    return AC;
}

std::ostream &operator<<(std::ostream &os, const TriangleEdgesLength &length) {
    os << "AB: " << length.AB << " BC: " << length.BC << " AC: " << length.AC;
    return os;
}
