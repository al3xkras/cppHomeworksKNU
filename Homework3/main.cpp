#include <iostream>
#include <cmath>

using namespace std;

#define DBL_MAX 1.79e308


void getRectIntersection(double downLeftX1,double downLeftY1,double edgeLength1,
                        double downLeftX2,double downLeftY2,double edgeLength2){

    if (edgeLength1<=0.0 | edgeLength2<=0.0){
        std::cout<<"Rectangle(s) do not exist.\n";
        return;
    }

    double dx = abs(downLeftX2-downLeftX1);
    double dy = abs(downLeftY2-downLeftY1);

    if ((dx>edgeLength1 & dx>edgeLength2) | (dy>edgeLength1 & dy>edgeLength2)){
        printf("Rectangles do not intersect.\n");
        return;
    }
    
    printf("Rectangles intersect.\n");

    double intersectionBottomX = max(downLeftX1,downLeftX2);
    double intersectionBottomY = max(downLeftY1,downLeftY2);
    double intersectionTopX = min(downLeftX1+edgeLength1,downLeftX2+edgeLength2);
    double intersectionTopY = min(downLeftY1+edgeLength1,downLeftY2+edgeLength2);

    printf("Intersection: Left Bottom: (%lf,%lf), Right top: (%lf,%lf)\n",
            intersectionBottomX,intersectionBottomY,
            intersectionTopX,intersectionTopY);
    
}

double leakyReLu(double x, double a){
    double output = (x<0) ? a*x : 0.0;
    return max(-DBL_MAX,min(DBL_MAX,output));
}

double derivLeakyReLu(double x, double a){
    double output = (x<0) ? a : 0.0;
    return max(-DBL_MAX,min(DBL_MAX,output));
}

void task3_23_v(){
    double x,a;

    std::cout<<"Input x \"\%lf\": ";
    scanf("%lf",&x);

    std::cout<<"Input a: \"\%lf\": ";
    scanf("%lf",&a);

    std::cout<<"Output:"<<endl<<endl;
    printf("leakyReLu(x,a) = %.3e\n",leakyReLu(x,a));
    printf("derivLeakyReLu(x,a) = %.3e\n",derivLeakyReLu(x,a));

}

void task3_17(){
    double x1,y1,x2,y2;
    double edgeLength1,edgeLength2;

    std::cout<<"Input Left Bottom point of Rectangle 1 \"\%lf \%lf\": ";
    scanf("%lf %lf",&x1,&y1);
    std::cout<<"Input edge length of Rectangle 1 \"\%lf\": ";
    scanf("%lf",&edgeLength1);

    std::cout<<"Input Left Bottom point of Rectangle 2 \"\%lf \%lf\": ";
    scanf("%lf %lf",&x2,&y2);
    std::cout<<"Input edge length of Rectangle 2 \"\%lf\": ";
    scanf("%lf",&edgeLength2);

    std::cout<<"Output:"<<endl<<endl;

    getRectIntersection(x1,y1,edgeLength1,
                        x2,y2,edgeLength2);
}


int main(){
    //11 Красовський Олександр 3.17, 3.23в
    
    task3_17();

    task3_23_v();

    return 0;
}