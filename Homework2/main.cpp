#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;


double findMedianLengthA(int a, int b, int c){
    return sqrt(2*pow(b,2)+2*pow(c,2)-pow(a,2))/2;
}

void task2_08_a(){
    unsigned int a,b,c;

    cout<<"������ ������� ���������� ����� ����� (\%d \%d \%d): ";
    scanf("%d %d %d",&a,&b,&c);

    if (a+b<=c | a+c<=b | c+b<=a){
        cout<<"������ ���������� �� ����."<<endl;
        return;
    }

    printf("������� ������ �� ������� a: %.2f\n",findMedianLengthA(a,b,c));
    printf("������� ������ �� ������� b: %.2f\n",findMedianLengthA(b,a,c));
    printf("������� ������ �� ������� c: %.2f\n",findMedianLengthA(c,b,a));

}

double invsqrt(double x, double alpha){
    return (x/sqrt(1.0+alpha*pow(x,2)));
}

double invsqrt_deriv(double x, double alpha){
    return 1.0/sqrt(pow(1+alpha*pow(x,2),3));
}

void task2_17_j(){
    double x,alpha;

    cout<<"������ x, alpha ����� ����� (\%lf, \%lf): ";
    scanf("%lf %lf",&x,&alpha);

    printf("invsqrt(x,aplha) = %lf\n",invsqrt(x,alpha));
    printf("invsqrt_deriv(x,aplha) = %lf\n",invsqrt_deriv(x,alpha));
    
}

void printDoubleNewLine(){
    cout<<endl<<endl;
}

int main(){
    //11 ����������� ��������� 2.08�, 2.17�

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    task2_08_a();
    printDoubleNewLine();

    task2_17_j();
    printDoubleNewLine();

    return 0;
}