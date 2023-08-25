///\file
///\brief main file

/*! \mainpage The square equation solver
    The program accepts for input the coefficients of the quadratic equation of the form ax^2 + bx + c = 0 <br>
    If the user has entered invalid values, the program issues a warning, the input must be repeated <br>
    The program solves the equation and displays the result on the screen indicating the number of roots found and their values
	*/

//Kvadratka.exe - a program for solving a quadratic equation
#include <TXlib.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "test_solve_equation.h"
#include "read_number.h"
#include "solve_equation.h"

int main (int argc, char* argv[]) {

    double a = 0;
    double b = 0;
    double c = 0;

    consolePaintText(TEXT_MAGENTA);
    printf ("Enter the coefficients a, b, c separated by a space: ");

    read_number (&a, &b, &c);

    double x1 = 0;
    double x2 = 0;
    /// When you enter the --test file into the console after launching, program testing starts
    if (argc == 2 && strcmp (argv[1], "--test") == 0) {
        Test_data data [] = {    { .a = 1, .b = 2, .c = 1,   .x1ref = -1, .x2ref = 0,  ZERO_ONE },  //< ref-values a != 0, discr = 0
                                 { .a = 1, .b = 0, .c = - 4, .x1ref = 2,  .x2ref = -2, ZERO_TWO },  //< ref-values a != 0, discr > 0
                                 { .a = 2, .b = 1, .c = 4,   .x1ref = 0,  .x2ref = 0,  ZERO_NULL }, //< ref-values a != 0, discr < 0
                                 { .a = 0, .b = 0, .c = 0,   .x1ref = 0,  .x2ref = 0,  INF_ROOTS }, //< ref-values a == 0, b =0, c = 0
                                 { .a = 0, .b = 2, .c = 4,   .x1ref = 2,  .x2ref = 0,  ZERO_ONE },  //< ref-values a == 0, b !=0, c!= 0
                                 { .a = 0, .b = 0, .c = 2,   .x1ref = 0,  .x2ref = 0,  INCORRECT }  //< ref-values a == 0, b = 0, c!=0
        };
             // TODO: consolePaintText(TEXT_RED); // enum CONSOLE_COLORS {TEXT_RED = 3456789};

        for (unsigned i = 0; i < sizeof (data) / sizeof (Test_data); i++) {
            Test_solve (&data [i]);
        }
    }

    /// The return value of the solve_quadratic_equution function (a, b, c, &x1, %x2) is stored in the solutions variable
    NRoots solutions = solve_quadratic_equation (a, b, c, &x1, &x2);

    consolePaintText(TEXT_BLUE);

    /// switch compares the resulting expression from the keys variable with case and displays information about the solution on the screen
    switch (solutions) {
        case ZERO_NULL:
        printf ("The equation has no real roots\n");
        break;

    case ZERO_ONE:
        printf ("The equation has one real root: %lg\n", x1);
        break;

    case ZERO_TWO:
        printf ("The equation has two real roots: %lg è %lg \n", x1, x2);
        break;

    case INCORRECT:
        printf ("There are no roots. Incorrect equation\n");
        break;

    case INF_ROOTS:
        printf ("Infinitely many roots\n");
        break;

    default:
        printf ("Reached default case in function %s. Unexpected number of roots: %d\n", __PRETTY_FUNCTION__, __LINE__);
    }

    return 0;
}



