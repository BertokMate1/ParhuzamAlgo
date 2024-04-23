#include "include/matrixMult.h"

typedef struct {
    int start_row;
    int end_row;
} ThreadData;

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