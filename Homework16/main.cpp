#include <iostream>

#include "src/main/Point.h"
#include "src/main/Figure.h"
#include "src/main/Rectangle.h"
#include "src/main/Triangle.h"

void task16_08(){
    Rectangle rectangle(Point(0, -1),
            Point(2, 1));

    Triangle triangle(Point(0,0),Point(0,2),Point(1,1));


    /*
    std::cout<<rectangle.perimeter()<<std::endl
        <<rectangle.area()<<std::endl
        <<rectangle.getEdgesLength()<< std::endl;
        */

    std::cout<<triangle.perimeter()<<std::endl
             <<triangle.area()<<std::endl
             <<triangle.getEdgesLength()<< std::endl << triangle;
}

int main() {
    //11 Красовський Олександр 16.08
    task16_08();
    return 0;
}
