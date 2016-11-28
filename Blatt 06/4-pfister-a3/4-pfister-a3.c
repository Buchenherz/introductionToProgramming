/*
//  4-pfister-a3.c
//
//  http://git.io/vXWXq
//  Created by Clemens Pfister on 26/11/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool save_division(const int* x, const int* y, int* result){
    if (*y > 0 && x && y && result) { /* Checks if pointers aren't NULL */
        *result = *x / *y;
        printf("True\n"); /* Just for testing */
        return true;
    }
    printf("False\n");
    return false;
}

int main() {
    int a = 100;
    int b = 2;
    int result = 0;
    
    if (save_division(&a, &b, &result)){
        printf("%d / %d = %d\n", a, b, result);
    } else {
        printf("Check your input, somethings isn't right here...\n");
    }
    
    
    
    /* Constant values do not change after first declaration.
     * This makes sure that pointers don't change
     * during function execution.
     */
    
    /* https://en.wikipedia.org/wiki/Pure_function
     * This function can be considered both a pure function 
     * and not a pure function. 
     *
     * pure: when a b and result are initialized with same
     * numbers over and over again, the outcome will not 
     * vary (result will change during the function, duh).
     *
     * not pure: when constants are uninitialized, addresses
     * may vary and thus, the outcome could be different 
     * every single time 
     */
}
