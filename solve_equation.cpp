#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "solve_equation.h"
/// EPSILLON - precision static constant for comparing floating point numbers
static double EPSILON = 1e-6;

NRoots solve_quadratic_equation (double a, double b, double c, double *x1, double *x2) {

    assert (isfinite (a) != 0);
    assert (isfinite (b) != 0);
    assert (isfinite (c) != 0);

    assert (x1 != NULL);
    assert (x2 != NULL);

    if (is_equal_comparison (a, 0)) {   //< If a == 0, then the function for solving the linear equation solve_linear_equation (b, c, x1, x2) is called
        return solve_linear_equation (b, c, x1, x2);    //< возвращется поле enum NRoots
    }
    //< Otherwise , the quadratic equation is solved through the discriminant
    double discr = b * b - 4 * a * c;   //< Calculating the discriminant discr

    if (discr < -EPSILON) {    //< Handling case d < 0
        return ZERO_NULL;
    }

    if (is_equal_comparison (discr, 0)) {   //< Handling case d == 0
        *x1 = -b / (2 * a);
        return ZERO_ONE;
    }

    if (discr > EPSILON) { //< Handling case d > 0
        double sqrt_d = sqrt (discr);
        *x1 = (-b + sqrt_d) / (2 * a);
        *x2 = (-b - sqrt_d) / (2 * a);
        return ZERO_TWO;
    }
}

//-----------------------------------------------------------------------------

NRoots solve_linear_equation (double b, double c, double *x1, double *x2) {
    if (!is_equal_comparison (b, 0)) {  //< Handling the case at b != 0, c != 0
        *x1 = c/b;
        return ZERO_ONE;
    }

    if (is_equal_comparison (b, 0) && !is_equal_comparison (c, 0)) {  //< Handling the case when b = 0, c != 0
        return INCORRECT;
    }

    if (is_equal_comparison (b, 0) && is_equal_comparison (c, 0)) { //< Handling the case when b = 0, c != 0
        return INF_ROOTS;
    }
}


//-----------------------------------------------------------------------------

bool is_equal_comparison (double x, double y) {
    return (fabs (x - y) < EPSILON);
}
