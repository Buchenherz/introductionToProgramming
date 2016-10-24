//
//  ai.c
//
//  Copyright © 2016 Clemens Pfister 19/10/2016.
//
/* Deﬁnieren Sie eine Variable vom Typ Integer namens n.
   Weisen Sie der Variable einen Wert zu. Prüfen Sie ob 
   der Wert n ohne Rest durch dreizehn teilbar ist gib 
   “Der gegebene Wert ist durch dreizehn teilbar” aus. 
   Andernfalls geben Sie “Der gegebene Wert ist nicht 
   durch dreizehn teilbar” aus.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    // Variable declaration //
    
    int n = 100; // Default value of n
    // scanf("%d",&n); // Custom value of n
    
    // Simple if else statement //
    
    if (n % 13 == 0) { // Checks if remainder of n / 13 equals 0
        printf("Der gegebene Wert ist durch dreizehn teilbar.\n"); // Prints this if true
    } else { // If remainder of n / 13 isn't 0
        printf("Der gegebene Wert ist NICHT durch dreizehn teilbar.\n"); // Prints this
    }
    
    // Ending program execution //
    
    return EXIT_SUCCESS;
}


