//
// Created by Alex on 14.11.2021.
//

#include "Polygon.h"

Polygon::Polygon(Point *points, size_t points_size) {
    this->points = points;
    this->points_size=points_size;
}

bool Polygon::isConvex() {
    return false;
}
