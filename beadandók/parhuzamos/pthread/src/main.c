#include "matrixMult.c"

int main(int argc, char *argv[]) {
    srand(time(NULL));

    clock_t start, end;
    double cpu_time_used;

    if (argc != 3) {
        printf("Usage: %s <matrix_size> <num_threads>\n", argv[0]);
        return 1;
    }

    MATRIX_SIZE = atoi(argv[1]);
    int num_threads = atoi(argv[2]);

    // Allocate memory for matrixA
    matrixA = (double**)malloc(MATRIX_SIZE * sizeof(double*));
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        matrixA[i] = (double*)malloc(MATRIX_SIZE * sizeof(double));
    }

    // Allocate memory for matrixB
    matrixB = (double**)malloc(MATRIX_SIZE * sizeof(double*));
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        matrixB[i] = (double*)malloc(MATRIX_SIZE * sizeof(double));
    }

    // Initialize matrixA with random values
    //printf("Matrix A:\n");
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            matrixA[i][j] = (rand() % 201 - 100) / 10.0; // Random double between -10 and 10
            //printf("%.2f ", matrixA[i][j]);
        }
        //printf("\n");
    }
    //printf("\n");

    originalA = (double**)malloc(MATRIX_SIZE * sizeof(double*));
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        originalA[i] = (double*)malloc(MATRIX_SIZE * sizeof(double));
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            originalA[i][j] = matrixA[i][j];
        }
    }

    // Initialize matrixB with random values
    //printf("Matrix B:\n");
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            matrixB[i][j] = (rand() % 201 - 100) / 10.0; // Random double between -10 and 10
            //printf("%.2f ", matrixB[i][j]);
        }
        //printf("\n");
    }
    //printf("\n");

    // Allocate memory for the result matrix
    resultMatrix = (double**)malloc(MATRIX_SIZE * sizeof(double*));
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        resultMatrix[i] = (double*)malloc(MATRIX_SIZE * sizeof(double));
    }

    // Initialize threads
    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];
    int rows_per_thread = MATRIX_SIZE / num_threads;

    // Launch threads for matrix multiplication
    for (int i = 0; i < num_threads; ++i) {
        thread_data[i].start_row = i * rows_per_thread;
        thread_data[i].end_row = (i + 1) * rows_per_thread;
        if (i == num_threads - 1) {
            thread_data[i].end_row = MATRIX_SIZE; // Last thread takes remaining rows
        }
        pthread_create(&threads[i], NULL, multiply, (void*)&thread_data[i]);
    }

    start = clock(); // Start measuring time

    // Join threads for matrix multiplication
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Initialize barrier for LU decomposition
    pthread_barrier_t barrier;
    pthread_barrier_init(&barrier, NULL, num_threads);

    // Launch threads for LU decomposition
    for (int i = 0; i < num_threads; ++i) {
        thread_data[i].start_row = i * rows_per_thread;
        thread_data[i].end_row = (i + 1) * rows_per_thread;
        if (i == num_threads - 1) {
            thread_data[i].end_row = MATRIX_SIZE; // Last thread takes remaining rows
        }
        pthread_create(&threads[i], NULL, LUDecompose, (void*)&thread_data[i]);
    }

    // Join threads for LU decomposition
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    end = clock(); // Stop measuring time

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print matrices L and U
    double** L = (double**)malloc(MATRIX_SIZE * sizeof(double*));
    double** U = (double**)malloc(MATRIX_SIZE * sizeof(double*));
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        L[i] = (double*)malloc(MATRIX_SIZE * sizeof(double));
        U[i] = (double*)malloc(MATRIX_SIZE * sizeof(double));
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            if (i == j) {
                L[i][j] = 1;
                U[i][j] = matrixA[i][j];
            } else if (i < j) {
                L[i][j] = 0;
                U[i][j] = matrixA[i][j];
            } else {
                L[i][j] = matrixA[i][j];
                U[i][j] = 0;
            }
        }
    }

    //  Multiply matrices L and U
double** LU_result = (double**)malloc(MATRIX_SIZE * sizeof(double*));
for (int i = 0; i < MATRIX_SIZE; ++i) {
    LU_result[i] = (double*)malloc(MATRIX_SIZE * sizeof(double));
    for (int j = 0; j < MATRIX_SIZE; ++j) {
        LU_result[i][j] = 0;
        for (int k = 0; k < MATRIX_SIZE; ++k) {
            LU_result[i][j] += L[i][k] * U[k][j];
        }
    }
}

// Compare the obtained LU result with the original A matrix
bool correct = true;
for (int i = 0; i < MATRIX_SIZE; ++i) {
    for (int j = 0; j < MATRIX_SIZE; ++j) {
        if (fabs(LU_result[i][j] - originalA[i][j]) > 0.1) { // Tűrés: 0.0001
            correct = false;
            break;
        }
    }
    if (!correct) break;
}

// Print the result
if (correct) {
    printf("Az LU felbontas helyes.\n");
} else {
    printf("Az LU felbontas helytelen.\n");
}

    // Print matrices L and U
    //printMatrix(L, MATRIX_SIZE, "L");

    //printMatrix(U, MATRIX_SIZE, "U");

    //printMatrix(originalA, MATRIX_SIZE, "Original A");

    // Running speed
    printf("Time taken: %.6f second(s)\n", cpu_time_used);

    // Free memory
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        free(matrixA[i]);
        free(matrixB[i]);
        free(resultMatrix[i]);
        free(L[i]);
        free(U[i]);
    }
    free(matrixA);
    free(matrixB);
    free(resultMatrix);
    free(L);
    free(U);

    return 0;
}