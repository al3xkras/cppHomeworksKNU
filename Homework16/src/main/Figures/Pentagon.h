//
// Created by Alex on 14.11.2021.
//

#ifndef HOMEWORK16_PENTAGON_H
#define HOMEWORK16_PENTAGON_H


#include <ostream>
#include "Polygon.h"

class Pentagon: public Polygon{
private:
    Polygon pentagon = Polygon(nullptr, 0);
public:
    Pentagon(Point* points, size_t points_size);
    bool isConvex() override;

    friend std::ostream &operator<<(std::ostream &os, const Pentagon &pentagon);

    virtual ~Pentagon();
};


#endif //HOMEWORK16_PENTAGON_H
