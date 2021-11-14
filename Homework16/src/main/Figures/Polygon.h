//
// Created by Alex on 14.11.2021.
//

#ifndef HOMEWORK16_POLYGON_H
#define HOMEWORK16_POLYGON_H


#include "../FigureComponents/Figure.h"
#include "../FigureComponents/Point.h"

class Polygon : public Figure{
private:
    size_t points_size;
    Point* points;
public:
    Polygon(Point* points, size_t points_size);
    bool isConvex();

    virtual ~Polygon();
};


#endif //HOMEWORK16_POLYGON_H
