//
//  a4.c
//  a1
//
//  Created by Clemens Pfister on 19/10/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
//
/*
 Deﬁnieren Sie eine Variable vom Typ Integer namens n. Weisen Sie dieser Variable einen Wert zu und geben Sie jede vierte Zahl von 1 bis n aus ohne eine if-Bedingung zu verwenden.
 */


#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Variable declaration //
    
    int n = 100; // Default value of n
    scanf("%d",&n); // Custom value of n
    int i = 1; // Used for counting up
    
    // This while Loop goes through all numbers between i and n
    while (i <= n) {
        // This while Loop uses a condition to choose only those numbers,
        // that are divisible through 4
        while (i % 4 == 0) {
            // Print i
            printf("%d\n",i);
            i++;
        }
        i++;
    }
    
    // Ending program execution //
    
    return EXIT_SUCCESS;
}
