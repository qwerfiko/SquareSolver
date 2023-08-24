#ifndef TEST_SOLVE_EQUATION_H
#define TEST_SOLVE_EQUATION_H

#include "solve_equation.h"
#include "read_number.h"
#include <windows.h>

const HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

struct Test_data
{
    double a;
    double b;
    double c;
    double x1ref;
    double x2ref;
    NRoots Roots_ref;
};

int Test_solve (Test_data* data);

#endif
