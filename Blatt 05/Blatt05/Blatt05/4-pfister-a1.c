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

int get_random_num(void){
    srand(time(NULL));
    int a = (rand() % 100) + 1;
    printf("%d\n", a);
    return a;
}

int main() {
    
    int num = get_random_num();
    
    int a, b, c = 0;
    printf("Please enter your first number: ");
    scanf("%d", &a);
    printf("Please enter your second number: ");
    scanf("%d", &b);
    printf("Please enter your third number: ");
    scanf("%d", &c);
    
    if(a == num || b == num || c == num){
        printf("Congratulations, the correct number was: %d\n", num);
        return EXIT_SUCCESS;
    }
    
    
}
