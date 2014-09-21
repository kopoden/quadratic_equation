enum results {NO_SOLUTIONS, ONE_ROOT, TWO_ROOTS, INFINITE};

enum choice {FINISH, CONTINUE, CLEAR_AND_CONTINUE};

enum format {CORRECT, INCORRECT};

int input_data (double* coef) {

    printf("%s", "Input coefficients\n");

    int check = scanf("%lg %lg %lg", &coef[2], &coef[1], &coef[0]);
    if (check == 3)
        return CORRECT;
    else;
        return INCORRECT;
}

//Function, solving equation of these types: 1) Ax^2+Bx+C=0
//                                           2) Bx+C=0
int solve_equation (double* coef, double* ans) {

    int num_of_x;
    double D, sqrtD;

//  Linear equation
    if (coef[2] == 0) {

//       There aren't any solutions
        if ((coef[1] == 0) && (coef[0] != 0)) {
            num_of_x = NO_SOLUTIONS;
        }

//       There is the only solution
        if (coef[1] != 0) {
            num_of_x = ONE_ROOT;

            ans[0] = (-coef[0]) / coef[1];
            if (coef[0] == 0) // '-0' --->'0'
                ans[0] = 0;
        }

//       All numbers.
        if ((coef[1] == 0) && (coef[0] == 0)) {
            num_of_x = INFINITE;
        }
    }
//   Quadratic equation
    if (coef[2] != 0) {
        D = (coef[1] * coef[1]) - (4 * coef[0] * coef[2]);

        if (D < 0) num_of_x = NO_SOLUTIONS;

        if (D == 0) {
            num_of_x = ONE_ROOT;

            ans[0] = (-coef[1]) / (2 * coef[2]);
        }

        if (D > 0) {
            num_of_x = TWO_ROOTS;
            sqrtD = sqrt(D);

            ans[0] = (-coef[1] + sqrtD) / (2 * coef[2]);
            ans[1] = (-coef[1] - sqrtD) / (2 * coef[2]);
        }

    }

    return num_of_x;
}

void output_res(int num_of_solutions, double* ans) {

    //      Infinite number of solutions.
    switch (num_of_solutions) {

        case INFINITE:
            printf("%s", "The equation has an infinite number of solutions\n");
            break;

        case NO_SOLUTIONS:
            printf("The equation has no solutions\n");
            break;

        case ONE_ROOT:
            printf("x = %lg\n", ans[0]);
            break;

        case TWO_ROOTS:
            printf("x1 = %lg\n", ans[0]);
            printf("x2 = %lg\n", ans[1]);
            break;
    }
}

//Function, clearing the console window
void clear_console() {

    for (int i = 0; i < 20; i++)
      printf("\n\n\n\n\n");
}

int restart() {
    int input_num;
    //   Program suggest to repeat an action
    printf("%s", "Do you want to solve one more equation ");
    printf("%s", "and clear the screen?\n");
    printf("%s", "0 - No\n");
    printf("%s", "1 - Yes\n");
    printf("%s", "2 - Yes, clear the screen, please.\n");
    scanf("%d", &input_num);
    return input_num;
}
