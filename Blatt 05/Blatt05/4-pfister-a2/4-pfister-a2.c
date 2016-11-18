//
//  main.c
//  4-pfister-a2
//
//  Created by Clemens Pfister on 18/11/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


double compute_discriminant(double a, double b, double c){
    double discriminant = (b * b)- 4 * a * c;
    printf("%lf\n", discriminant);
    return discriminant;
}

short is_solvable(double discriminant){
    if (discriminant >= 0) {
        printf("Equation has solutions in R!\n");
        return 1;
    } else {
        printf("Equation has no solutions in R!\n");
        return 0;
    }
}

double compute_x1(double a, double b, double c){
    double discriminant = compute_discriminant(a, b, c);
    if (is_solvable(discriminant) == 0){
        printf("0");
        return 0;
    }
    
}

double compute_x2(double a, double b, double c){
    double discriminant = compute_discriminant(a, b, c);
    if (is_solvable(discriminant) == 0){
        printf("0");
        return 0;
    }
}

int main() {
    double a, b, c = 0.0;
    printf("Please enter your first number: ");
    scanf("%lf", &a);
    printf("Please enter your second number: ");
    scanf("%lf", &b);
    printf("Please enter your third number: ");
    scanf("%lf", &c);
    double discriminant = compute_discriminant(a, b, c);
    is_solvable(discriminant);
    return EXIT_SUCCESS;
    
}



