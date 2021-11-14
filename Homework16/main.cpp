#include <iostream>

#include "src/main/FigureComponents/Point.h"
#include "src/main/FigureComponents/Figure.h"
#include "src/main/Figures/Rectangle.h"
#include "src/main/Figures/Triangle.h"
#include "src/main/FigureComponents/Line.h"
#include "src/main/Figures/Polygon.h"
#include "src/main/Figures/Pentagon.h"

void task16_08(){

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

    Point points2[7] = {
            Point(0,0),
            Point(1,0),
            Point(2,1),
            Point(2,2),
            Point(1,3),
            Point(0,3),
            Point(0.5,1.5)
    };

    Rectangle rectangle(Point(0, -1),
                        Point(2, 1));

    Triangle triangle(Point(0,0),Point(0,2),Point(1,1));

    Pentagon pentagon(points, 5);
    Polygon polygon(points2,7);

    std::cout << std::boolalpha << pentagon.isConvex() << std::endl;
    std::cout << pentagon << std::endl;

}

int main() {
    //11 Красовський Олександр 16.08
    task16_08();
    return 0;
}
