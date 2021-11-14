//
// Created by Alex on 14.11.2021.
//

#ifndef HOMEWORK16_RECTANGLE_H
#define HOMEWORK16_RECTANGLE_H

#include "Figure.h"
#include "iostream"

struct EdgesLength{
private:
    double shortEdge;
    double longEdge;
public:
    EdgesLength(const double shortEdge, const double longEdge){
        this->shortEdge=shortEdge;
        this->longEdge=longEdge;
    };

    double getShortEdge() const {
        return shortEdge;
    }

    double getLongEdge() const {
        return longEdge;
    }

    friend std::ostream &operator<<(std::ostream &os, const EdgesLength &length) {
        os << "shortEdge: " << length.shortEdge << " longEdge: " << length.longEdge;
        return os;
    }
};

class Rectangle: public Figure {
private:
    double x1,y1,
           x2,y2;

public:
    Rectangle(double x1, double y1, double x2, double y2);

    EdgesLength getEdgesLength() const;

    double area() const;

    double perimeter() const;
};


#endif //HOMEWORK16_RECTANGLE_H
