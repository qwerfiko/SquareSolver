#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <conio.h>
#include "Windows.h"

#include "test_solve_equation.h"
#include "solve_equation.h"
#include "read_number.h"

bool is_equal_comparison (double x, double y);

int Test_solve (Test_data* data1) {
    double x1 = 0;
    double x2 = 0;

    NRoots key = solve_quadratic_equation (data1->a, data1->b, data1->c, &x1, &x2);

    if (!is_equal_comparison (x1, data1->x1ref)
        || !is_equal_comparison (x2, data1->x2ref)
        || key != data1->Roots_ref) {
        SetConsoleTextAttribute(hConsole, 4);
        printf ("Ошибка:       x1 = %lg,    x2 = %lg, nRoots = %d,"
                "ожидалось: x1ref = %lg, x2ref = %lg, nRoots = %d\n",
               x1, x2, key, data1->x1ref, data1->x2ref, data1->Roots_ref);
        return 0;
    }
    else {
        SetConsoleTextAttribute (hConsole, 2);
        printf ("Успешно\n");
        return 1;
    }
}

//-----------------------------------------------------------------------------

bool is_equal_comparison (double x, double y) {
    const double EPSILLON = 1e-6;
    return (fabs(x - y) < EPSILLON);
}
