//
//  main.c
//  4-pfister-a5
//
//  Created by Clemens Pfister on 14/11/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
//

#include <stdio.h> 
#include <stdlib.h>

int main(void) {
    
    int n;
    scanf("%d", &n);
    switch (n) {
        
        case 0: printf("A"); printf("B");
            
        case 1: printf("C");
            
        case 2: printf("D"); break;
            
        case 3: printf("E"); break;
            
        case 4: printf("F");
            
        default: printf("G");
            
    }
    
    printf("\n");
    
    return EXIT_SUCCESS;
    
}
