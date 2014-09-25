/*! @file "new quadratic equation.h"
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
    CLEAR_AND_CONTINUE ///< == restart(), if user wants to clear the screen and continue
    };

/*! \enum format
    Contains all possible values returned by function input_data.
*/

enum format {
    CORRECT, ///< == input_data(), reports about correct input data.
    INCORRECT ///< == input_data(), reports about incorrect input data.
    };

/*! @fn int input_data (double* arrayOfCoefficients)
    @brief Inputs coefficients and checks data

    RETURNS:

    \b CORRECT if data format is correct

    \b INCORRECT  if data format is wrong
*/

int input_data (double* coef) {

    printf("%s", "Input coefficients\n");

    int check = scanf("%lg %lg %lg", &coef[2], &coef[1], &coef[0]);
    if (check == 3)
        return CORRECT;
    else;
        return INCORRECT;
}

/*! @fn int solve_equation (double* ArrayOfCoefficients, double* ArrayOfAnswers)
    @brief Find roots and the number of them

   Function, solving equation of these types:
   <ol>
    <li> Ax^2 + Bx + C = 0
    <li> Bx + C = 0
   </ol>

   RETURNS THE NUMBER OF SOLUTIONS:

   <ol>
    <li> \b NO_SOLUTIONS
    <li> \b ONE_ROOT
    <li> \b TWO_ROOTS
    <li> \b INFINITE
   </ol>
*/

int solve_equation (double* coef, double* ans) {

    int num_of_x; //number of answers
    double D, sqrtD; // discriminant and its square root

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

/*! @fn void output_res(int numberOfSolutions, double* ArrayOfAnswers)
    @brief Shows result on the screen

    @param numberOfSolutions Number of roots counted with function solve_equation.
    @param ArrayOfAnswers
*/

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
     <li> \b FINISH (if user has entered '0')
     <li> \b CONTINUE (if user has entered '1')
     <li> \b CLEAR_AND_CONTINUE (if user has entered '2')
    </ol>

*/

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
