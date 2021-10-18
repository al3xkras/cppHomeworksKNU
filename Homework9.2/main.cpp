#include <iostream>
#include <random>

using namespace std;

int randint(int min_value, int max_value){
    return min_value + ( std::rand() % ( max_value - min_value + 1 ) );
}

void task9_9_n(){
    size_t N, M;

    cout<<"Input N>0: ";
    scanf("%d",&N);

    cout<<"Input M>0: ";
    scanf("%d",&M);

    if (N<=0 | M<=0) return;

    int** matrix;

    matrix = (int**)calloc(N,sizeof(int)*M);

    for (int i=0; i<N; i++){
        matrix[i] = (int*)calloc(M, sizeof(int));
        
        for (int j=0; j<M; j++){
            matrix[i][j]=randint(0,100);
        }
    }

    int** new_matrix;

    size_t new_N = N/2;
    int current_row=0;
    new_matrix = (int**) calloc(new_N, M*sizeof(int));

    printf("\nMatrix %dx%d:\n",N,M);
    for (int i=0; i<N; i++){
        cout<<i+1<<") [ ";
        for (int j=0; j<M; j++){
            cout<<matrix[i][j]<<", ";
        }

        if (i%2!=0) {
            new_matrix[current_row++] = matrix[i];
        } else {
            delete(matrix[i]);
        }
        cout<<"]"<<endl;
    }

    printf("\nMatrix with dropped rows:\nMatrix %dx%d:\n",new_N,M);
    for (int i=0; i<new_N; i++){
        cout<<2*i+2<<") [ ";
        for (int j=0; j<M; j++){
            cout<<new_matrix[i][j]<<", ";
        }
        delete(new_matrix[i]);
        cout<<"]"<<endl;
    }

    delete(matrix);
    delete(new_matrix);
}

void task9_9_n_2(){
    size_t N, M;

    cout<<"Input N>0: ";
    scanf("%d",&N);

    cout<<"Input M>0: ";
    scanf("%d",&M);

    if (N<=0 | M<=0) return;

    int* matrix;
    int* new_matrix;

    int current_i=0;
    size_t new_N = N/2;

    matrix= (int*)calloc(N*M,sizeof(int));
    new_matrix = (int*)calloc(new_N*M,sizeof(int));

    for (int i=0; i<N*M; i++){
        matrix[i]=randint(0,100);
    }

    
    printf("\nMatrix %dx%d:\n",N,M);
    for (int i=0; i<N*M; i=i+M){
        cout<<i/M+1<<") [ ";

        if (i%2!=0) {
            for (int j=0; j<M;j++){
                cout<<matrix[i+j]<<", ";
                new_matrix[current_i++] = matrix[i+j];
            }
        } else {
            for (int j=0; j<M;j++){
                cout<<matrix[i+j]<<", ";
            }
        }

        cout<<"]"<<endl;
    }

    printf("\nMatrix with dropped rows:\nMatrix %dx%d:\n",new_N,M);
    for (int i=0; i<new_N*M; i=i+M){
        cout<<2*i/M+2<<") [ ";
        for (int j=0; j<M;j++){
            cout<<new_matrix[i+j]<<", ";
        }
        cout<<"]"<<endl;
    }

    delete(matrix);
    delete(new_matrix);
}

int main(){
    //11 Красовський Олександр 9.09н
    task9_9_n();
    task9_9_n_2();
    return 0;
}