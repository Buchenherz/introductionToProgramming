//
//  main.c
//  4-pfister-a3
//
//  Created by Clemens Pfister on 18/11/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

double add();
double subtract();
double multiply();
/* FIXME: Add some kind of "input" function here because DRY!! */

int calc_mode = 0;

int main() {
    while(1 == 1){
        printf("/*=======================================\n");
        printf("=            Taschenrechner:            =\n");
        printf("+            1-Addieren                 +\n");
        printf("-            2-Subtrahieren             -\n");
        printf("*            3-Multiplizieren           *\n");
        printf("q            0-Beenden                  q\n");
        printf("=======================================*/\n");
        printf("   Please choose a mode from above: ");
        scanf("%d", &calc_mode);
        printf("\n\n");
        
        if (calc_mode == 0) {
            system ( "clear" );
            return EXIT_SUCCESS;
        } else if (calc_mode == 1) {
            system ( "clear" );
            add();
        } else if (calc_mode == 2) {
            system ( "clear" );
            subtract();
        } else if (calc_mode == 3) {
            system ( "clear" );
            multiply();
        }
        
        continue;
    }
}

double add(){
    printf("+++++++++++++++++++++++++++++++++++++++++\n");
    printf("+       You are in addition mode!       +\n");
    printf("+               a + b = ?               +\n");
    printf("+++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n");
    double a, b = 0.0;
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    
    /* FIXME: Add solution variable because 2 calculations are not needed */
    
    printf("%lf\n\n", a+b);
    return EXIT_SUCCESS;
}


double subtract(){
    printf("-----------------------------------------\n");
    printf("-      You are in subtraction mode!     -\n");
    printf("-               a - b = ?               -\n");
    printf("-----------------------------------------\n");
    printf("\n");
    double a, b = 0.0;
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    
    printf("%lf\n\n", a-b);
    return EXIT_SUCCESS;
}

double multiply(){
    printf("*****************************************\n");
    printf("*      You are in subtraction mode!     *\n");
    printf("*               a * b = ?               *\n");
    printf("*****************************************\n");
    printf("\n");
    double a, b = 0.0;
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    
    printf("%lf\n\n", a*b);
    return EXIT_SUCCESS;
}
