#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;


double findMedianLengthA(int a, int b, int c){
    return sqrt(2*pow(b,2)+2*pow(c,2)-pow(a,2))/2;
}

void task2_08_a(){
    unsigned int a,b,c;

    cout<<"Введіть сторони трикутника через пробіл (\%d \%d \%d): ";
    scanf("%d %d %d",&a,&b,&c);

    if (a+b<=c | a+c<=b | c+b<=a){
        cout<<"Такого трикутника не існує."<<endl;
        return;
    }

    printf("Довжина медіани до сторони a: %.2f\n",findMedianLengthA(a,b,c));
    printf("Довжина медіани до сторони b: %.2f\n",findMedianLengthA(b,a,c));
    printf("Довжина медіани до сторони c: %.2f\n",findMedianLengthA(c,b,a));

}

double invsqrt(double x, double alpha){
    return (x/sqrt(1.0+alpha*pow(x,2)));
}

double invsqrt_deriv(double x, double alpha){
    return 1.0/sqrt(pow(1+alpha*pow(x,2),3));
}

void task2_17_j(){
    double x,alpha;

    cout<<"Введіть x, alpha через пробіл (\%lf, \%lf): ";
    scanf("%lf %lf",&x,&alpha);

    printf("invsqrt(x,aplha) = %lf\n",invsqrt(x,alpha));
    printf("invsqrt_deriv(x,aplha) = %lf\n",invsqrt_deriv(x,alpha));
    
}

void printDoubleNewLine(){
    cout<<endl<<endl;
}

int main(){
    //11 Красовський Олександр 2.08а, 2.17ж

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    task2_08_a();
    printDoubleNewLine();

    task2_17_j();
    printDoubleNewLine();

    return 0;
}