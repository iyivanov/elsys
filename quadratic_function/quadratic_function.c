// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Quadratic function in C programming language
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

/*

D = sqrt( b*b - 4 * a * b)
x1 = (- b + D) / (2 * a)
x1 = (- b - D) / (2 * a)

*/

#include <stdio.h>

#include "../common/elsys.h"

float quadratic(float a, float b, float c);

int main() {

    printf("Welcome to Quadratic Function");
    PRINT_NEW_LINE;

    float a = 4;
    float b = 2;
    float c = -5;

    printf("a = %.2f; b = %.2f; c = %.2f", a, b, c);
    PRINT_NEW_LINE;

    PRINT_NEW_LINE;
    return 0;
}