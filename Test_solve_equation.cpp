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
    NRoots solutions1 = solve_quadratic_equation (data->a, data->b, data->c, &x1, &x2);

    if (!is_equal_comparison (x1, data->x1ref)  //< If x1 != x1ref
        || !is_equal_comparison (x2, data->x2ref)   //< If x2 != x2ref
        || solutions1 != data->Roots_ref) {    //< If the value is key != the value of Roots_ref passed by pointer from the structure
        consolePaintText (TEXT_RED);
        printf ("Mistake:   x1 = %lg,    x2 = %lg, nRoots = %d,"     //< Error message and expected result
                "expected:  x1ref = %lg, x2ref = %lg, nRoots = %d\n",
               x1, x2, solutions1, data->x1ref, data->x2ref, data->Roots_ref);
        consolePaintText (TEXT_WHITE);
        return 0;
    }

    else {
        consolePaintText (TEXT_GREEN);
        printf ("Successfully\n");
        consolePaintText (TEXT_WHITE);   //<A message about a successful test
        return 1;
    }
}

/// When you enter the --test file into the console after launching, program testing starts
int TestAll (int argc, char* argv[]) {
    int k = 0; //изменить название
    if (argc >= 2 && strcmp (argv[1], "--test") == 0) {
        if (argc > 2) {
            FILE *f = NULL;
            f = fopen (argv[2], "r");
            if (f == NULL) {
                printf ("ERROR: no such file: %s\n", argv[2]);

                Test_data data[] = {
                    { .a = 1, .b = 0, .c = 4,   .x1ref = 2,  .x2ref = -2, ZERO_TWO },  //< ref-values a != 0, discr > 0 .ERROR
                    { .a = 2, .b = 1, .c = 4,   .x1ref = 0,  .x2ref = 0,  ZERO_NULL }, //< ref-values a != 0, discr < 0
                    { .a = 0, .b = 0, .c = 0,   .x1ref = 0,  .x2ref = 0,  INF_ROOTS }, //< ref-values a == 0, b =0, c = 0
                    { .a = 0, .b = 2, .c = 4,   .x1ref = 2,  .x2ref = 0,  ZERO_ONE },  //< ref-values a == 0, b !=0, c!= 0
                    { .a = 0, .b = 0, .c = 2,   .x1ref = 0,  .x2ref = 0,  INCORRECT } //< ref-values a == 0, b = 0, c!=0
                };
                k = test_loop (data, sizeof (data)/sizeof(Test_data));

            }

            else {
                Test_data data [6] = {};    //< ref-values a != 0, discr = 0


                for (unsigned i = 0; i < sizeof (data) / sizeof (Test_data) ; i++) {
                    while (!feof (f)) {
                        int scan_res = fscanf (f, "%lg %lg %lg %lg %lg %d ", &data[i].a, &data[i].b, &data[i].c,
                                                         &data[i].x1ref, &data[i].x2ref, &data[i].Roots_ref);
                     //fscanf что выдаёт  EOF - конец потока файла
                        if (scan_res != 6) {
                        break;
                        }
                    }
                }
                k = test_loop (data, sizeof(data) / sizeof(Test_data)); //TODO: sizeof(data) / sizeof(Test_data) в отдельную функцию
                fclose (f);
            }
        }
        else {
            printf ("USAGE: kvadratka.exe --test FILE\n");
        }
    }
    return k;
}

int test_loop (Test_data* data, int length) {
    int counter = 0;
    for (int i = 0; i < length ; i++) {  //переименовать итератор
        printf ("a = %lg, b = %lg, c = %lg, x1ref = %lg, x2ref = %lg, nRoots = %d\n", data[i].a, data[i].b, data[i].c,
                                                                     data[i].x1ref, data[i].x2ref, data[i].Roots_ref);
        if (Test_solve (&data [i]) == 0) {
            counter += 1;
        }

    }
    return counter;
}
