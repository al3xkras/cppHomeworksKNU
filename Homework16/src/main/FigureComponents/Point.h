//
// Created by Alex on 14.11.2021.
//

#ifndef HOMEWORK16_POINT_H
#define HOMEWORK16_POINT_H


#include <ostream>

class Point {
private:
    double x;
    double y;
public:
    Point(double x, double y);

    double distanceTo(Point other);

    double getX() const;
    double getY() const;
    void setX(double X);
    void setY(double Y);

    friend std::ostream &operator<<(std::ostream &os, const Point &point);
};


#endif //HOMEWORK16_POINT_H
