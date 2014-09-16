#include <stdio.h>
#include <math.h>

//Funtion, clearing the console window

void clear_console() {
    
    int i;

    for (i = 0; i < 20; i++)
      printf("\n\n\n\n\n");
}

//Function, defining the case, when the number of solutions is infinite

bool check_infinity(double* coef, double* ans) {
    if ((coef[0] == 0) and (coef[1] == 0) and (coef[2] == 0))
        return true;

    else;

    return false;
}

//Function, solving equation of these types: 1) Ax^2+Bx+C=0
//                                           2) Bx+C=0

int solve_equation (double* coef, double* ans) {

    int num_of_x;
    double D, sqrtD;

//  Linear equation
    if (coef[2] == 0) {
        
//       There aren't any solutions
        if ((coef[1] == 0) and (coef[0] != 0)) {
            num_of_x = 0;
        }

//       There is the only solution
        if ((coef[1] != 0) and (coef[0] != 0)) {
            num_of_x = 1;
            ans[0] = (-coef[0])/coef[1];
        }
    }
//   Quadratic equation
    if (coef[2] != 0) {
        D = (coef[1] * coef[1]) - (4 * coef[0] * coef[2]);

        if (D < 0) num_of_x = 0;

        if (D == 0) {
            num_of_x = 1;
            ans[0] = (-coef[1]) / (2 * coef[2]);
        }

        if (D > 0) {
            num_of_x = 2;
            sqrtD = sqrt(D);

            ans[0] = (-coef[1] + sqrtD) / (2 * coef[2]);
            ans[1] = (-coef[1] - sqrtD) / (2 * coef[2]);
        }

    }

    return num_of_x;
}


// Main function. Input and Output settings.
int main() {

    // It's necessary only to set array's sizes.
    int const MAX_DEGREE = 10;
    
    bool check_res;//Get the result of the function check_infinity
    
    int degree = -1;
    int i, num_of_solutions = 0;
    
    double coef[MAX_DEGREE + 1], ans[MAX_DEGREE];
    
    // flag defines if it's necessary to restart the program
    int flag = 1;
    
    while (flag != 0) {
        if (flag == 2)
            clear_console();
        flag = 0;
        printf("Input degree of equation( >=2 )\n");
        scanf("%d", &degree);
    
    //  Incorrect degree
        if ((degree < 2) or (degree > 10)) {
            printf("%s", "You have entered an incorrect degree.\n");
            printf("%s", "Please, read a guide(it's in repository) and try later.\n");
            return 0;
        }
    
    //  Degree is greater than 2
        if ((degree > 2) and (degree < 11))
            printf("%s", "This program can't solve so difficult equations.\n");
    
    //  Degree 2
        if (degree == 2) {
            printf("%s", "Input coefficients\n");
    
            for (i = degree; i >= 0; i--)
                scanf("%lg", &coef[i]);
    
            check_res = check_infinity(coef, ans);
    
    //      Infinite number of solutions.
            if (check_res == true)
                printf("%s", "The equation has an infinite number of solutions\n");
    
    //      Check returned false.
            if (check_res == false) {
                num_of_solutions = solve_equation(coef, ans);
    
                if (num_of_solutions == 0)
                    printf("The equation has no solutions\n");
    
                for (i = 0; i < num_of_solutions; i++)
                    printf("x%d = %lg\n", i, ans[i]);
            }
        }
    
    //   Program suggest to repeat an action
        printf("%s", "Do you want to solve one more equation ");
        printf("%s", "and clear the screen?\n");
        printf("%s", "0 - No\n");
        printf("%s", "1 - Yes\n");
        printf("%s", "2 - Yes, clear the screen, please.\n");
        scanf("%d", &flag);
    }

return 0;
}
