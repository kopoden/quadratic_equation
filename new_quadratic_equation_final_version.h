/*! @file "new_quadratic_equation.h"
    @brief Library file.

    IT CONTAINS ALL FUNCTIONS, USING IN MAIN PROGRAM

    FUNCTIONS IN LIBRARY:

    clear_console();

    restart();

    input_data();

    solve_equation();

*/

/*! \enum results
    Contains all possible values returned by function solve_equation.
*/

enum results {
    NO_SOLUTIONS, ///< == solve_equation(), if there aren't any solutions.
    ONE_ROOT, ///< == solve_equation(), if there is the only root.
    TWO_ROOTS, ///< == solve_equation(), if there are two answers.
    INFINITE ///< == solve_equation(), if the number of answers is infinite.
    };

/*! \enum choice
    Contains all possible values returned by function restart.
*/

enum choice {
    FINISH, ///< == restart(), if user wants to close the program
    CONTINUE, ///< == restart(), if user wants to continue
    CLEAR_AND_CONTINUE, ///< == restart(), if user wants to clear the screen and continue
    INCORRECT_FORMAT ///< == restart(), if user used incorrect format.
    };

/*! \enum format
    Contains all possible values returned by function input_data.
*/

enum format {
    CORRECT, ///<  reports about correct input format.
    INCORRECT ///<  reports about incorrect input format.
    };

/*! @fn int input_data (double ArrayOfCoefficients[], const int coeffNum)
    @brief Inputs coefficients and checks data

    @param ArrayOfCoefficients
    @param coeffNum  amount of coefficients

    RETURNS:

    <b> CORRECT </b> if data format is correct

    <b> INCORRECT </b>  if data format is wrong
*/

int input_data (double coef[], const int coeffNum ) {

    char coefficient = 'A' - coeffNum + 2;

    printf("%c = ", coefficient);
    fflush(stdin);

    if (scanf("%lg", &coef[coeffNum]) == 0 || getchar() != '\n') {


        printf("%s\n", "Please, enter a rational number.");

        return INCORRECT;
    }

    return CORRECT;
}

/*! @fn int solve_equation (const double ArrayOfCoefficients[], double ArrayOfAnswers[])
    @brief Find roots and the number of them

    @param ArrayOfCoefficients
    @param ArrayOfAnswers

   Function, solving equation of these types:
   <ol>
    <li> Ax^2 + Bx + C = 0
    <li> Bx + C = 0
   </ol>

   RETURNS THE NUMBER OF SOLUTIONS:

   <ol>
    <li> <b> NO_SOLUTIONS </b>
    <li> <b> ONE_ROOT     </b>
    <li> <b> TWO_ROOTS    </b>
    <li> <b> INFINITE     </b>
   </ol>
*/

int solve_equation (const double coef[], double ans[]) {

    int num_of_x; //number of answers
    double D, sqrtD; // discriminant and its square root

//  Linear equation
    if (coef[2] == 0) {

//       There aren't any solutions
        if ((coef[1] == 0) && (coef[0] != 0))
            num_of_x = NO_SOLUTIONS;

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

/*! @fn void output_res(const int numberOfSolutions, const double ArrayOfAnswers[])
    @brief Shows result on the screen

    @param numberOfSolutions Number of roots counted with function solve_equation.
    @param ArrayOfAnswers
*/

void output_res (const int num_of_solutions, const double ans[]) {

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

/*! @fn void clear_console()
    @brief Function, clearing the console window
*/

void clear_console() {

    for (int i = 0; i < 20; i++)
      printf("\n\n\n\n\n");
}

/*! @fn int restart()
    @brief Function, asking user to restart or close program

    RETURNS:
    <ol>
     <li> <b> FINISH </b> (if user has entered '0')
     <li> <b> CONTINUE </b> (if user has entered '1')
     <li> <b> CLEAR_AND_CONTINUE </b> (if user has entered '2')
    </ol>

*/

int restart() {

    printf("%s", "Do you want to solve one more equation ");
    printf("%s", "and clear the screen?\n");
    printf("%s", "0 - No\n");
    printf("%s", "1 - Yes\n");
    printf("%s", "2 - Yes, clear the screen, please.\n");

    int input_num = INCORRECT_FORMAT;
    fflush(stdin);

    if ((scanf("%d", &input_num) == 0) || (getchar() != '\n')) {
        printf("%s", "Please, enter 0, 1 or 2.\n");
        return INCORRECT_FORMAT;
    }

    return input_num;
}
