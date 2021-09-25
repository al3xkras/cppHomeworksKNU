#include <iostream>
#include <cmath>

using namespace std;

void task4_12_v(){
    int n;
    double x;

    std::cout<<"Input n>=1: ";
    scanf("%d",&n);

    std::cout<<"Input x: ";
    scanf("%lf",&x);

    if (n<1) return;

    double output = x;

    for (int i=2; i<=n; i++){
        output+= pow(x,pow(i,2));
    }

    printf("\nOutput: %lf\n", output);
}

void task4_18_b(){
    int k;
    double x;

    std::cout<<"Input k>=0: ";
    scanf("%d",&k);

    std::cout<<"Input x: ";
    scanf("%lf",&x);

    if (k<0) return;

    double output = 1;

    for (int i=1;i<=k;i++){
        output *= x*x/(2*i*(2*i-1));
    }

    printf("\nOutput: %lf\n", output);
}

void task4_27_d(){
    double eps;

    std::cout<<"Input eps>0: ";
    scanf("%lf",&eps);

    if (eps<=0) return;

    double pi = 1.0;

    double d_pi = pi+eps+1.0;

    int k=2;

    while (d_pi>eps){
        d_pi = 1.0/pow(k,4);
        pi += d_pi;
        k++;
    }

    pi = sqrt(sqrt(pi*90.0));

    printf("\nPi ~= %lf, eps=%lf\n", pi,eps);
}

int main(){
    //11 Красовський Олександр 4.12в, 4.18б, 4.27д
    task4_12_v();
    task4_18_b();
    task4_27_d();

    return 0;
}