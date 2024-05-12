#include "../include/matrixMult.h"

double** matrixA;
double** matrixB;
double** resultMatrix;
int MATRIX_SIZE;

typedef struct {
    int start_row; ///< Start row of the thread.
    int end_row;   ///< End row of the thread.
} ThreadData;

/**
 * @brief Perform matrix multiplication by a single thread.
 * 
 * @param arg Data structure associated with the thread, containing the start and end rows of the thread.
 * @return void* Thread execution completion.
 */
void* multiply(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int start_row = data->start_row;
    int end_row = data->end_row;

    for (int i = start_row; i < end_row; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            resultMatrix[i][j] = 0; // Initialize resultMatrix element
            for (int k = 0; k < MATRIX_SIZE; ++k) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    pthread_exit(NULL);
}

// Function to perform LU decomposition
void LUDecomposition(double** A, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = k + 1; i < n; ++i) {
            if (A[k][k] != 0) {
                A[i][k] /= A[k][k];
            }
            for (int j = k + 1; j < n; ++j) {
                A[i][j] -= A[i][k] * A[k][j];
            }
        }
    }
}

// Function to print matrix
void printMatrix(double** matrix, int n, const char* name) {
    printf("Matrix %s:\n", name);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}