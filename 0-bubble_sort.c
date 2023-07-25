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
 * bubble_sort - sorts an array of ints in ascending order using bubble sort
 * @array: array of ints being sorted
 * @size: size of array
 *
 * Description: The arrray is printed after each time elements are swapped
 */
void bubble_sort(int *array, size_t size)
{
    size_t i;
    size_t len = size;
    bool sort_ = false;

    if (array == NULL || size < 2)
        return;

    while (sort_ == false)
    {
        sort_ = true;
        for (i = 0; i < len - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap_func(array + i, array + i + 1);
                print_array(array, size);
                sort_ = false;
            }
        }
        len--;
    }
}
