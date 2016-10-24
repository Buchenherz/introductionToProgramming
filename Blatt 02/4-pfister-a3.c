//
//  a3.c
//  a1
//
//  Created by Clemens Pfister on 19/10/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
//
/*
    Deﬁnieren Sie eine Variable vom Typ Integer namens n. Weisen Sie dieser Variable einen Wert zu und geben Sie alle Zahlen von 1 bis n aus welche ohne Rest durch dreizehn teilbar sind.
 */


#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Variable declaration //

    int n = 100; // Default value of n
    scanf("%d",&n); // Custom value of n
    int i = 1; // Variable used for counting up
    
    // While loop //
    
    // Count from 1 to n
    while (i <= n) {
        
        // If statement //
        
        // If remainder of i / 13 = 0
        if (i % 13 == 0) {
            // Print i
            printf("%d\n", i);
        }
        // Add 1 to i
        i++;
    }

    // Ending program execution //

    return EXIT_SUCCESS;
}
