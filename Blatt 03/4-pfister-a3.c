//
//  4-pfister-a3.c
//
//  Created by Clemens Pfister on 27/10/2016.
//
/* Schreiben Sie ein Programm welches die Fibonacci Zahlen 
 * kleiner n iterativ berechnet und ausgibt. 
 * Die Fibonacci Zahlen sind folgendermaßen deﬁniert: 
 * Die ersten beiden Zahlen sind 0 und 1. Die nächste Zahl 
 * ist jeweils die Summe der zwei vorangehenden Zahlen.
 * z.B. Für n = 10 soll die Ausgabe folgendermaßen aussehen: 
 * 0 1 1 2 3 5 8
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n = 10;
  scanf("%d", &n);
  int firstNumber = 0;
  int secondNumber = 1;
  int sum = firstNumber + secondNumber;

  printf("% d% d", firstNumber, secondNumber);

  while(sum < n){
      
    sum = firstNumber + secondNumber;
    firstNumber = sum;

    /* if sum is greater than the number given
     * prevent output */
    if(sum < n)
    printf("% d", firstNumber);

    sum = firstNumber + secondNumber;
    secondNumber = sum;
    
    /* if sum is greater than the number given
     * prevent output */
    if(sum < n)
    printf("% d", secondNumber);
    
  }
  /* Simple line break for formatting */
  printf("\n");

    return EXIT_SUCCESS;
}
