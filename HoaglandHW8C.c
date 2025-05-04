#include <stdio.h>

// multiplies the matrix by a scalar
void scale(int rows, int columns, double Bmatrix[rows][columns], double num) {
    // for each row
    for(int i = 0; i < rows; i++) {
        // for each column
        for(int j = 0; j < columns; j++) {
            Bmatrix[i][j] *= num;
        }
    }

}

//matrix multiplication
void mult(int Brows, int Bcolumns, int Crows, int Ccolumns, double Bmatrix[Brows][Bcolumns], double Cmatrix[Crows][Ccolumns], double newMatrix[Brows][Ccolumns]) {
    if(Bcolumns == Crows) {
        // for each row
        for(int i = 0; i < Brows; i++) {
            // for each column
            for(int j = 0; j < Ccolumns; j++) {
                // we now need to add the resulting multiplication of A[I][N] * B[N][J] for each N
                for(int k = 0; k < Crows; k++) {
                newMatrix[i][j] += (Bmatrix[i][k] * Cmatrix[k][j]); 
                } 
            }
        }
    }

}

// matrix addition, only works if other matrix has equal rows to this matrix columns
void add(int Arows, int Acolumns, double AMatrix[Arows][Acolumns], double Dmatrix[Arows][Acolumns]) {
    // for each row
    for(int i = 0; i < Arows; i++) {
        // for each column
        for(int j = 0; j < Acolumns; j++) {
            Dmatrix[i][j] += AMatrix[i][j];
        }
    }
}


int main() {
    // define variables
    double A[2][2] = {{6,4},{8,3}};
    double B[2][3] = {{1,2,3},{4,5,6}};
    double C[3][2] = {{2,1},{4,3},{6,5}};
    double D[2][2] = {{0,0},{0,0}};
    double num = 3;

    scale(2,3,B,num);
    mult(2,3,3,2,B,C,D);
    add(2,2,A,D);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", D[i][j]);
        }
        printf("\n");
    }
    return 0;

}
