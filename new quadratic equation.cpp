
/*! @file "new quadratic equation.cpp"
    @brief File of main program.
*/

#include <stdio.h>
#include <math.h>
#include "new quadratic equation.h"

int main() {

    // It's neccessary only to set array's sizes
    int const MAX_DEGREE = 2;

    double coef[MAX_DEGREE + 1], ans[MAX_DEGREE];

    int restart_and_clear_marker = CONTINUE;

    while (restart_and_clear_marker != FINISH) {

        if (restart_and_clear_marker == CLEAR_AND_CONTINUE)
            clear_console();

        int check_res = input_data(coef);

        if (check_res == CORRECT) {

            int num_of_roots = solve_equation(coef, ans);
            output_res(num_of_roots, ans);
        }

        if (check_res == INCORRECT) {
            printf("%s", "Incorrect format\n");
            return 0;
        }

        restart_and_clear_marker = restart();

    }

    return 0;
}
