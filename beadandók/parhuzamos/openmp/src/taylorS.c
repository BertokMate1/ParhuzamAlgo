#include "include/taylorS.h"

double f(double x) {
    return sin(x); // The sine function
}

double taylor_sin(double x, double a, int n) {
    double result = 0.0;
    double power = 1.0;
    double factorial = 1.0;

    // Sum of the Taylor series
    #pragma omp parallel for reduction(+:result) // Parallelization with OpenMP
    for (int i = 0; i < n; ++i) {
        power *= (x - a);
        factorial *= (i + 1);
        result += (power / factorial) * pow(-1, i) * f(a + i);
    }

    return result;
}