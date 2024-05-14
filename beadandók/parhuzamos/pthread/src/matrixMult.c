#include "../include/matrixMult.h"

double** matrixA;
double** originalA;
double** matrixB;
double** resultMatrix;
int MATRIX_SIZE;
pthread_barrier_t barrier;

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

/**
 * @brief Perform LU decomposition by a single thread.
 * 
 * @param arg Data structure associated with the thread, containing the start and end rows of the thread.
 * @return void* Thread execution completion.
 */
void* LUDecompose(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int start_row = data->start_row;
    int end_row = data->end_row;

    for (int k = 0; k < MATRIX_SIZE; ++k) {
        for (int i = start_row; i < end_row; ++i) {
            if (i > k) {
                if (matrixA[k][k] != 0) {
                    matrixA[i][k] /= matrixA[k][k];
                }
            }
        }
        pthread_barrier_wait(&barrier); // Wait for all threads to finish updating A[i][k]

        for (int i = start_row; i < end_row; ++i) {
            if (i > k) {
                for (int j = k + 1; j < MATRIX_SIZE; ++j) {
                    matrixA[i][j] -= matrixA[i][k] * matrixA[k][j];
                }
            }
        }
        pthread_barrier_wait(&barrier); // Wait for all threads to finish updating A[i][j]
    }

    pthread_exit(NULL);
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