// Hello World C Programm with comments
// (c) Clemens Pfister 16th October 2016

/* Header files start (#include <file.h>) */

#include <stdlib.h> // standard-library header file for the EXIT_SUCCESS statement.
#include <stdio.h> // standard-in-out header file for the printf statement.

/* Header files end (#include <file.h>) */

/* Program start */

/* The function called at program startup is named main.
It shall be defined with a return type of int and with no parameters. */

int main(void) {
	
    /* The printf statement allows me to print text 
    (in this case "Hello World!") to the console. "\n" adds a line break. */
    
    printf("Hello World!\n");
    
    /* The C programming language allows programs exiting or returning from the
    main function to signal success or failure by returning EXIT_SUCCESS or EXIT_FAILURE.
    On some systems these are equal to 0 and 1 respectively. */
    
	return EXIT_SUCCESS;
}

// Note: Semicolons must be placed to signal line completion.

/* Program end */
