//
//  4-pfister-a4.c
//
//  Created by Clemens Pfister on 31/10/2016.
//
/* 
 * Geben Sie den Inhalt der Variablen a, b, c, d und e korrekt
 * auf der Konsole aus
 * Geben Sie c als Hexadezimalzahl aus
 * Geben Sie a in Exponentialschreibweise aus 
 * Geben Sie b mit 10 Nachkommastellen aus. Fällt Ihnen hierbei etwas auf?
 * Geben Sie c als Integer mit drei Stellen (evtl. führende
 * Nullen) aus
 * Erklären Sie die Lebensdauer der variable sd.
 * Welchen Wert erwarten Sie für die Variable zero?
 */

#include <stdlib.h>
#include <stdio.h>

int main(void) {
    double a = 1.23e14;
    float b = 0.034;
    char c = 'X';
    unsigned int d = 3147483647;
    long e = 31474836472;
    { int sd = 232; }
    int zero;
    
    /* TODO print variables */

    /* Out: 58 */
    printf("%X\n", c);

    /* Out: 1.230000E+14 */
    printf("%E\n", a);

    /* 0.034 with ten decimal places is
     * more accurate than 0.34
     * Out: 0.0340000018 
     */
    printf("%.10f\n",b);

    /* Ausgabe: 088 */
    printf("%0.3d\n", c);

    /* printf("%d",sd); 
     * Does not work, because var 'sd'
     * is only accessible within the
     * braces it has been declared 
     */

    /* According to naming conventions,
     * this variable should have the value
     * 0 
     */
    printf("%d\n",zero);

    
    return EXIT_SUCCESS;
    
}
