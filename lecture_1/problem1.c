// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Quadratic function in C programming language
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <stdio.h>

#include "../common/elsys.h"

int get_elem(int *i_arr, int i_index );
void put_elem(int *i_arr, int i_index, int i_value );

int main() {
    printf("Function that accepts an array and index and returns the value at that possition. Index is always between 0 and 9.");
    PRINT_NEW_LINE;

    int i_array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int i_ndx = 4;

    int i_result = get_elem(i_array, i_ndx);

    printf("value at %d is %d", i_ndx, i_result);
    PRINT_NEW_LINE;

    put_elem(i_array, i_ndx, 67);
    i_result = get_elem(i_array, i_ndx);

    printf("value at %d is %d", i_ndx, i_result);
    PRINT_NEW_LINE;
    PRINT_NEW_LINE;
}

int get_elem(int *i_arr, int i_index ) {
    if (i_arr == 0 || i_index < 0 || i_index > 9)
    {
        return -1;
    } 

    return i_arr[i_index];
}

void put_elem(int *i_arr, int i_index, int i_value ) {
    if (i_arr != 0 && i_index >= 0 && i_index < 10)
    {
        i_arr[i_index] = i_value;
    } 
}
