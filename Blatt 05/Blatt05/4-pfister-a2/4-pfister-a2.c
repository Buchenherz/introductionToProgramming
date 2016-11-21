//
//  main.c
//  4-pfister-a2
//
//  Created by Clemens Pfister on 18/11/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double compute_discriminant(double a, double b, double c);
short is_solvable(double discriminant);
double compute_x1(double a, double b, double c);
double compute_x2(double a, double b, double c);
int test_program();

int main() {
    double a, b, c = 0.0;
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
    compute_x1(a, b, c);
    compute_x2(a, b, c);
    
    return EXIT_SUCCESS;
}

double compute_discriminant(double a, double b, double c){
    double discriminant = (b * b) - (4 * a * c);
    // printf("Discriminant = %lf\n", discriminant);
    return discriminant;
}

short is_solvable(double discriminant){
    
    if (discriminant < 0) {
        // printf("Equation has no solutions in R!\n");
        return 0;
    } else if (discriminant == 0) {
        // printf("Equation has a solution in R!\n");
        return 1;
    } else if (discriminant > 0) {
        // printf("Equation has solutions in R!\n");
        return 2;
    }
    return EXIT_SUCCESS;
}

double compute_x1(double a, double b, double c){
    double discriminant = compute_discriminant(a, b, c);
    int solvable = is_solvable(discriminant);
    
    if (solvable == 0) {
        /* No solutions */
        printf("No solutions! x_1 = 0, x_2 = 0\n");
    } else if (solvable == 1) {
        /* Positive solution */
        double x_1 = ((-1 * b) + sqrt(discriminant))/(2*a);
        printf("One solution! x_1 = %lf\n", x_1);
    }
    /* Dont need other cases, rest is done in compute_x2 */
    
    return EXIT_SUCCESS;
}

double compute_x2(double a, double b, double c){
    
    double discriminant = compute_discriminant(a, b, c);
    
    if (is_solvable(discriminant) == 2) {
        double x_1 = ((-1 * b) + sqrt(discriminant))/(2*a);
        double x_2 = ((-1 * b) - sqrt(discriminant))/(2*a);
        printf("Two solutions! x_1 = %lf x_2 = %lf\n", x_1, x_2);
    }
    /* case 0 and 2: covered by compute_x1 */
    
    return EXIT_SUCCESS;
}

int test_program(){
    
    return EXIT_SUCCESS;
}
