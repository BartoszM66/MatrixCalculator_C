#include "matrix_operations.h"

#include <stdlib.h>

//Funckja alokacji pamieci
Matrix allocateMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;

    mat.data = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; ++i) {
        mat.data[i] = (double*)malloc(cols * sizeof(double));
    }

    return mat;
}

//Funkcja zwalniania pamieci
void freeMatrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; ++i) {
        free(mat->data[i]);
    }
    free(mat->data);
}

