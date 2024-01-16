#include "matrix_operations.h"
#include <stdio.h>
int main() {
    int rows1, cols1, rows2, cols2;

    printf("Do you want to enter the first matrix manually or load it from a file? (1 - Manual, 2 - Load from file): ");
    int choice;
    scanf("%d", &choice);

    Matrix mat1;

    if (choice == 1) {
        printf("Enter dimensions of the first matrix (rows columns): ");
        scanf("%d %d", &rows1, &cols1);
        mat1 = allocateMatrix(rows1, cols1);
        inputMatrix(&mat1);
    } else if (choice == 2) {
        mat1 = readMatrixFromFile("matrix1.txt");
        rows1 = mat1.rows;
        cols1 = mat1.cols;
    } else {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }

    printf("Enter dimensions of the second matrix (rows columns): ");
    scanf("%d %d", &rows2, &cols2);

    Matrix mat2 = allocateMatrix(rows2, cols2);
    inputMatrix(&mat2);

    Matrix result = multiplyMatrices(mat1, mat2);

    printf("\nResult of matrix multiplication:\n");
    displayMatrix(result);

    double det = determinant(result);
    printf("\nDeterminant of the result matrix: %lf\n", det);

    printf("\nDo you want to read the previously saved matrix from file? (1 - Yes, 0 - No): ");
    int readFromFile;
    scanf("%d", &readFromFile);

    if (readFromFile) {
        Matrix matFromFile = readMatrixFromFile("result.txt");
        printf("\nMatrix read from file:\n");
        displayMatrix(matFromFile);
        freeMatrix(&matFromFile);
    } else {
        writeMatrixToFile("result.txt", result);
    }

    if (choice == 1) {
        freeMatrix(&mat1);
    }
    freeMatrix(&mat2);

    return 0;
}