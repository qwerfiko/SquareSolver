#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <conio.h>
#include "windows.h"

#include "test_solve_equation.h"
#include "solve_equation.h"
#include "read_number.h"

int Test_solve (Test_data* data) {
    double x1 = 0;
    double x2 = 0;

    ///< The value solve_quadratic_equation is stored in the key variable (data->a, data->b, data->c, &x1, &x2)
/*!
Values are passed to the solve_quadratic_equation function
 \param [in] element of structure a
 \param [in] element of structure b
 \param [in] element of the c structure
 \param [out] the root obtained by substituting coefficients from an array of structures
 \param [out] the root obtained by substituting coefficients from an array of structures
 */
    NRoots solutions1 = solve_quadratic_equation (data->a, data->b, data->c, &x1, &x2);

    if (!is_equal_comparison (x1, data->x1ref)  //< If x1 != x1ref
        || !is_equal_comparison (x2, data->x2ref)   //< If x2 != x2ref
        || solutions1 != data->Roots_ref) {    //< If the value is key != the value of Roots_ref passed by pointer from the structure
        consolePaintText (TEXT_RED);
        printf ("Mistake:   x1 = %lg,    x2 = %lg, nRoots = %d,"     //< Error message and expected result
                "expected:  x1ref = %lg, x2ref = %lg, nRoots = %d\n",
               x1, x2, solutions1, data->x1ref, data->x2ref, data->Roots_ref);
        return 0;
    }

    else {
        consolePaintText (TEXT_GREEN);
        printf ("Successfully\n");   //<A message about a successful test
        return 1;
    }
}
