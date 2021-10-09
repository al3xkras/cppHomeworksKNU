#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void task9_8(){

    int n;
    std::cout<<"How many times to input vector: ";
    scanf("%d",&n);

    if (n<=0) return;

    double* array;

    for (int i=0; i<n; i++){
        size_t vec_size;
        std::cout<<"("<<i+1<<") Vector size: ";
        scanf("%d",&vec_size);
        if (vec_size<=0) continue;

        array = (double*)calloc(vec_size,sizeof(*array));

        for (int j=0; j<vec_size; j++){
            double vec_j;
            printf("vector_%d = ",j+1);
            scanf("%lf",&vec_j);

            *(array+j)=vec_j;
        }

        printf("\n\nArray:\n[ ");
        for (int j=0; j<vec_size; j++){
            printf("%lf, ",*(array+j));
        }
        std::cout<<"]"<<endl;


        double sum = 0;
        for (int j=0; j<vec_size; j++){
            sum += *(array+j);
        }
        double mean = sum/vec_size;
        printf("\nMean: %lf\n",mean);


        printf("\nDispersion:\n[ ");
        for (int j=0; j<vec_size; j++){
            printf("%lf, ",abs(mean-*(array+j)));
        }
        std::cout<<"]"<<endl<<endl;

        free(array);
    }

}

int main(){
    //Task: 9.08
    task9_8();

    return 0;
}