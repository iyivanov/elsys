// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// String manipulation sample in C language
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <stdio.h>

#include "../common/elsys.h"

// Calculates the length of the given string
int str_len(const char *str)
{
    int len = 0;
    if (str != NULL) {
        for (const char *c = str; *c != 0; c++)
        {
            len++;
        }
    }
    return len;
}

// Compares the two strings, case-sensitive
// returns the index of the first character that is different
// returns 0 if they are the same
// returns 1 if str1 is NULL and str2 is not, or vice versa
int str_cmp(char *str1, char *str2)
{
    if ((str1 == NULL && str2 != NULL) || (str1 != NULL && str2 == NULL))
    {
        return 1;
    }

    int len1 = str_len(str1);
    int len2 = str_len(str2);
    int minlen = len1 < len2 ? len1 : len2;

    int index = 0;

    for (; index < minlen; index++)
    {
        if (str1[index] != str2[index]) 
        {
            break;
        }
    }

    if (index == len1 && index == len2)
    {
        return 0;
    }

    return index + 1;
}

// Calculates the length of the given string
bool is_empty_str(char *str)
{
    if (str == NULL || *str == 0 || str[0] == '\0') 
    {
        return true;
    }
    return false;
}

// Checks if the str has only alpha-nummeric characer and space (code 32).
int is_alpha_nummeric(char *str)
{
    char *c = str;
    while (*c != 0) 
    {
        if (*c < 'a' && *c > 'z' && *c < '0' && *c > '9' && *c != ' ')
        {
            return 0;
        }
        c++;
    }

    return 1;
}

//
// ENTRY POINT
//
int main(int argc, char const *argv[])
{

    char string[256] = "big brown fox jumps over the lazy dog";

    printf("\nstring is: %s\n", string);

    string[0] = 0;
    printf("\nstring is: %s\n", string);

    string[0] = '\0';
    printf("\nstring is: %s\n", string);

    string[0] = 'w'; string[1] = 'e'; string[2] = 'e';
    printf("\nstring is: %s\n", string);

    printf("\ncompare strings 'lorem' =?= 'lorum' : %d\n", 
        str_cmp("lorem", "lorum"));

    printf("\ncompare strings 'abcde' =?= 'ABCDE' : %d\n", 
        str_cmp("abcde", "ABCDE"));

    printf("\ncompare strings 'red fox' =?= 'red fox' : %d\n", 
        str_cmp("red fox", "red fox"));

    printf("\ncompare strings 'lorem' =?= NULL : %d\n", 
        str_cmp("lorem", NULL));

    return 0;
}
