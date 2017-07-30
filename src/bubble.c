#include <stdio.h>
#include <stdlib.h>
#include "helper_funcs.h"

/**
 * Bubble sort is a comparison based algorithm that compares each 
 * pair of elements in an array and swaps them if they are out of 
 * order until the entire array is sorted.
 *
 * Best Case:  O(n) 
 * Worse Case: O(n^2)
 *
 * A couple notes that improve run-time a bit:
 * 1) The list could become sorted before fully running through the algorithm.
 *    We keep a bool 'swapped' to determine if a pass has not swapped
 *    anything, and if so, break early
 * 2) On each pass, the highest number bubbles up to its final resting place.
 *    Thus, on subsequent passes, we don't need to compare the number that reach
 *    its final resting place in the previous pass.  This explains the
 *    'size-1-i' on the inner loop - we just run through the remaining unsorted
 *    portion of the list
 */

void bubbleSort(int *arr, int size)
{
    bool swapped = FALSE;
    int i = 0, j = 0;

    for (i=0; i < size-1; i++) {
        printf("\nPass %i:\t", i);
        dumpArray(arr, size);
        for (j = 0; j < size-1-i; j++) {
            printf("Considering %i,%i: ", arr[j], arr[j+1]);
            if(arr[j] > arr[j+1]) {
                printf("swapping -> ");
                swap(&arr[j], &arr[j+1]);
                swapped = TRUE;
                dumpArray(arr, size);
            } else {
                printf("no swap\n");
            }
        }
        if (FALSE == swapped) {
            printf("Fully sorted, breaking early\n");
            break;
        }
    }
}

void bubbleSortNoPrints(int *arr, int size)
{
    bool swapped = FALSE;
    int i = 0, j = 0;

    for (i=0; i < size-1; i++) {
        for (j = 0; j < size-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = TRUE;
            }
        }
        if (FALSE == swapped) {
            break;
        }
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
        bubbleSort(testArr[i], 5);
    };
}
