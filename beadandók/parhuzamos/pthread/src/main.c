#include "matrixMult.c"

int main() {
    srand(time(NULL));

    clock_t start, end;
    double cpu_time_used;

    printf("How big should the matrix be? : ");
    scanf("%d", &MATRIX_SIZE);

    // Allocate memory for matrix
    matrixA = (int**)malloc(MATRIX_SIZE * sizeof(int*));
    matrixB = (int**)malloc(MATRIX_SIZE * sizeof(int*));
    result = (int**)malloc(MATRIX_SIZE * sizeof(int*));
    
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        matrixA[i] = (int*)malloc(MATRIX_SIZE * sizeof(int));
        matrixB[i] = (int*)malloc(MATRIX_SIZE * sizeof(int));
        result[i] = (int*)malloc(MATRIX_SIZE * sizeof(int));
    }

    // Initialize matrix with random values
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            matrixA[i][j] = rand() % 100;
            matrixB[i][j] = rand() % 100;
        }
    }

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    int chunk_size = MATRIX_SIZE / NUM_THREADS;
    int start_row = 0;

    // Repeat the process for different number of threads
    for (int num_threads = 1; num_threads <= NUM_THREADS; num_threads += 1) {
        start = clock(); // Start time measurement

        // Create threads
        int chunk_size = MATRIX_SIZE / num_threads;
        int start_row = 0;
        for (int i = 0; i < num_threads; ++i) {
            thread_data[i].start_row = start_row;
            thread_data[i].end_row = start_row + chunk_size;
            if (i == num_threads - 1) {
                thread_data[i].end_row = MATRIX_SIZE;
            }
            start_row += chunk_size;
            pthread_create(&threads[i], NULL, multiply, &thread_data[i]);
        }

        // Wait for threads to finish
        for (int i = 0; i < num_threads; ++i) {
            pthread_join(threads[i], NULL);
        }

        end = clock(); // End time measurement
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time taken with %d threads: %f seconds\n", num_threads, cpu_time_used);
    }

    // Free memory
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        free(matrixA[i]);
        free(matrixB[i]);
        free(result[i]);
    }
    free(matrixA);
    free(matrixB);
    free(result);

    return 0;
}
