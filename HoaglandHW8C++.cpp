#include<iostream>
#include<vector>
using namespace std;

class Matrix {
public:
    int rows;
    int columns;
    vector<vector<int>> matrix;

    // constructors
    Matrix() {} // empty

    // only necessary for initial declaration of D
    Matrix(int row, int column) : rows(row), columns(column) {
        matrix.resize(rows,vector<int>(columns,0)); // sets size for matrix, and fill it with 0's
        }

    // main constructor we will use
    Matrix(const vector<vector<int>>& values) {
        rows = values.size();
        columns = values[0].size();
        matrix = values;
    }

    // Transposes the matrix (rotates it 90 degrees right, aka just switching the coordinate values)
    Matrix Transpose() {
        Matrix result(columns,rows);
        // for each row
        for(int i = 0; i < rows; i++) {
            // for each column
            for(int j = 0; j < columns; j++) {
                result.matrix[j][i] = matrix[i][j];
            }
        }
        return result;
    }

    // prints the matrix
    void print() const {
        // for each row
        for(int i = 0; i < rows; i++) {
            // for each column
            for(int j = 0; j < columns; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    // multiplies the matrix by a scalar
    void scale(int num) {
        // for each row
        for(int i = 0; i < rows; i++) {
            // for each column
            for(int j = 0; j < columns; j++) {
                matrix[i][j] *= num;
            }
        }
    }

    // matrix multiplication, only works if other matrix has equal rows to this matrix columns
    // matrix multiplication is multiplying the first element of each row by the first element of each column, repeat for all elements in row/column, repeat for each element in the new matrix
    Matrix operator*(const Matrix& other) const {
        if(columns == other.rows) {
            Matrix result(rows,other.columns);
            // for each row
            for(int i = 0; i < rows; i++) {
                // for each column
                for(int j = 0; j < other.columns; j++) {
                    // we now need to add the resulting multiplication of A[I][N] * B[N][J] for each N
                    for(int k = 0; k < columns; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j]; 
                    } 
                }
            }
            return result;
        }
        return matrix; // just return the old matrix if it doesn't work
    }

    // matrix addition, only works if other matrix has equal rows to this matrix columns
    Matrix operator+(const Matrix& other) const {
        if(columns == other.columns && rows == other.rows) {
            Matrix result(rows,columns);
            // for each row
            for(int i = 0; i < rows; i++) {
                // for each column
                for(int j = 0; j < columns; j++) {
                    result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
                }
            }
            return result;
        }
        return matrix; // just return the old matrix if it doesn't work
    }
};

int main() {
    // define variables
    Matrix A({{6,4},{8,3}});
    Matrix B({{1,2,3},{4,5,6}});
    Matrix C({{2,4,6},{1,3,5}});

    B.scale(3);
    C = C.Transpose();
    B = B * C;
    
    Matrix D = A + B;

    D.print();
    return 0;
}
