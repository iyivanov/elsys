// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Kodirane na tekst
// Avtor: 
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void crypt_string(char *str) 
{
    if (str != NULL)
    {
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            switch (str[i])
            {
                case ' ':
                    break;
                case 'X':
                    str[i] = 'A';
                    break;
                case 'x':
                    str[i] = 'a';
                    break;
                case 'y':
                    str[i] = 'b';
                    break;
                case 'Y':
                    str[i] = 'B';
                    break;
                case 'z':
                    str[i] = 'c';
                    break;
                case 'Z':
                    str[i] = 'C';
                    break;
                default:
                    str[i] = ((int) str[i]) + 3;
                    break;
            }
        }
    }
}


int main(int argc, const char *argv[])
{
    char *str;
    if (argc > 1)
    {
        str = (char*) malloc(strlen(argv[1]) + 1);
        strcpy(str, argv[1]);
    } 
    else
    {
        const char * text = "the big brown fox jumps over lazy dog";
        str = (char*) malloc(strlen(text) + 1);
        strcpy(str, text);
    }

    printf("nekodiran: %s\n", str);
    crypt_string(str);
    printf("--- kodiran: %s\n", str);

    free(str);

    return 0;
}
