#ifndef MATRIXMULT_H
#define MATRIXMULT_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

/**
 * @brief Perform multiplication between two matrices.
 * 
 * @param arg Data structure associated with the thread, containing the start and end rows of the thread.
 * @return void* Thread execution completion.
 */
void* multiply(void* arg);

#endif /* MATRIXMULT_H */