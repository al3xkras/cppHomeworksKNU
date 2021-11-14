#include <iostream>

#include "src/main/Figure.h"
#include "src/main/Rectangle.h"

void task16_08(){
    Rectangle rectangle(0, -1, 2, 1);

    std::cout<<rectangle.perimeter()<<std::endl
        <<rectangle.area()<<std::endl
        <<rectangle.getEdgesLength()<< std::endl;
}

int main() {
    //11 Красовський Олександр 16.08
    task16_08();
    return 0;
}
