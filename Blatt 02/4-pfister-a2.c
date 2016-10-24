//
//  4-pfister-a2.c
//  a1

//  Created by Clemens Pfister on 19/10/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
/*
 Deﬁnieren Sie eine Variable vom Typ Integer namens n. Weisen Sie dieser einen Wert zu und geben Sie alle Zahlen von n bis 1 aus.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    // Variable declaration //
    
    int n = 101; // Default value of n
    scanf("%d",&n); // Custom value of n
    
    // While loop //
    
    // While n >= 1
    while (n >= 1) {
        // Print number
        printf("%d\n",n);
        // Then subtract 1 of n (count from n to 1)
        n--;
        // Repeat
    }
    
    // Ending program execution //

    return EXIT_SUCCESS; // Execution ended
}
