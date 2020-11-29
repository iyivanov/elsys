// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// This is a sample programme that shows different data types 
// of C programming langueage.
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


#include <stdio.h>

#include "../common/elsys.h"

signed char sc ;
unsigned char uc = 200;
char ch = (char) 65;
char alpha = 'A';
char *text = "The big borwn fox jumps over the lazy dog";

signed short ss = 1024;
unsigned short us = 1024;

signed int si = 10241024;
unsigned int ui = 10241024;

signed long sl = 10241024;
unsigned long ul = 10241024;

float f = 1.23456f;
double d = 1.234556;

#define SIZES_LEN 10
int sizes[SIZES_LEN] = { 
    sizeof(sc), 
    sizeof(unsigned char), 
    sizeof(us), 
    sizeof(ss), 
    sizeof(ui), 
    sizeof(si), 
    sizeof(text), 
    sizeof(float), 
    sizeof(long*) };

void main() {

    printf("These are some og the C lang data types");
    PRINT_NEW_LINE;

    printf("sc = %d", sc);
    PRINT_NEW_LINE;

    printf("uc = %d", uc);
    PRINT_NEW_LINE;

    printf("ch = %d; as char - %c", ch, ch);
    PRINT_NEW_LINE;

    if (ch == alpha) {
        printf("ch and alpha are the same");
    } else {
        printf("ch and alpha are NOT the same");
    }
    PRINT_NEW_LINE;

    printf("string = %s", text);
    PRINT_NEW_LINE;

    printf("ss = %d", ss);
    PRINT_NEW_LINE;

    printf("us = %d", us);
    PRINT_NEW_LINE;

    printf("si = %d", si);
    PRINT_NEW_LINE;

    printf("ui = %d", ui);
    PRINT_NEW_LINE;

    printf("sl = %d", sl);
    PRINT_NEW_LINE;

    printf("ul = %d", ul);
    PRINT_NEW_LINE;

    printf("f = %5.3f", f);
    PRINT_NEW_LINE;

    printf("d = %5.3f", d);
    PRINT_NEW_LINE;

    sizes[SIZES_LEN - 1] = sizeof(sizes);

    for (int i = 0; i < SIZES_LEN; i++) {
        printf("sizes[%d] = %d", i, sizes[i]);
        PRINT_NEW_LINE;
    }
}