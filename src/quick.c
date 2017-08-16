#include <stdio.h>
#include <stdlib.h>
#include "helper_funcs.h"

/**
 * Quicksort is an in-place recursive divide-and-conquer sorting algorithm.
 *
 * It works by choosing a pivot. This could be chosen several ways, but in
 * this tutorial, we will simply use the right-most element of the array.
 * Then, we rearrange elemnts such that those less than the pivot go in the left
 * side of the array, and those greater than the pivot go in the right side, then
 * finally plop the pivot into place.
 * Finally, we sort the sub arrays to the left and right of the pivot.
 *
 * Best Case:   O(n*log(n))
 * Worse Case:  O(n^2)
 */

/**
 * Parition function in quick sort
 *
 * Select pivot as right-most element, then setup left and right marker
 * While markers haven't crossed
 *    Advance left marker looking for element greater than pivot
 *    Decrement right marker looking for element less than pivot
 *    If the markers haven't crossed - swap the elements
 * Now that markers have crossed, swap the pivot with the left marker
 */
int partition(int arr[], int l, int r)
{
    int pivot = arr[r]; // choose pivot as right most element
    int i = l;          // set left marker to left most element
    int j = r - 1;      // set right marker to one left of pivot

    while (i <= j) {
        while (arr[i] < pivot) {  // can never walk off this end of arr
            i++;                  // since pivot is the right most element
        }
        while (arr[j] > pivot && j >= l) {  // guard against walking off lower end of array
            j--;
        }
        if (i < j) {
            swap(&arr[i++], &arr[j++]);
        }
    }

    swap(&arr[i], &arr[r]);
    return i;
}

/**
 * Recursive portion of quicksort
 * Find the pivot point
 * Recursively call with sub array to left and right of pivot point 
 */
void _quickSort(int arr[], int l, int r) 
{
    if (l >= r) {
        return;
    }
    int piv = partition(arr, l, r);
    _quickSort(arr, l, piv - 1);
    _quickSort(arr, piv + 1, r);
}

void quickSort(int arr[], int size)
{
    _quickSort(arr, 0, size - 1);
}

int main(void) {
    int arr1[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    int arr2[] = {1,  6,   3,  8,  5,  7,  2,  9,  4};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    printf("\nUnsorted Array:\t");
    dumpArray(arr1, size);
    quickSort(arr1, size);
    printf("\nSorted Array:\t");
    dumpArray(arr1, size);

    printf("\nUnsorted Array:\t");
    dumpArray(arr2, size);
    quickSort(arr2, size);
    printf("\nSorted Array:\t");
    dumpArray(arr2, size);
}

