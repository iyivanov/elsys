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

int partition(int *array, int low, int high)
{
    int pi = (high+low)/2;
    int i=low;
    while (i<pi)
    {
        if (array[i] > array[pi])
        {
            int tmp = array[i];
            for (int k = i; k < pi; k++)
            {
                array[k] = array[k+1];
            }
            array[pi] = tmp;
            pi--;
        } else {
            i++;
        }
    }
    i = pi + 1;
    while (i <= high)
    {
        if (array[i] < array[pi])
        {
            int tmp = array[i];
            for (int k = i; k > pi; k--)
            {
                array[k] = array[k-1];
            }
            array[pi] = tmp;
            pi++;
        } else {
            i++;
        }
    }
    return pi;
}

void swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int quick_partition(int *array, int low, int high)
{
    int pivot = high;
    int index = 0;
    for (int i = 0; i < pivot; i++)
    {
        if (array[i] < array[pivot]) 
        {
            if (i != index)
            {
                swap(&array[i], &array[index]);
            }
            index++;
        }
    }
    swap(&array[pivot], &array[index]);
    return index;
}

void quick_sort(int *array, int low, int high)
{
    if(low < high)
    {
        int pi = quick_partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

int main(){

    int array[] = {100,10,80,30,90,20,50,40,70,60};

    int length = sizeof(array) / sizeof(array[0]);
    printf("\narray size: %d\n", length);

    print_array(array, length);

    quick_sort(array, 0, length - 1);

    print_array(array, length);
}