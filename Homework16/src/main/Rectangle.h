//
// Created by Alex on 14.11.2021.
//

#ifndef HOMEWORK16_RECTANGLE_H
#define HOMEWORK16_RECTANGLE_H

#include "Point.h"
#include "Figure.h"
#include "iostream"

struct RectangleEdgesLength{
private:
    double shortEdge;
    double longEdge;
public:
    RectangleEdgesLength(const double shortEdge, const double longEdge){
        this->shortEdge=shortEdge;
        this->longEdge=longEdge;
    };

    double getShortEdge() const {
        return shortEdge;
    }

    double getLongEdge() const {
        return longEdge;
    }

    friend std::ostream &operator<<(std::ostream &os, const RectangleEdgesLength &length) {
        os << "shortEdge: " << length.shortEdge << " longEdge: " << length.longEdge;
        return os;
    }
};

class Rectangle: public Figure {
private:
    double x1,y1,
           x2,y2;

public:
    Rectangle(Point leftBottom, Point rightTop);

    RectangleEdgesLength getEdgesLength() const;
    double area() const;
    double perimeter() const;
    virtual ~Rectangle();
};


#endif //HOMEWORK16_RECTANGLE_H