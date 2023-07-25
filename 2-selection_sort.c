#include "sort.h"

/**
 * swap_func - swaps two integers
 * @a: 1st int to swap
 * @b: 2nd int to swap
 */

void swap_func(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * selection_sort - sorts an array of ints using selection sort
 * @array: pointer to the array of ints to be sorted
 * @size:  size of the array
 *
 * Description: print the array after each time you swap two elements
 */
void selection_sort(int *array, size_t size)
{
    int *index;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        index = array + i;
        for (j = i + 1; j < size; j++)
            index = (array[j] < *index) ? (array + j) : index;

        if ((array + i) != index)
        {
            swap_func(array + i, index);
            print_array(array, size);
        }
    }
}
