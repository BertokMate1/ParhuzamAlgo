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
 * @param n The length of the Taylor series.
 * @return The approximated sine value.
 */
double taylor_sin(double x, int n);

/**
 * @brief Approximates the value of the cosine function using Taylor series.
 * 
 * @param x The argument whose cosine is approximated.
 * @param n The length of the Taylor series.
 * @return The approximated cosine value.
 */
double taylor_cos(double x, int n);

#endif /* TAYLORS_H */
