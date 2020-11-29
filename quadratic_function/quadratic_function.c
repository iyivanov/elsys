// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Quadratic function in C programming language
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

/*

a*x^2 + b*x + c = 0

c = -5
x^2 + x + (-5) = 0

D = sqrt( b*b - 4 * a * c)
x1 = (- b + D) / (2 * a)
x1 = (- b - D) / (2 * a)

*/

#include <stdio.h>
#include <math.h>

#include "../common/elsys.h"

float quadratic(float a, float b, float c);

int main() {

    printf("Welcome to Quadratic Function");
    PRINT_NEW_LINE;

    float a = 4;
    float b = 0;
    float c = -5;

    float d;
    float x1, x2;

    printf("a = %.2f; b = %.2f; c = %.2f", a, b, c);
    PRINT_NEW_LINE;

    if (a == 0) {
        x1 = x2 = -c / b;
    } else if (b == 0) {
        x1 = x2 = sqrt(-c / a);
    } else {

        if (a == 0 || c == 0) {
            d = b;
        } else {
        // if (a != 0 && c != 0) {
            d = sqrt(b * b - 4 * a * c);
        }

        printf("d = %.2f", d);
        PRINT_NEW_LINE;

        if (d < 0) {
            printf("no real solution");
            PRINT_NEW_LINE;
            return 1;
        }

        if (d == 0) {
            x1 = x2 = -b / (2 * a);
        } else {
            x1 = (-b + d) / (2 * a);
            x2 = (-b - d) / (2 * a);
        }


    }

    printf("x1 = %.2f", x1);
    PRINT_NEW_LINE;
    printf("x2 = %.2f", x2);
    PRINT_NEW_LINE;
 
    PRINT_NEW_LINE;
    return 0;
}