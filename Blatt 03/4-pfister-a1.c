//
//  4-pfister-a1.c
//
//  Created by Clemens Pfister on 27/10/2016.
//
/* Schreiben Sie ein Programm in welchem die Variable
 * int n mit einem Wert > 1 initialisiert ist.
 * Geben Sie alle Zahlen zwischen 1 und n aus wobei abwechselnd
 * von Unten hinauf und von Oben herab gezählt werden soll.
 * z.B. Für n=10 soll die Ausgabe folgendermaßen aussehen: 1 10 2 9 3 8 4 7 5 6
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int n = 10;
    scanf("%d", &n);
    int i = 1;
    int iMinus1 = 0;
    int m = 0;

    if((n % 2) == 1){
    	m = (n/2) + 1;
    } else {
    	m = n/2;
    }

    while((i <= m)) {
    	
    	iMinus1 = i - 1;
    	
    	printf("% d \n", i);
    	if(i == m && (n%2 == 1)){
        	return EXIT_SUCCESS;	
        }
    	printf("% d \n", n-iMinus1);

    	// printf("n: %d\n", n);
    	// printf("iMinus1: %d\n", iMinus1);
    	// printf("i: %d\n", i);

        i++;
    }
    return EXIT_SUCCESS;
}
