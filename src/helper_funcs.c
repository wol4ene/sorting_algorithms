#include <stdlib.h>
#include <stdio.h>

#include "helper_funcs.h"

void swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
};

void dumpArray(int *arr, int size) {
    int i = 0;
    printf("[");
    for (i = 0; i < size-1; i++) {
        printf("%i,", arr[i]);
    }
    printf("%i]\n", arr[size-1]);
};
