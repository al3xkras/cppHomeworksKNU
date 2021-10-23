#include <iostream>
#include <fstream>

using namespace std;



const size_t array_max_size = 15;




void task11_07_a(){
    size_t n;
    printf("Input n<%d: ",array_max_size);
    scanf("%d",&n);

    if (n<0) return;

    double numbers[n];

    for (int i=0; i<n; i++){
        printf("Input element %d of array: ",i+1);
        double e_i;
        scanf("%lf",&e_i);
        numbers[i]=e_i;
    }

    FILE *f1 = fopen("integer_array.bin","wb+");

    cout<<"Writing data to file..."<<endl;
    fwrite(&numbers, sizeof(double)*n, 1, f1);

    fclose(f1);

    FILE *f2 = fopen("integer_array.bin","rb");

    double numbers_read[n];
    double array_sum = 0;
    
    cout<<"Reading data from file..."<<endl;
    fread(&numbers_read, sizeof(double)*n, 1, f2);

    fclose(f2);

    cout<<"Read data: "<<endl;
    for (int i=0; i<n; i++){
        array_sum+=numbers_read[i];
        printf("%.3f\n",numbers_read[i]);
    }

    cout<<endl<<"Sum of array items: "<<array_sum<<endl;
}


struct Toy{
    char toyName[25];
    double toyPrice;
    int minAge;
    int maxAge;
};

void task11_12_b(){

    size_t toys_size = 4;
    Toy toys[] = {
        {"Tennis racket", 1250.75, 7, 99},
        {"Baseball bat", 550.55, 12, 99},
        {"Puppet", 1500.0, 5, 9},
        {"Constructor", 2020.220, 5, 15}
    };

    //Save toys

    FILE* f1 = fopen("toys.dat", "wb+");

    cout<<"Writing data to file..."<<endl;
    fwrite(&toys, sizeof(Toy)*toys_size, 1, f1);

    fclose(f1);



    FILE* f2 = fopen("toys.dat", "r");

    cout<<"Reading data from file..."<<endl;
    Toy toys_read[toys_size];

    fread(&toys_read, sizeof(Toy)*toys_size, 1, f2);

    fclose(f2);

    cout<<endl<<"Task 11.12(b):";

    int n,m;
    cout<<"Input n (for age n or m): ";
    scanf("%d",&n);
    cout<<"Input m: ";
    scanf("%d",&m);

    if (n<0 | m<0) return;

    printf("\nToys, that match for both age %d and %d:\n",n,m);
    for (int i=0; i<toys_size; i++){
        Toy toy = toys_read[i];
        if (n<toy.minAge || m<toy.minAge ||
            n>toy.maxAge || m>toy.maxAge){
            continue;
        }
        cout<<"    "<<toy.toyName<<endl;
    }
}

int main(){
    //Вказівка. Усі файли мають бути бінарні.
    //11 Красовський Олександр 11.07а, 11.12б

    task11_07_a();
    task11_12_b();
    return 0;
}