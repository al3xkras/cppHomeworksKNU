#include <iostream>
#include <cmath>

using namespace std;

void task5_10_d(){
    double a_k_m3=1, a_k_m2=1, a_k_m1=1;

    int n;
    std::cout<<"Input n>=1: ";
    scanf("%d",&n);

    if (n<1) return;

    int d=2;
    double _sum = 0;
    double a_k;

    for (int k=1; k<min(n+1,4); k++){
        _sum += a_k_m1/d;
        d *= 2;
    }

    for (int k=4; k<=n; k++){
        a_k = a_k_m1+a_k_m3;

        a_k_m3=a_k_m2;
        a_k_m2 = a_k_m1;
        a_k_m1 = a_k;
        _sum += a_k/d;
        d *= 2;
    }

    printf("S_n = %lf\n",_sum);
}
/*
double task5_11_a_a_k(int k){
    if (k<3){
        return 3-k;
    }
    return task5_11_a_a_k(k-1)/(k+1) + task5_11_a_a_k(k-2) + task5_11_a_b_k(k);
}

double task5_11_a_b_k(int k){
    if (k<3){
        return k%2;
    }
    return 2.0*task5_11_a_b_k(k-1)+task5_11_a_a_k(k-1);
}

void task5_11_a(){
    int n;
    std::cout<<"Input n>=1: ";
    scanf("%d",&n);
    
    if (n<1) return;

    double _sum = 0.0;

    for (int k=1; k<=n; k++){
        _sum+=pow(3,2*k+1)/(task5_11_a_a_k(k)*task5_11_a_b_k(k)+1);
    }

    printf("\nS_n = %lf\n",_sum);
}
*/

void task5_15_g(){
    double eps;

    std::cout<<"Input eps>0: ";
    scanf("%lf",&eps);

    double x;
    std::cout<<"Input x: ";
    scanf("%lf",&x);

    if(eps<=0.0) return;

    double _sin = x;
    double x_k = x;
    int k = 2;

    while(abs(x_k)>eps){
        
        x_k = -x_k*x*x/((2*k-2)*(2*k-1));
        k++;
        _sin+=x_k;
    }

    printf("sin(x) = %lf, eps=%lf",_sin,eps);
}



int main(){
    //11 Красовський Олександр 5.10д, 5.11а, 5.15г
    task5_10_d();
    //Помилка в умові
    //task5_11_a();
    task5_15_g();
    return 0;
}