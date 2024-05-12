#include "../include/taylorS.h"

double taylor_sin(double x, int n) {
    double result_sin = 0.0;

    #pragma omp parallel for reduction(+:result_sin) schedule(dynamic) // Parallelization with OpenMP, reduction, and static scheduling
    for (int i = 0; i < n; ++i) {
        double term = 1.0;
        double sign = (i % 2 == 0) ? 1 : -1; // Alternating sign

        // Calculate term without using pow and factorial
        for (int j = 0; j < 2 * i + 1; ++j) {
            term *= x / (j + 1); // Update term
        }

        term *= sign; // Apply sign
        result_sin += term;
    }

    return result_sin;
}

double taylor_cos(double x, int n) {
    double result_cos = 0.0;

    #pragma omp parallel for reduction(+:result_cos) schedule(dynamic) // Parallelization with OpenMP, reduction, and static scheduling
    for (int i = 0; i < n; ++i) {
        double term = 1.0;
        double sign = (i % 2 == 0) ? 1 : -1; // Alternating sign

        // Calculate term without using pow and factorial
        for (int j = 0; j < 2 * i; ++j) {
            term *= x / (j + 1); // Update term
        }

        term *= sign; // Apply sign
        result_cos += term;
    }

    return result_cos;
}