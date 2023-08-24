#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include "solve_equation.h"

const double EPSILLON = 1e-6;

NRoots solve_quadratic_equation (double a, double b, double c, double *x1, double *x2) {

    assert (std::isfinite (a));
    assert (std::isfinite (b));
    assert (std::isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (is_zero(a)) {
        return solve_linear_equation (b, c, x1, x2);
    }

    double discr = b * b - 4*a*c;

    if (discr < -EPSILLON) {
        return Zero_null;
    }

    if (is_zero(discr)) {
        *x1 = -b/(2*a);
        return Zero_one;
    }

    if (discr > EPSILLON) {
        double sqrt_d = sqrt(discr);
        *x1 = (-b + sqrt_d) / (2*a);
        *x2 = (-b - sqrt_d) / (2*a);
        return Zero_two;
    }
}

//-----------------------------------------------------------------------------

NRoots solve_linear_equation (double b, double c, double *x1, double *x2) {
    if (is_zero(b) == false) {
        *x1 = c/b;
        return Zero_one;
    }

    if (is_zero(b) && is_zero(c) == false) {
        return Error;
    }

    if (is_zero(b) && is_zero(c)) {
        return INF_ROOTS;
    }
}

//-----------------------------------------------------------------------------

bool is_zero (double x) {
    return (fabs(x) < EPSILLON);
}
