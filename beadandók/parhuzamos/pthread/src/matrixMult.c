#include "include/matrixMult.h"

int** matrixA;
int** matrixB;
int** result;
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
            result[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    pthread_exit(NULL);
}