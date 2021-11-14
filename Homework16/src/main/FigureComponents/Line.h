//
// Created by Alex on 14.11.2021.
//

#ifndef HOMEWORK16_LINE_H
#define HOMEWORK16_LINE_H


#include <ostream>
#include "Point.h"

class Line {
private:
    Point a;
    Point b;
public:
    Line(const Point &a, const Point &b);
    double angleWithPoint(Point point);

    friend std::ostream &operator<<(std::ostream &os, const Line &line);
};


#endif //HOMEWORK16_LINE_H
