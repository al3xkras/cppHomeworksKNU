//
// Created by Alex on 14.11.2021.
//

#include "Figure.h"

bool Figure::isConvex() {
    return false;
}

double Figure::perimeter() {
    return 0;
}

std::ostream &operator<<(std::ostream &os, const Figure &figure) {
    return os;
}
