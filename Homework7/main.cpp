#include <iostream>
#include <cmath>

using namespace std;


bool isPrime(int number){
    if (number<=1) return false;

    int div_max = (int)sqrt(number)+1;

    for (int i=2; i<div_max; i++){
        if (number%i == 0) return false;
    }

    return true;
}

void task7_8_e(){
    int N;

    cout<<"\n  Task 7.8 (e)\nInput N>=0: ";

    scanf("%d",&N);

    if (N<0) return;

    int numbers[N];
    int prime_numbers[N];
    int prime_count = 0;

    for (int i=0; i<N; i++){
        int num_i;
        
        printf("Input element num_%d>0 of array: ",i+1);

        scanf("%d",&num_i);

        if (num_i<=0){
            i--;
            cout<<"Element is less that/ equal to zero."<<endl;
        }

        numbers[i]=num_i;

        if (isPrime(num_i)){
            prime_numbers[prime_count++] = num_i;
        }
    }

    cout<<endl<<"Prime numbers: [ ";
    for (int i=0; i<prime_count; i++){
        cout<<prime_numbers[i]<<", ";
    }
    cout<<"] "<<endl;

    printf("Prime number count: %d\n",prime_count);

    delete(&numbers);
    delete(&prime_numbers);
}


double arrayMax(double arr[], size_t size){
    if (size<=0) return -4e307;

    double arrMax = arr[0];
    for (int i=1; i<size; i++){
        arrMax = (arrMax>arr[i]) ? arrMax : arr[i];
    }
    return arrMax;
}

void task7_9_v(){
    
    int N;

    cout<<"\n  Task 7.9 (v)\nInput N>=0: ";

    scanf("%d",&N);

    if (N<0) return;

    double numbers[N];
    int num_count = 0;

    for (int i=0; i<N; i++){
        double num_i;
        
        printf("Input element %d: ",i+1);

        scanf("%lf",&num_i);
        
        if (! ((i+1)&1) ){
            numbers[num_count++]=num_i;
        }
        
    }

    printf("Max value: %lf\n",arrayMax(numbers,num_count));

    delete(&numbers);
}

int main(){
    //11 Красовський Олександр 7.08е, 7.09в
    task7_8_e();
    task7_9_v();
    
    return 0;
}