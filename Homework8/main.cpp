#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const size_t matrix_max_size = 5;

void input_matrix(double matrix[matrix_max_size][matrix_max_size], size_t n){
    if (n>matrix_max_size) return;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            double m_ij;
            printf("Input m_%d_%d element of matrix M: ",i+1,j+1);
            scanf("%lf",&m_ij);
            matrix[i][j]=m_ij;
        }
    }
}

void print_mat(double matrix[matrix_max_size][matrix_max_size], size_t n){
    printf("Matrix (%d,%d):\n",n,n);
    for (int i=0; i<n; i++){
        printf("[ ");
        for (int j=0; j<n; j++){
            printf("%lf, ",matrix[i][j]);
        }
        printf(" ]\n");
    }
}


void submatrix(double matrix[matrix_max_size][matrix_max_size], 
                double sub_matrix[matrix_max_size][matrix_max_size],
                int drop_row, int drop_col, size_t n){
    
    int current_i=0, current_j=0;

    for (int i=0; i<n; i++){
        if (i==drop_row) continue;
        for (int j=0; j<n; j++){
            if (j==drop_col) continue;

            sub_matrix[current_i][current_j] = matrix[i][j];
            current_j++;
        }
        current_i++;
        current_j=0;
    }

}


double determinant(double matrix[matrix_max_size][matrix_max_size], size_t n){
    if (n==1){
        return matrix[0][0];
    } else if (n==2){
        return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
    } else {
        double det = 0;

        for (int i=0; i<n; i++){
            double sub_matrix[matrix_max_size][matrix_max_size];
            submatrix(matrix,sub_matrix,0,i,n);
            det += pow(-1,i)*matrix[0][i]*determinant(sub_matrix,n-1);
        }
        
        return det;
    }

}



bool invert(double matrix[matrix_max_size][matrix_max_size],
            double inverted[matrix_max_size][matrix_max_size],
            size_t n){
    //
    if (n>matrix_max_size) return false;

    double matrix_det = determinant(matrix,n);

    if ((long)(matrix_det*1000.0)==0L){
        std::cout<<"Inverse matrix does not exist."<<endl;
        return false;
    }

    double oneByMatrixDet = 1/matrix_det;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            double submatrix_i_j[matrix_max_size][matrix_max_size];
            submatrix(matrix,submatrix_i_j,
                i,j,n);

            inverted[j][i] = oneByMatrixDet*pow(-1,i+j)*determinant(submatrix_i_j,n-1);
        }
    }

    return true;
}


void task8_8(){
    size_t n;

    double matrix[matrix_max_size][matrix_max_size];
    double inverted[matrix_max_size][matrix_max_size];
    
    printf("Input n<=%d: ",matrix_max_size);
    scanf("%d",&n);

    if (n>matrix_max_size) return;

    input_matrix(matrix,n);

    std::cout<<endl<<"Matrix:"<<endl;

    print_mat(matrix,n);

    std::cout<<endl<<"Inverse matrix:"<<endl;
    if (!invert(matrix,inverted,n)) return;

    print_mat(inverted,n);

    std::cout<<endl;

    delete(&matrix);
    delete(&inverted);
}


int main(){
    //11 Красовський Олександр 8.08

    task8_8();

    return 0;
}