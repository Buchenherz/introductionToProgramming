//
//  main.c
//  4-pfister-a3
//
//  Created by Clemens Pfister on 26/11/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

bool save_division(const int* x, const int* y, int* result){
    if (*y > 0 && x && y && result) { /* Checks if pointers aren't NULL */
        if (*x >= *y){
            *result = *x / *y;
            printf("True\n");
            return true;
        }
        else if (*y >= *x) {
            *result = *y / *x;
            printf("True\n");
            return true;
        }
    }
    printf("False\n");
    return false;
}

int main() {
    int a = 4;
    int b = 2;
    int result = 0;
    
    save_division(&a, &b, &result);
    printf("= %d\n", result);
    
    
    /* Constant values do not change after first declaration,
     * this probably makes sure that pointers don't change
     * during function execution 
     */
    
    /* https://en.wikipedia.org/wiki/Pure_function
     * This function can be considered both a pure function 
     * and not a pure function. 
     * pure: when a b and result are initialized with same
     * numbers over and over again, the outcome will not 
     * vary
     * not pure: when constants are uninitialized, addresses
     * may vary and thus, the outcome could be different 
     * every single time 
     */
}
