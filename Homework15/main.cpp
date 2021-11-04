#include <iostream>
#include "src/Point2D.h"
#include "src/Line2D.h"
#include "src/Triangle.h"



int main() {
    Point2D a(0,0),
            b(1,2),
            c(0,-0.1),
            d(1,0);
    //std::cout<<"";
    //a.input();
    //b.input();
    //c.input();
    //d.input();

    Line2D line1(a,b);
    Line2D line2(c,d);

    std::cout<<line1.intersection(line2);

    return 0;
}
