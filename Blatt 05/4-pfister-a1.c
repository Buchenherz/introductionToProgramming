//
//  main.c
//  Blatt05
//
//  Created by Clemens Pfister on 18/11/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int rng();
int smallest_distance(int a, int b, int c, int num);

int main() {
    /* Get a random number */
    printf("/*=======================================\n");
    printf("=           The guessing game:          =\n");
    printf("=   The computer will choose a random   =\n");
    printf("=       number between 1 and 100.       =\n");
    printf("=     And you have to figure it out!    =\n");
    printf("=======================================*/\n");

    int num = rng();
    
    /* While loop that runs until function exit condition is met */
    while(1 == 1){
        
        /* Variable declaration */
        int a, b, c = 0;
        printf("Guess 1 of 3: ");
        scanf("%d", &a);
        printf("Guess 2 of 3: ");
        scanf("%d", &b);
        printf("Guess 3 of 3: ");
        scanf("%d", &c);
        printf("\n");
        
        /* Calculate distances abs() makes value positive if negative 
         * DRY!! */
        int dist_a = abs(num - a);
        int dist_b = abs(num - b);
        int dist_c = abs(num - c);
        int distance = smallest_distance(a, b, c, num);
        
        /* Check number vs distances of a, b, c */
        
        /* If correct number was chosen */
        if(a == num || b == num || c == num){
            printf("=========================================\n");
            printf("=            Congratulation!:           =\n");
            printf("=   You guessed the right number (%d)   =\n", num);
            printf("=========================================\n");
            return EXIT_SUCCESS;
        }
        /* If entered numbers were equally far away (using distances) */
        else if ((dist_a == dist_b)||(dist_b == dist_a)||(dist_c == dist_a) || (dist_c == dist_b)){
            printf("-----------------------------------------\n");
            printf("=               Try again!              =\n");
            printf("=   The numbers you chose were mostly   =\n");
            printf("=   equally far away from secret num!   =\n");
            printf("-----------------------------------------\n");
            printf(" The smallest distance to secret is: %d  \n", distance);
        }
        /* Are 2 of entered numbers greater than rng? */
        else if ((a > num && b > num) || (a > num && c > num) || (b > num && c > num)) {
            printf("-----------------------------------------\n");
            printf("=               Try again!              =\n");
            printf("=   The numbers you chose were mostly   =\n");
            printf("=       greater than secret num!        =\n");
            printf("-----------------------------------------\n");
            printf(" The smallest distance to secret is: %d  \n", distance);
        }
        /* Are 2 of entered numbers smaller than rng? */
        else if ((a < num && b < num) || (a < num && c < num) || (b < num && c < num)) {
            printf("-----------------------------------------\n");
            printf("=               Try again!              =\n");
            printf("=   The numbers you chose were mostly   =\n");
            printf("=       smaller than secret num!        =\n");
            printf("-----------------------------------------\n");
            printf(" The smallest distance to secret is: %d  \n", distance);
        }
        printf("\n");
    }
}


/* Generates a random integer between 1 and 100 */
int rng(){
    srand(time(NULL));
    int a = (rand() % 100) + 1;
    
    /* For testing purposes */
    /* printf("%d\n", a); */
    return a;
}


int smallest_distance(int a, int b, int c, int num){
    
    /* Calculate distances abs() makes value positive if negative
     * Not perfect because same declaration further down */
    int dist_a = abs(num - a);
    int dist_b = abs(num - b);
    int dist_c = abs(num - c);
    int distance = 0;
    
    /* Checks for smallest distance between num and a, b, c */
    if(dist_a <= dist_b && dist_a <= dist_c){
        return distance = dist_a;
    } else if(dist_b <= dist_a && dist_b <= dist_c){
        return distance = dist_b;
    } else if(dist_c <= dist_a && dist_c <= dist_b){
        return distance = dist_c;
    }
    
    return EXIT_SUCCESS;
}
