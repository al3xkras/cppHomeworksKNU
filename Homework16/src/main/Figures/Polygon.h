//
// Created by Alex on 14.11.2021.
//

#ifndef HOMEWORK16_POLYGON_H
#define HOMEWORK16_POLYGON_H


#include <ostream>
#include "../FigureComponents/Figure.h"
#include "../FigureComponents/Point.h"

class Polygon : public Figure{
private:
    size_t points_size;
    Point* points;
public:
    Polygon(Point* points, size_t points_size);

    virtual bool isConvex();

    friend std::ostream &operator<<(std::ostream &os, const Polygon &polygon);

    virtual ~Polygon();
};


#endif //HOMEWORK16_POLYGON_H
