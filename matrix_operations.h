#ifndef MATRIXCALCULATOR_C_MATRIX_OPERATIONS_H
#define MATRIXCALCULATOR_C_MATRIX_OPERATIONS_H

typedef struct {
    int rows;
    int cols;
    double** data;
} Matrix;

Matrix allocateMatrix(int rows, int cols);
void freeMatrix(Matrix* mat);
void inputMatrix(Matrix* mat);
void displayMatrix(Matrix mat);
Matrix multiplyMatrices(Matrix mat1, Matrix mat2);
double determinant(Matrix mat);
Matrix readMatrixFromFile(const char* filename);
void writeMatrixToFile(const char* filename, Matrix mat);

#endif //MATRIXCALCULATOR_C_MATRIX_OPERATIONS_H
