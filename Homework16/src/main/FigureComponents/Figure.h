//
// Created by Alex on 14.11.2021.
//

#ifndef HOMEWORK16_FIGURE_H
#define HOMEWORK16_FIGURE_H


#include <ostream>

class Figure {
public:
    virtual bool isConvex();
    virtual double perimeter();

    friend std::ostream &operator<<(std::ostream &os, const Figure &figure);
};


#endif //HOMEWORK16_FIGURE_H
