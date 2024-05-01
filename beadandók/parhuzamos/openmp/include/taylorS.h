#ifndef TAYLORS_H
#define TAYLORS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>

/**
 * @brief Approximates the value of the sine function using Taylor series.
 * 
 * @param x The argument whose sine is approximated.
 * @param a The center of the Taylor series.
 * @param n The length of the Taylor series.
 * @return The approximated sine value.
 */
double taylor_sin(double x, double a, int n);

/**
 * @brief Mathematical sine function.
 * 
 * @param x The argument whose sine is calculated.
 * @return The sine value.
 */
double f(double x);

#endif /* TAYLORS_H */
