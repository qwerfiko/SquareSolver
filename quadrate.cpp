//quadrate.c - a program for solving a quadratic equation
#include <TXlib.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <conio.h>
#include <windows.h>

#include "test_solve_equation.h"
#include "read_number.h"
#include "solve_equation.h"

void swap (double *x1, double *x2);

int main(int argc, char* argv[]) {

    double a = 0;
    double b = 0;
    double c = 0;

    SetConsoleTextAttribute (hConsole, 13);
    printf("Введите через пробел a, b, c:");
    read_number (&a, &b, &c);

    double x1 = 0;
    double x2 = 0;
    NRoots keys = solve_quadratic_equation (a, b, c, &x1, &x2);

    NRoots Roots_ref;
    const Test_data data1 [] = { { .a = 1, .b = 2, .c = 1,   .x1ref = -1, .x2ref = 0,  Zero_one },
                                 { .a = 1, .b = 0, .c = - 4, .x1ref = 2,  .x2ref = -2, Zero_two },
                                 { .a = 0, .b = 0, .c = 0,   .x1ref = 0,  .x2ref = 0,  INF_ROOTS },
                                 { .a = 2, .b = 1, .c = 4,   .x1ref = 0,  .x2ref = 0,  Zero_null },
                                 { .a = 0, .b = 2, .c = 4,   .x1ref = 2,  .x2ref = 0,  Zero_one },
                                 { .a = 0, .b = 0, .c = 2,   .x1ref = 0,  .x2ref = 0,  Error }
    };

    for (unsigned i = 0; i < sizeof(data1) / sizeof(Test_data); i++) {
        Test_solve (&data1 [i]);
    }

    SetConsoleTextAttribute (hConsole, 9);

    switch (keys) {
        case Zero_null:
        printf ("Уравнение не имеет корней\n");
        break;

    case Zero_one:
        printf ("Уравнение имеет один вещественный корень: %lg\n", x1);
        break;

    case Zero_two:
        printf ("Уравнение имеет два вещественных корня: %lg %lg \n", x1, x2);
        break;

    case Error:
        printf ("Корней нет. Неверное уравнение\n");
        break;

    case INF_ROOTS:
        printf ("Бесконечно много корней\n");
        break;

    default:
        printf("\nReached default case in function %s:%d\n", __PRETTY_FUNCTION__, __LINE__);
    }

    return 0;
}


void swap (double *x1, double *x2) {
    double tmp = *x1;
    *x1 = *x2;
    *x2 = tmp;
}

