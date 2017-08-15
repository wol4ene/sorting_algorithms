#include <stdio.h>
#include <stdlib.h>
#include "helper_funcs.h"

/**
 * Mergesort is a divide and conquer sorting algorithm that divides an unsorted
 * list into n sublists, each containing 1 element.  Then it repeatedly merges sublists
 * to produce new sorted sublists until there is only 1 sublist remaining.
 * 
 * Best Case: O(n*log(n))
 * Worse Case: O(n*log(n))
 */

/**
 * Merge portion of mergesort algorithm
 *
 * Creates a temporary array sized to the number of elements we are sorting
 * in this pass.
 * Using sentinels i & j to keep track of left and right portions of unsorted
 * arr[l..m] and arr[m+1..r], merge together left and right arrays into temp array.
 * Finally, copy this sorted temp array into the arr[l..r]
 */
void _merge(int arr[], int l, int m, int r) 
{
    int tmpSize = r - l + 1;        // total number of elems to sort
    int *tmp = malloc(sizeof(int)   // tmp array
                      * tmpSize);

    int numL = m - l + 1;   // num elems are in left subarray
    int numR = r - m;       // num elems in right subarray
    int i = l;              // idx into arr for left subarray
    int j = m + 1;          // idx into arr for right subarr
    int k = 0;              // indx into tmp array

    /* while elems exist in both subarrays, grab the smallest */
    while (numL > 0 && numR > 0) {
        if (arr[i] < arr[j]) {
            tmp[k++] = arr[i++];
            numL--;
        } else {
            tmp[k++] = arr[j++];
            numR--;
        }
    }

    /* if any elems exist in left or right subarray, copy them over to temp */
    while (numL > 0) {
        tmp[k++] = arr[i++];
        numL--;
    };
    while (numR > 0) {
        tmp[k++] = arr[j++];
        numR--;
    }

    /* finally, copy tmp back into arr, starting at left */
    i = l;
    for (k = 0; k < tmpSize; k++) {
        arr[i++] = tmp[k];
    }
}

/**
 * Recursive part of mergesort algorithm
 *
 * Recursively divide array in half, until only 1 element,
 * then start merging left and right arrays together
 */
void _mergeSort(int arr[], int l, int r)
{
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    _mergeSort(arr, l, m);
    _mergeSort(arr, m+1, r);
    _merge(arr, l, m, r);
}

void mergeSort(int arr[], int size)
{
    _mergeSort(arr, 0, size-1);
}

int main(void) {
    int arr1[] = {6,8,9,3};
    printf("\nUnsorted Array:\t");
    dumpArray(arr1, 4);
    mergeSort(arr1, 4);
    printf("\nSorted Array:\t");
    dumpArray(arr1, 4);

    int arr2[] = {6,7,8,2,1,9,5};
    printf("\nUnsorted Array:\t");
    dumpArray(arr2, 7);
    mergeSort(arr2, 7);
    printf("\nSorted Array:\t");
    dumpArray(arr2, 7);;
}

/**
 * Alternate form for merge-sort that uses two temporary arrays
 * to store the unsorted elements of arr[l..r], where
 *     left array stores arr[l..m]
 *    right array stores arr[m+1..r]
 * Then merges these temp arrays back into arr[l..r]
 */
void _merge_alt(int arr[], int l, int m, int r) 
{
    /* create 2 temp arrays, one for left and one for right */
    int numL = m - l + 1;       // num elems in left array
    int numR = r - m;           // num elems in right array
    int left[numL];
    int right[numR];
    
    int i = 0;  // idx for left array
    int j = 0;  // idx for right array
    int k = l;  // idx for copying into final, sorted array

    /* copy unsorted elems into left and right array, respectively */
    for (i = 0; i < numL; i++) {
        left[i] = arr[l+i];
    }
    for (j = 0; j < numR; j++) {
        right[j] = arr[m+1+j];
    };

    /* merge the temp arrays back into arr[l..r] */
    i = j = 0;
    while (numL > 0 && numR > 0) {
        if (left[i] > right[j]) {
            arr[k++] = right[j++];
            numR--;
        } else {
            arr[k++] = left[i++];
            numL--;
        }
    }

    /* merge in any leftovers in left-array */
    while (numL > 0) {
        arr[k++] = left[i++];
        numL--;
    };
    /* merge in any leftovers in right-array */
    while (numR > 0) {
        arr[k++] = right[j++];
        numR--;
    }
}

