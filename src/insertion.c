#include <stdio.h>
#include <stdlib.h>
#include "helper_funcs.h"

/**
 * Insertion sort is a comparison based algorithm that builds a sorted list
 * by consuming one element at a time from the unsorted list and inserting
 * it into the appropriate place in the sorted list.
 *
 * We walk the unsorted array, and for each element, or 'key', begin comparing
 * leftward.  If the key is < previous element, slide prev elem forward.
 * Finally once we reach an elem where key is > the elem, insert key at this spot + 1
 *
 * Begin    5, 4, 1, 8, 2 --> start with 4, is < 5, slide 5 forward, insert 4
 *          4, 5, 1, 8, 2 --> start with 1, is < 5, slide 5 forward, 1 < 4, slide 4 forward, insert 1
 *          1, 4, 5, 8, 2 --> start with 8, is > 5, simply insert 8 where it is
 *          1, 4, 5, 8, 2 --> start with 2, is < 8, slide 8 forward, 2 < 5, etc etc
 *
 * Best Case:  O(n)
 * Worse Case: O(n^2)
 */

void insertionSort(int *arr, int size)
{
    int i = 0;    // index for which we are trying to insert
    int key = 0;  // value of index we are trying to insert
    int prev = 0; // prev idx to compare key to as we walk backwards
    
    for (i=1; i < size; i++) {  // start at 1, node0 starts as 'sorted' already
        printf("Pass %i, key %i:\t", i, arr[i]);
        dumpArray(arr, size);

        key = arr[i];   // save the key for later use
        prev = i - 1;   // init prev to be one prior slot

        /* walk backwards, sliding elems that are >key forward */
        while (prev >= 0 && key < arr[prev]) {
            arr[prev+1] = arr[prev];    // slide prev elem forward
            prev--;                     // walk back to next elem
        }
        
        /* finally - dump key into final resting place */
        arr[prev+1] = key;
    }
}

void insertionSortNoPrints(int *arr, int size)
{
    int i = 0, key = 0, prev = 0;
    
    for (i=1; i < size; i++) {
        key = arr[i];
        prev = i - 1;
        while (prev >= 0 && key < arr[prev]) {
            arr[prev+1] = arr[prev];
            prev--;                
        }
        arr[prev+1] = key;
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
        insertionSort(testArr[i], 5);
        printf("\nSorted Array:\t");
        dumpArray(testArr[i], 5);
    };
}
