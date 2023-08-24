#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

enum NRoots {Zero_null, Zero_one, Zero_two, Error, INF_ROOTS};

bool is_zero (double x);

NRoots solve_quadratic_equation (double a, double b, double c, double *x1, double *x2);
NRoots solve_linear_equation (double b, double c, double *x1, double *x2);

#endif
