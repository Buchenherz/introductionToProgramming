//
//  4-pfister-a2-testing.c
//  Blatt05
//
//  Created by Clemens Pfister on 21/11/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double compute_discriminant(double a, double b, double c);
short is_solvable(double discriminant);
double compute_x1(double a, double b, double c);
double compute_x2(double a, double b, double c);

int main() {
    
    printf("/*=======================================\n");
    printf("=               Solve x for             =\n");
    printf("=            ax^2 + bx + c = 0          =\n");
    printf("=======================================*/\n");
    
    /* If a is 0, program will find two solutions
     * with NaN and -inf because division through 0 */
    
    compute_x1(0, 2, 7);
    compute_x2(0, 2, 7);
    
    printf("\n");
    
    /* If discriminant is negative, no solution is found */
    
    compute_x1(1, 2, 1);
    compute_x2(1, 2, 1);
    
    printf("\n");
    
    /* If the user enters something different then a number
     * the programm will output solution 0.0 */
    
    double x = 0;
    printf("Enter char: ");
    compute_x1(scanf("%lf", &x), 1, 2);
    compute_x2(scanf("%lf", &x), 1, 2);
    
    
    /* Testing for some numbers
    
    for(int i = -15; i <= 15; i++){
        for (int j = -15; j <= 15; j++) {
            for (int k = -15; k <= 15; k++) {
                compute_x1(i, j, k);
                compute_x2(i, j, k);
                
                printf("\n");
            }
        }
    }
    
    */
    
    
    return EXIT_SUCCESS;
}

double compute_discriminant(double a, double b, double c){
    double discriminant = (b * b) - (4 * a * c);
    /* printf("Discriminant = %lf\n", discriminant); */
    return discriminant;
}

short is_solvable(double discriminant){
    
    if (discriminant < 0) {
        /* printf("Equation has no solutions in R!\n"); */
        return 0;
    } else if (discriminant == 0) {
        /* printf("Equation has a solution in R!\n"); */
        return 1;
    } else if (discriminant > 0) {
        /* printf("Equation has solutions in R!\n"); */
        return 2;
    }
    return EXIT_SUCCESS;
}

double compute_x1(double a, double b, double c){
    double discriminant = compute_discriminant(a, b, c);
    int solvable = is_solvable(discriminant);
    
    if (solvable == 0) {
        /* No solutions */
        printf("-----------------------------------------\n");
        printf("=             No solutions!             =\n");
        printf("=                x_1 = 0                =\n");
        printf("=                x_2 = 0                =\n");
        printf("-----------------------------------------\n");
    } else if (solvable == 1) {
        /* Positive solution */
        double x_1 = ((-1 * b) + sqrt(discriminant))/(2*a);
        printf("-----------------------------------------\n");
        printf("              One solution!              \n");
        printf("              x_1 = %lf            \n", x_1);
        printf("-----------------------------------------\n");
    }
    /* Dont need other cases, rest is done in compute_x2 */
    
    return EXIT_SUCCESS;
}

double compute_x2(double a, double b, double c){
    
    double discriminant = compute_discriminant(a, b, c);
    
    if (is_solvable(discriminant) == 2) {
        double x_1 = ((-1 * b) + sqrt(discriminant))/(2*a);
        double x_2 = ((-1 * b) - sqrt(discriminant))/(2*a);
        printf("-----------------------------------------\n");
        printf("               Two solutions!            \n");
        printf("              x_1 = %lf            \n", x_1);
        printf("              x_2 = %lf            \n", x_2);
        printf("-----------------------------------------\n");
    }
    /* case 0 and 2: covered by compute_x1 */
    
    return EXIT_SUCCESS;
}
