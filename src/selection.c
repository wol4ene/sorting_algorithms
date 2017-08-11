#include <stdio.h>
#include <stdlib.h>
#include "helper_funcs.h"

/**
 * Selection sort is an inplace comparison based algorithm that
 * maintains a sorted list which is built left->right, and the sublist
 * of items remaining to be sorted in the rest of the list.
 *
 * Example:    Begin     -->  5,4,1,8,2
 *                           |_________|
 *                             unsorted
 *
 *    Min=1, swap with 5 -->  1,4,5,8,2
 *                           |_|______|
 *                        sorted unsorted
 *
 *    Min=2, swap with 4 -->  1,2,5,8,4
 *                           |___|_____|
 *                        sorted  unsorted
 *
 *    Min=4, swap with 5 -->  1,2,4,8,5
 *                           |_____|___|
 *                          sorted  unsorted
 *  
 *    Min=5, swap with 8 -->  1,2,4,5,8
 *                           |_________|
 *                              sorted
 *
 * Best Case:  O(n^2)
 * Worse Case: O(n^2)
 */

void selectionSort(int *arr, int size)
{
    int i = 0, j = 0, minIdx = 0;

    for (i=0; i < size-1; i++) {
        printf("Pass %i:\t", i);
        dumpArray(arr, size);
        minIdx = i;   // need to start min at beginning of unsorted array each pass
        for (j = i+1; j < size; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        printf("Range [%i,%i] min=%i; swap with idx=%i\n",
                i, size-1, arr[minIdx], i);
        swap(&arr[i], &arr[minIdx]);
    }
}

void selectionSortNoPrints(int *arr, int size)
{
    int i = 0, j = 0, minIdx = 0;

    for (i=0; i < size-1; i++) {
        minIdx = i;   // need to start min at beginning of unsorted array each pass
        for (j = i+1; j < size; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(&arr[i], &arr[minIdx]);
    }
}

int testArr[3][5] = 
{
    {5,4,1,8,2},
    {1,2,3,4,5},
    {5,4,3,2,1},
};

int sizeTestArr = sizeof(testArr) / sizeof(testArr[0]);

int main(void) {
    int i = 0;
    for (i = 0; i < sizeTestArr; i++) {
        selectionSort(testArr[i], 5);
        printf("\nSorted Array:\t");
        dumpArray(testArr[i], 5);
    };
}
