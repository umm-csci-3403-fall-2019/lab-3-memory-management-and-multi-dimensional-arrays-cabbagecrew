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
  int sumSizes = 0;

  for (int i = 0; i < num_arrays; i++) {
    sumSizes += sizes[i]; 
  }

  int *joined_array = (int *) calloc(sumSizes, sizeof(int)); 
   
  int j_array_index = 0;

  for (int j = 0; j < num_arrays; j++) {
    for (int k = 0; k < sizes[j]; k++) { 
      printf("Values: %d \n", values[j][k]);
      joined_array[j_array_index] = values[j][k];
      j_array_index++;
    }
  }

  mergesort(j_array_index, joined_array);

  int unique = 1;
  for(int b = 0; b < j_array_index -1; b++) {
    if(joined_array[b]==joined_array[b+1]) {
      continue;
    } else {
      unique++;
    }
  }

  printf("Unqiue: %d \n", unique);

  printf("Sorted: \n");
  for (int v = 0; v < j_array_index; v++) {
      printf("Values: %d \n", joined_array[v]);
  }
  
  return joined_array;
}

int main(int argc, char *argv[]) {

  int num_arrays = 3;
  int sizes[] = { 2, 2, 3 };
  int a0[] = { 3, 8 };
  int a1[] = { 5, 8 };
  int a2[] = { 8, 5, 1 };
  int* a[] = { a0, a1, a2 };
  int* arr_merge = array_merge(num_arrays, sizes, a);

  // for (int l = 0; l < 4; l++) {
  //   printf("%d", arr_merge[l]);
  // }

  free(arr_merge);
  
}
