/*
//  4-pfister-a2.c
//
//  Created by Clemens Pfister on 27/10/2016.
//  https://git.io/vXWXq
*/
/* Schreiben Sie ein Programm in welchem die Variable
 * int n mit einem Wert > 1 initialisiert ist.
 * Geben Sie alle Zahlen zwischen 1 und n aus wobei abwechselnd
 * von Unten hinauf und von Oben herab gezählt werden soll.
 * z.B. Für n=10 soll die Ausgabe folgendermaßen aussehen: 1 10 2 9 3 8 4 7 5 6
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    /* Value of n (default = 10) */
    int n = 10;
    printf("Enter a number (will be count up and down): ");
    scanf("%d", &n);

    /* Counter */
    int i = 1;

    /* Value used for accurate counting of 
     * odd numbers */
    int m = 0;

    /* Set m for correct counting 
     * in while loop */
    if((n % 2) == 1){
    	m = (n/2) + 1;
    } else {
    	m = n/2;
    }

    /* Counts to n/2 if even and 
     * (n/2)+1 if odd */
    while((i <= m)) {
    	
        /* Print 1st number */
    	printf("% d \n", i);

    	/* To make odd numbers work 
         * exits scope before  
         * duplicates happen */
        if(i == m && (n%2 == 1)){
        	return EXIT_SUCCESS;	
        }

        /* Value of n-(i-1) (n-0, n-1, n-2) */
    	printf("% d \n", n-(i-1));

        i++;
    }
    return EXIT_SUCCESS;
}
