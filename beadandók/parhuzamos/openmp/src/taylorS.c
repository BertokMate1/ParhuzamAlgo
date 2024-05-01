#include "include/taylorS.h"
#include <math.h>
#include <omp.h>

double taylor_sin(double x, double a, int n) {
    double result = 0.0;
    double diff = x - a; // Difference between x and a

    #pragma omp parallel for reduction(+:result) // Parallelization with OpenMP
    for (int i = 0; i < n; ++i) {
        double term = 1.0;
        double factorial = 1.0;
        int sign = (i % 2 == 0) ? 1 : -1; // Alternating sign

        // Calculate factorial
        for (int j = 1; j <= 2 * i + 1; ++j) {
            factorial *= j;
        }

        // Calculate term without using pow
        for (int k = 0; k < 2 * i + 1; ++k) {
            term *= diff;
        }

        term *= sign / factorial; // Combine term with factorial and sign
        result += term;
    }

    return result;
}
