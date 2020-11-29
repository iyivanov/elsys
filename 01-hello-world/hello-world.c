// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// This is a sample programme written in C programming langueage.
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

//
//  try compiling as
//  gcc -E hello-world.c > hello-world-preprocessed.c
//  gcc -S hello-world.c -o hello-world-preprocessed.asm
//
#define PRINT_NEW_LINE printf("\n")

#include <stdio.h>

int main() {
    printf("Hello World!");

    PRINT_NEW_LINE;

    PRINT_NEW_LINE;

    return 0;
}
