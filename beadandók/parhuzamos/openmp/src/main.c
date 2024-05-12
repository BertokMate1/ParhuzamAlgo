#include "taylorS.c"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <series_length>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    srand(time(NULL)); // Initialize random seed

    double x = (double)rand() / RAND_MAX * 10.0; // Generate a random value for x
    double taylor_sin_result;
    double taylor_cos_result;
    double math_sin_result;
    double math_cos_result;

    for (int num_threads = 1; num_threads <= 10; ++num_threads) {
        omp_set_num_threads(num_threads);
        double start_time = omp_get_wtime(); // Measure time

        taylor_sin_result = taylor_sin(x, n);
        taylor_cos_result = taylor_cos(x, n);
        math_sin_result = sin(x);
        math_cos_result = cos(x);

        double end_time = omp_get_wtime(); // Measure time

        printf("Number of threads: %d, Taylor series approximation of sin: %lf, math.h sin: %lf, difference (sin): %lf\n",
                num_threads, taylor_sin_result, math_sin_result, fabs(taylor_sin_result - math_sin_result));
        printf("Number of threads: %d, Taylor series approximation of cos: %lf, math.h cos: %lf, difference (cos): %lf\n",
                num_threads, taylor_cos_result, math_cos_result, fabs(taylor_cos_result - math_cos_result));
        printf("Time: %lf seconds\n", end_time - start_time);
    }

    return 0;
}