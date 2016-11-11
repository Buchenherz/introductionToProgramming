/*
 * 4-pfister-a2.c
 * Created by Clemens Pfister on 11/11/2016.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int n = 0;
    printf("Enter your number here: ");
    scanf("%d", &n);
    
    int x, y, z = 0;
    printf("x, y, z\n");
    
    for(x = 0; x <= n; x++){
        
        for(y = 0; y < x; y++){
            if(y == x){
                continue;
            }
            for(z = 0; z < y; z++){
                if(z == y){
                    continue;
                }
                printf("%d, %d, %d\n", x, y, z);
                
            }
        }
    }
    
    return EXIT_SUCCESS;
}

