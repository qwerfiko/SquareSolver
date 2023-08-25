///\file
///\brief test_solve_equation file
#ifndef TEST_SOLVE_EQUATION_H
#define TEST_SOLVE_EQUATION_H

#include "solve_equation.h"
#include "read_number.h"
#include <windows.h>

///< Test_data is a structure to which you can pass the ref values of coefficients, roots and their number
struct Test_data
{
    double a;   ///< ref-value of the coefficient a
    double b;   ///< ref-value of the coefficient b
    double c;   ///< ref-value of the coefficient c
    double x1ref;   ///< ref-the value of the root x1
    double x2ref;   ///< ref-the value of the root x2
    NRoots Roots_ref;   ///< ref-value of the number of roots
};
/*!
    The function takes a pointer to an array of data structures.
    For each element of the array, compares the values of coefficients, roots and their number with ref-values
    \param [in] data array of structures
    \return 0 if the test passed with an error
    \return 1 if the test was successful
 */
int Test_solve (Test_data* data);

#endif
