// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Pointers cheat sheet in C programming language
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tip: fix the header
void swap(int *x, int *y)
{
// swap the values of a and b so that when
    int c;
    c=*x;
    *x=*y;
    *y=c;
// the function returns the caller gets its variables swapped
}

int main(int argc, char const *argv[])
{
    int x = 6;
    int y = 9;

    swap(&x, &y);

    printf("\nx= %d\ny=%d\n", x, y);
    if (x == 6 && y == 9)
    {
        printf("... failed\n");
    }
    else
    {
        printf("BINGO!");
    }

    return 0;
}