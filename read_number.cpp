#include <cmath>
#include <cstdio>
#include <cassert>
#include "read_number.h"

void read_number (double *a, double *b, double *c) {

    assert (a != nullptr);
    assert (b != nullptr);
    assert (c != nullptr);

    while (scanf ("%lg %lg %lg", a, b, c ) != 3) {
        printf ("Не могу прочитать числа. Повторите попытку. \n");

        clear_buffer();
    }
    printf ("%lg, %lg, %lg\n",*a,*b,*c);
}

void clear_buffer() {
    while (getchar() != '\n')
        ;
}


