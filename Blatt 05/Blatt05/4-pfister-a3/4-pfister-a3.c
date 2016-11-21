//
//  main.c
//  4-pfister-a3
//
//  Created by Clemens Pfister on 18/11/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int calc_mode = 0;

/* FIXME: Add some kind of "input" function here because DRY!! */


double add(){
    printf("+++ Sie befinden sich im Addierer +++\n");
    double a, b = 0.0;
    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%lf", &a);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%lf", &b);
    
    /* FIXME: Add solution variable because 2 calculations are not needed */
    
    printf("%lf\n", a+b);
    return a + b;
}


double subtract(){
    printf("--- Sie befinden sich im Subtrahierer ---\n");
    double a, b = 0.0;
    
    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%lf", &a);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%lf", &b);
    
    printf("%lf\n", a-b);
    return a - b;
}

long double multiply(){
    printf("*** Sie befinden sich im Multiplizierer ***\n");
    double a, b = 0.0;
    
    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%lf", &a);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%lf", &b);
    
    printf("%lf\n", a*b);
    return a * b;
}


int main() {
    while(1 == 1){
    printf("Taschenrechner:\n1-Addieren, 2-Subtrahieren, 3-Multiplizieren, 0-Beenden\n");
    printf("Bitte wählen Sie einen Modus aus: ");
    scanf("%d", &calc_mode);
    
    if (calc_mode == 0) {
        return EXIT_SUCCESS;
    } else if (calc_mode == 1) {
        add();
    } else if (calc_mode == 2) {
        subtract();
    } else if (calc_mode == 3) {
        multiply();
    }
    
    continue;
    }
}
