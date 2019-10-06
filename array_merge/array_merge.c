// #include <cstdio>
#include "../mergesort/mergesort.c"
#include "../mergesort/mergesort.h"
#include <stdio.h>

//Our idea for steps to approach this issue:

//1: Combine all `values` into a single array, including duplicates
//2: Sort the single array using `mergesort`
//3: Use the most succinct unique counting approach that we found: gevni's counter 
//     @ https://cboard.cprogramming.com/c-programming/155200-how-can-i-count-total-no-unique-elements-array.html#post1154407
//     Our modification of this involves creating another array in the next step...
//4: Create an array for the unique values. As #3 adds to the unique counter, it will also put in that unique value into 
//     our new array. This will add them uniquely in order. 
//5: Put the unique counter at the head of the array. Not sure if we need to reserve the spot for it upfront or if it could
//     just but moved into the front. 

int* array_merge(int num_arrays, int* sizes, int** values) {
  // This is obviously broken. It has the right type, though, eh?
  return sizes;
}

int main(int argc, char *argv[]) {
  int a[2] = { 8, 5 };
  mergesort(2, a);

  for(int loop = 0; loop < 2; loop++){
    printf("%d ", a[loop]);
  }
}
