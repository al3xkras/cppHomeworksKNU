//
// Created by Alex on 14.11.2021.
//

#ifndef HOMEWORK16_RECTANGLE_H
#define HOMEWORK16_RECTANGLE_H

#include "../FigureComponents/Point.h"
#include "../FigureComponents/Figure.h"
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
    double x1,y1;
    double x2,y2;

public:
    Rectangle(Point leftBottom, Point rightTop);
    virtual ~Rectangle();

    bool isConvex() override;
    double perimeter() override;

    RectangleEdgesLength getEdgesLength();
    double area();
};


#endif //HOMEWORK16_RECTANGLE_H
