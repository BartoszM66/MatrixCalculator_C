#include "matrix_operations.h"

#include <stdio.h>
#include <stdlib.h>

//Fukcja mnozenia macierzy
Matrix multiplyMatrices(Matrix mat1, Matrix mat2) {
    if (mat1.cols != mat2.rows) {
        printf("Error: Incompatible matrix dimensions for multiplication.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = allocateMatrix(mat1.rows, mat2.cols);

    for (int i = 0; i < mat1.rows; ++i) {
        for (int j = 0; j < mat2.cols; ++j) {
            result.data[i][j] = 0;

            for (int k = 0; k < mat1.cols; ++k) {
                result.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }

    return result;
}

//Funkcja obliczania wyznacznika
double determinant(Matrix mat) {
    if (mat.rows != mat.cols) {
        printf("Error: Determinant can only be calculated for a square matrix.\n");
        exit(EXIT_FAILURE);
    }

    if (mat.rows == 1) {
        return mat.data[0][0];
    }

    double det = 0;
    int sign = 1;

    for (int i = 0; i < mat.rows; ++i) {
        Matrix submatrix = allocateMatrix(mat.rows - 1, mat.cols - 1);

        for (int j = 1; j < mat.rows; ++j) {
            for (int k = 0, l = 0; k < mat.cols; ++k) {
                if (k != i) {
                    submatrix.data[j - 1][l++] = mat.data[j][k];
                }
            }
        }

        det += sign * mat.data[0][i] * determinant(submatrix);
        sign = -sign;

        freeMatrix(&submatrix);
    }

    return det;
}



