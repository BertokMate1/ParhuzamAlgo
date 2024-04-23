#ifndef MATRIXMULT_H
#define MATRIXMULT_H

#define NUM_THREADS 10

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int** matrixA;
int** matrixB;
int** result;
int MATRIX_SIZE;

void* multiply(void* arg);

#endif /* MATRIXMULT_H */