#include "taylorS.c"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <series_length>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    srand(time(NULL)); // Initialize random seed

    double x = (double)rand() / RAND_MAX * 10.0; // Generate a random value for x
    double a = (double)rand() / RAND_MAX * 10.0; // Generate a random value for a
    double taylor_result;
    double math_result;

    for (int num_threads = 1; num_threads <= 10; ++num_threads) {
        omp_set_num_threads(num_threads);
        double start_time = omp_get_wtime(); // Measure time

        taylor_result = taylor_sin(x, a, n);
        math_result = sin(x);

        double end_time = omp_get_wtime(); // Measure time

        printf("Number of threads: %d, Taylor series approximation: %lf, math.h sin: %lf, difference: %lf, time: %lf seconds\n",
                num_threads, taylor_result, math_result, fabs(taylor_result - math_result), end_time - start_time);
    }

    return 0;
}