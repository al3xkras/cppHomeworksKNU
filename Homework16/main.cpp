#include <iostream>

#include "src/main/FigureComponents/Point.h"
#include "src/main/FigureComponents/Figure.h"
#include "src/main/Figures/Rectangle.h"
#include "src/main/Figures/Triangle.h"
#include "src/main/FigureComponents/Line.h"
#include "src/main/Figures/Polygon.h"

void task16_08(){
    Rectangle rectangle(Point(0, -1),
            Point(2, 1));

    Triangle triangle(Point(0,0),Point(0,2),Point(1,1));


    /*
    std::cout<<rectangle.perimeter()<<std::endl
        <<rectangle.area()<<std::endl
        <<rectangle.getEdgesLength()<< std::endl;
        */

    /*
    std::cout<<triangle.perimeter()<<std::endl
             <<triangle.area()<<std::endl
             <<triangle.getEdgesLength()<< std::endl << triangle;
             */
    //Line line(Point(0,0),Point(0,1));
    //std::cout<<line.angleWithPoint(Point(1,0))<<std::endl;

    Point points[5] = {
            Point(0,0),
            Point(1,0),
            Point(2,1),
            Point(2,2),
            Point(1,3)
    };

    Polygon polygon(points,5);

    std::cout<<std::boolalpha<<polygon.isConvex()<<std::endl;

}

int main() {
    //11 Красовський Олександр 16.08
    task16_08();
    return 0;
}
