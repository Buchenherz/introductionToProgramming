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


double compute_discriminant(double a, double b, double c){
    double discriminant = (b * b) - (4 * a * c);
    // printf("Discriminant = %lf\n", discriminant);
    return discriminant;
}

short is_solvable(double discriminant){
    if (discriminant >= 0) {
        // printf("Equation has solutions in R!\n");
        return 1;
    } else {
        // printf("Equation has no solutions in R!\n");
        return 0;
    }
}

double compute_x1(double a, double b, double c){
    double discriminant = compute_discriminant(a, b, c);
    if (is_solvable(discriminant) == 0){
        printf("x1 = 0\n");
        return 0;
    }
    double x_1 = ((-1 * b) + sqrt(discriminant))/(2*a);
    printf("x1 = %lf\n", x_1);
    return x_1;
}

double compute_x2(double a, double b, double c){
    double discriminant = compute_discriminant(a, b, c);
    if (is_solvable(discriminant) == 0){
        printf("x2 = 0\n");
        return 0;
    }
    double x_2 = ((-1 * b) - sqrt(discriminant))/(2*a);
    printf("x2 = %lf\n", x_2);
    return x_2;
}

int main() {
    // test_program();
    double a, b, c = 0.0;
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
    // double discriminant = compute_discriminant(a, b, c);
    // is_solvable(discriminant);
    compute_x1(a, b, c);
    compute_x2(a, b, c);
    
    return EXIT_SUCCESS;
}

int test_program(){
    
    return EXIT_SUCCESS;
}


