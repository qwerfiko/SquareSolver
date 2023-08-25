#include <math.h>
#include <cstdio>
#include <cassert>
#include "read_number.h"
#include <windows.h>
#include "test_solve_equation.h"
#include "solve_equation.h"

void read_number (double *a, double *b, double *c) {

    assert (isfinite (*a) != 0);
    assert (isfinite (*b) != 0);
    assert (isfinite (*c) != 0);

    while (scanf ("%lg %lg %lg", a, b, c ) != 3) {
        printf ("I can't read the numbers. Try again. \n");

        clear_buffer();
    }

    consolePaintText (TEXT_WHITE);
    printf ("Coefficients are introduced: %lg, %lg, %lg\n",*a,*b,*c);
}

//-----------------------------------------------------------------------------

void clear_buffer() {
    while (getchar() != '\n')
        ;
}

//-----------------------------------------------------------------------------

void consolePaintText (CONSOLE_COLORS colors) {
    const HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);   ///< The function of obtaining the descriptor of the standard input, output device
    SetConsoleTextAttribute (hConsole, colors);
}


