///\file
///\brief solve_equation file
#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H
/// A set of possible values of the number of roots
enum NRoots {ZERO_NULL = 0, ///< 0 roots
            ZERO_ONE = 1,   ///< 1 root
            ZERO_TWO = 2,   ///< 2 roots
            INCORRECT = 3,  ///< Incorrect equation, no roots
            INF_ROOTS = 4   ///< Infinitely many roots
};

/*!
the function takes two numbers as input and compares the modulus of the difference of two floating point numbers with static const EPSILON
\return true if the difference modulus is less than EPSILLON
*/
bool is_equal_comparison (double x, double y);
/*!
    The function takes the values of coefficients entered by the user.
    Solves a quadratic equation, if linear - uses the solve_linear_equation function inside (double b, double c, double *x1, double *x2)
    \param [in] coefficient a
    \param [in] coefficient b
    \param [in] coefficient c
    \param [out] root x1
    \param [out] root x2
    \return the enum NRoots field depending on the number of roots received
*/
NRoots solve_quadratic_equation (double a, double b, double c, double *x1, double *x2);
/*!
    The function takes the values of coefficients entered by the user.
    Solves a linear equation, a == 0
    \param [in] coefficient b
    \param [in] coefficient c
    \param [out] root x1
    \param [out] root x2
    \return the enum NRoots field depending on the number of roots received
*/
NRoots solve_linear_equation (double b, double c, double *x1);

#endif
