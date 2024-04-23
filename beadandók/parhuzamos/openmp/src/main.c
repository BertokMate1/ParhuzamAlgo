#include "taylorS.c"

int main() {
    int n;
    printf("Please enter the problem size (number of terms in the Taylor series): ");
    scanf("%d", &n);

    srand(time(NULL)); // Initialize random seed

    double x = (double)rand() / RAND_MAX * 10.0; // Generate a random value for x
    double a = (double)rand() / RAND_MAX * 10.0; // Generate a random value for a
    double taylor_result;

    for (int num_threads = 1; num_threads <= 10; ++num_threads) {
        omp_set_num_threads(num_threads);
        double start_time = omp_get_wtime(); // Measure time

        taylor_result = taylor_sin(x, a, n);

        double end_time = omp_get_wtime(); // Measure time

        printf("Time taken with %d thread(s): %lf seconds\n", num_threads, end_time - start_time);
    }

    return 0;
}
