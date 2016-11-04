/*
//  4-pfister-a5.c
//
//  Created by Clemens Pfister on 31/10/2016.
*/
/* 
 * Deﬁnieren sie eine Aufzählungskonstante (enum) welche 
 * verwendet werden kann um zu speichern ob sich ein Student 
 * im Bachelor–, Master– oder PhD– Studium beﬁndet.
 * 
 * Legen Sie eine Variable dieses Typs an und geben Sie 
 * je nach Inhalt dieser Variablen aus: 
 * “Der Student beﬁndet sich im Bachelor Studium”, 
 * “Der Student beﬁndet sich im Master Studium” oder 
 * “Der Student beﬁndet sich im PhD Studium”.
 */

#include <stdlib.h>
#include <stdio.h>

int main(void) {
   
    enum studentType {Bachelor = 0, Master, PhD};
    
    /* enum studentType student = Master; */
    /* enum studentType student = PhD; */
    enum studentType student = Bachelor;

    if(student == Bachelor){
        printf("Der Student beﬁndet sich im Bachelor Studium.\n");
    } else if (student == Master){
        printf("Der Student beﬁndet sich im Master Studium.\n");
    } else if (student == PhD){
        printf("Der Student beﬁndet sich im PhD Studium.\n");
    }
    
    return EXIT_SUCCESS;
    
}
