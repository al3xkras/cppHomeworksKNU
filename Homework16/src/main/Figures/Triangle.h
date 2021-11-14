//
// Created by Alex on 14.11.2021.
//

#ifndef HOMEWORK16_TRIANGLE_H
#define HOMEWORK16_TRIANGLE_H

#include <ostream>
#include "../FigureComponents/Point.h"
#include "../FigureComponents/Figure.h"

struct TriangleEdgesLength{
private:
    double AB;
    double BC;
    double AC;
public:
    TriangleEdgesLength(double ab, double bc, double ac);

    double getAb() const;
    double getBc() const;
    double getAc() const;

    friend std::ostream &operator<<(std::ostream &os, const TriangleEdgesLength &length);
};

class Triangle : public  Figure{
private:
    Point* points;
public:
    Triangle(const Point &a, const Point &b, const Point &c);
    virtual ~Triangle();

    TriangleEdgesLength getEdgesLength();
    double area();
    double perimeter();

    friend std::ostream &operator<<(std::ostream &os, const Triangle &triangle);
};


#endif //HOMEWORK16_TRIANGLE_H
