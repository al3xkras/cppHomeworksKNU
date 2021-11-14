//
// Created by Alex on 14.11.2021.
//

#include "Pentagon.h"

Pentagon::Pentagon(Point *points, size_t points_size) : Polygon(points, points_size){
    this->pentagon = Polygon(points,points_size);
}

Pentagon::~Pentagon() {
    delete(&pentagon);
}

bool Pentagon::isConvex() {
    return pentagon.isConvex();
}

std::ostream &operator<<(std::ostream &os, const Pentagon &pentagon) {
    os << pentagon.pentagon;
    return os;
}
