// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Input/Output samples in C language.
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include "../common/elsys.h"

int main(int argc, char const *argv[])
{
    char ch = 0;
    char sentence[512] = { 0 };
    scanf( "%511[^.!?]%c", sentence, &ch );

    printf("\nsentence: \"%s\"\n", sentence);
    printf("\nch: %c\n", ch);

    char* line = NULL;

    scanf("%*[^\n]*%c", line);

    printf("\nline: %s\n", line);

    return 0;
}
