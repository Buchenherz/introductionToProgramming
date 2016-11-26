//
//  main.c
//  4-pfister-a1
//
//  Created by Clemens Pfister on 26/11/2016.
//  Copyright © 2016 Clemens Pfister. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b);
int mult(int a, int b);
int factorial(int a);

int main(void) {
    
    /* Enter some numbers */
    int a, b, c = 0;
    printf("Enter a: "); scanf("%d", &a);
    printf("Enter b: "); scanf("%d", &b);
    printf("Enter c (factorial): "); scanf("%d", &c);
    
    int i = sum(a, b);
    printf("%d\n", i);
    
    int j = mult(a, b);
    printf("%d\n", j);
    
    int k = factorial(c);
    printf("%d\n", k);

}

int sum(int a, int b){
    if (b > 0){
        /* Increment a before rec function call! */
        return sum(++a, b - 1);
    } else {
        return a;
    }
}

int mult(int a, int b){
    if (b > 0){
        /* add a to every instance while true */
        return a + mult(a, b - 1);
    } else {
        return 0;
    }
}

int factorial(int a){
    if (a > 0) {
        return a * factorial(a - 1);
    } else {
        /* 0! is defined as 1 */
        return 1;
    }
}
