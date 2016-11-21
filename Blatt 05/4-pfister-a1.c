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

int rng(void){
    srand(time(NULL));
    int a = (rand() % 100) + 1;
    printf("%d\n", a);
    return a;
}


int smallest_distance(int a, int b, int c, int num){
    
    printf("The smallest distance is: ");
    
    /* Calculate distances abs() makes value positive if negative */
    int dist_a = abs(num - a);
    int dist_b = abs(num - b);
    int dist_c = abs(num - c);
    
    /* Checks for smallest distance between num and a, b, c */
    if(dist_a <= dist_b && dist_a <= dist_c){
        printf("%d\n", dist_a);
    } else if(dist_b <= dist_a && dist_b <= dist_c){
        printf("%d\n", dist_b);
    } else if(dist_c <= dist_a && dist_c <= dist_b){
        printf("%d\n", dist_c);
    }
    
    return EXIT_SUCCESS;
}

int main() {
    /* Get a random number */
    int num = rng();
    
    /* While loop that runs until function exit condition is met */
    while(1 == 1){
        
        /* Variable declaration */
        int a, b, c = 0;
        printf("Please enter your first number: ");
        scanf("%d", &a);
        printf("Please enter your second number: ");
        scanf("%d", &b);
        printf("Please enter your third number: ");
        scanf("%d", &c);
        
        /* Check number vs a, b, c */
        if(a == num || b == num || c == num){
            printf("Congratulations, the correct number was: %d\n", num);
            return EXIT_SUCCESS;
        } else if ((a > num && b > num) || (a > num && c > num) || (b > num && c > num)) {
            printf("The numbers you choose were for the most part greater than wanted!\n");
            smallest_distance(a, b, c, num);
        } else if ((a < num && b < num) || (a < num && c < num) || (b < num && c < num)) {
            printf("The numbers you choose were for the most part smaller than wanted!\n");
            smallest_distance(a, b, c, num);
        } else {
            /* FIXME: Get equal far away to work */
            printf("The numbers you choose are equally far away than wanted!\n");
            smallest_distance(a, b, c, num);
        }
    }
}
