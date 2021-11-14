//
// Created by Alex on 14.11.2021.
//

#ifndef HOMEWORK16_POINT_H
#define HOMEWORK16_POINT_H


class Point {
private:
    double x;
    double y;
public:
    Point(double x, double y);
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
};


#endif //HOMEWORK16_POINT_H
