//
//  4-pfister-a5.c
//
//  Created by Clemens Pfister on 31/10/2016.
//
/* 
 * Lesen Sie vom Benutzer drei Fließkommazahlen 
 * mittels scanf ein und geben Sie die größte 
 * und kleinste dieser Zahlen auf dem Bildschirm
 * aus.
 */

#include <stdlib.h>
#include <stdio.h>

int main(void) {

	float firstNumber = 0.0;
	float secondNumber = 0.0;
	float thirdNumber = 0.0;

	printf("Enter number 1: ");
	scanf("%f", &firstNumber);
	printf("Enter number 2: ");
	scanf("%f", &secondNumber);
	printf("Enter number 3: ");
	scanf("%f", &thirdNumber);

	printf("\n");

	/* Checks for greatest number */
	printf("The greatest number you entered is: ");
	if(firstNumber >= secondNumber && firstNumber >= thirdNumber){
		printf("%f\n", firstNumber);
	} else if(secondNumber >= firstNumber && secondNumber >= thirdNumber){
		printf("%f\n", secondNumber);
	} else if(thirdNumber >= firstNumber && thirdNumber >= secondNumber){
		printf("%f\n", thirdNumber);
	}

	/* Checks for smallest number */
	printf("The smallest number you entered is: ");
	if(firstNumber <= secondNumber && firstNumber <= thirdNumber){
		printf("%f\n", firstNumber);
	} else if(secondNumber <= firstNumber && secondNumber <= thirdNumber){
		printf("%f\n", secondNumber);
	} else if(thirdNumber <= firstNumber && thirdNumber <= secondNumber){
		printf("%f\n", thirdNumber);
	} 

    return EXIT_SUCCESS;
    
}
