#ifndef TAYLORS_H
#define TAYLORS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>

double f(double x);

double taylor_sin(double x, double a, int n);

#endif /* TAYLORS_H */