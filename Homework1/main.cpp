#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

void fancyPrint(string name,int args_size, int args[]){
    std::cout<<name<<"|";
    string s = "-|";

    for (int i=0; i<args_size; i=i+1){
        int arg = args[i];
        printf("%d|",arg);
        s = s+"--|";
    }
    printf("\n");
    std::cout<<s<<"\n";
}

void fancyPrint(string name,int args_size,float args[]){
    std::cout<<name<<"|";
    string s = "-|";

    for (int i=0; i<args_size; i=i+1){
        float arg = args[i];
        printf("%.2f|",arg);
        s = s+"--|";
    }
    printf("\n");
    std::cout<<s<<"\n";
}

void fancyPrint(string name,int args_size,double args[]){
    std::cout<<name<<"|";
    string s = "-|";

    for (int i=0; i<args_size; i=i+1){
        double arg = args[i];
        printf("%.2lf|",arg);
        s = s+"--|";
    }
    printf("\n");
    std::cout<<s<<"\n";
}

void task10(){
    std::cout<<"Task 10"<<endl;
    int x1 = 10;
    int x2 = -1;
    int x3 = 0;
    int x4 = 50;
    int x5 = -25;

    int X[] = {x1,x2,x3,x4,x5};

    float y1 = 1.0f;
    float y2 = -11.5f;
    float y3 = 100.003f;
    float y4 = -5.f;
    float y5 = 30.f;

    float Y[] = {y1,y2,y3,y4,y5};

    fancyPrint("x",5,X);
    fancyPrint("y",5,Y);

}




void task12(){
    std::cout<<endl<<endl<<"Task 12"<<endl;
    double d1 = 1.0/(1.0 + 1.0/3.0);
    double d2 = 1.0/(7.0+d1);
    double d3 = 1.0/(4.0+d2);

    double T = 365.0 + d3;

    printf("T = %lf\n",T);
}

void task16a(){
    std::cout<<endl<<endl<<"Task 16(a)"<<endl;
    int x[] = {1,2,3,4,5};
    int x_size = 5;
    double F[x_size];


    for (int i=0; i<x_size; i=i+1){
        F[i] = exp(-pow(x[i],2));
    }
    fancyPrint("x",5,x);
    fancyPrint("F(x)",5,F);
}

void task16b(){
    std::cout<<endl<<endl<<"Task 16(b)"<<endl;
    int x[] = {1,2,3,4,5};
    int x_size = 5;
    double F[x_size];


    for (int i=0; i<x_size; i=i+1){
        F[i] = sqrt(x[i]);
    }
    fancyPrint("x",5,x);
    fancyPrint("F(x)",5,F);
}

void task17(){
    std::cout<<endl<<endl<<"Task 17"<<endl;
    long _min = 0;
    long _max = 10000;

    long number;
    std::cout<<"Input number in range ["<<_min<<","<<_max<<"]"
        <<endl;
    scanf("%d",&number);

    if (number>_max | number<_min){
        std::cout<<"Number is not in range ["<<_min<<","<<_max<<"]"
        <<endl;
        return;
    }

    double result = number*number; //**2
    result = result*result; //**4
    result = result*result; //**8

    printf("Result = %20.4f\n",result);
}

int main()
{
    task10();
    task12();
    task16a();
    task16b();
    task17();
    return 0;
}
