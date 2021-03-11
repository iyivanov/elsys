#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void print_array(int *array, int size)
{
    printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");
    for(int i=0; i<size; i++)
    {
        printf("array[%d] = %d\n",i, array[i]);
    }
    printf("--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--\n");
}

void swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void pyramid_sort(int *array, int size)
{
    for (int i = size / 2; i >= 0 ; i--)
    {
        if (i * 2 + 1 < size)
        {
            if (array[i * 2] > array[i * 2 + 1])
            {
                swap(&array[i * 2], &array[i * 2 + 1]);
            }
        }
        if (i * 2 < size)
        {
            if (array[i] > array[i * 2]) 
            {
                swap(&array[i], &array[i * 2]);
            }
        }
    }
}

int main(){

    int array[] = {100,10,80,30,90,20,50,40,70,60};

    int length = sizeof(array) / sizeof(array[0]);
    printf("\narray size: %d\n", length);

    print_array(array, length);

    pyramid_sort(array, length);

    print_array(array, length);
}