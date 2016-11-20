/*
 * 4-pfister-a2.c
 * Created by Clemens Pfister on 11/11/2016.
 * https://git.io/vXWXq
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    /* Variable declaration */
    int n = 0;
    printf("Enter your number here: ");
    scanf("%d", &n);
    
    /* Formatting */
    printf("x, y, z\n");
    
    /* For loop 1 to 3 */
    for(int x = 0; x <= n; x++){
        /* Major mistake: instead of y <= n initially y <= x 
         * --> A lot of solutions left out */
        for(int y = 0; y <= n; y++){
            for(int z = 0; z <= n; z++){
                /* These loops iterator over every triple between
                 * 0 and n.
                 * This if clause allows me to discard every unwanted
                 * solution */
                if(x != y && x != z && z != y)
                printf("%d, %d, %d\n", x, y, z);
            }
        }
    }
    return EXIT_SUCCESS;
}