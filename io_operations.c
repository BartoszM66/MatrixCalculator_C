#include "matrix_operations.h"
#include <stdio.h>
#include <stdlib.h>

//Funkcja wprowadzania macierzy
void inputMatrix(Matrix* mat) {
    printf("Enter matrix (%dx%d):\n", mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; ++i) {
        for (int j = 0; j < mat->cols; ++j) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            if (scanf("%lf", &mat->data[i][j]) != 1) {
                printf("Error: Invalid input. Please enter a valid number.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

//Funcja wyswietlania macierzy
void displayMatrix(Matrix mat) {
    printf("Matrix (%dx%d):\n", mat.rows, mat.cols);
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            printf("%lf\t", mat.data[i][j]);
        }
        printf("\n");
    }
}

//Funkcja do zapisywania do pliku
void writeMatrixToFile(const char* filename, Matrix mat) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error: Unable to open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d %d\n", mat.rows, mat.cols);

    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            fprintf(file, "%lf ", mat.data[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

//Funkcja do wczytywania z pliku
Matrix readMatrixFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    int rows, cols;
    fscanf(file, "%d %d", &rows, &cols);

    Matrix mat = allocateMatrix(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fscanf(file, "%lf", &mat.data[i][j]);
        }
    }

    fclose(file);

    return mat;
}