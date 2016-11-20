/*
 * 4-pfister-a1.c
 * Created by Clemens Pfister on 09/11/2016.
 * https://git.io/vXWXq
 */

#include <stdio.h>
#include <stdlib.h>

 int main(void){

 	/* Variable declaration */
 	int n = 5;
 	printf("Please enter your number here: ");
 	scanf("%d", &n);

 	/* Will be used later for counting down as well */
 	int increment = 1;

 	/* Formatting */
 	printf("\n");
 	
 	/* First for loop – iterates from 1 to n 
	 * && i != 0 prevents infinite.
 	 */
 	for(int i = 1; i <= n && i != 0; i += increment){
 		/* Second for loop – iterates from 1 to i */
 		for(int j = 1; j <= i; j++){
 			/* Print numbers */
 			printf("%d ", j);
 		}
 		printf("\n");
 		/* if we hit the final iteration of i, 
 		 * set increment to -1 (count down)
 		 */
 		if(i == n){
 			increment = -1;
 		}
 	}
 	
 	printf("\n");
 	
 	return EXIT_SUCCESS;
 }

