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

  if(num_arrays == 0) {
    int *sortedUniques = (int *) calloc(1, sizeof(int));
    sortedUniques[0] = 0;
    return sortedUniques; 
  }

  int sumSizes = 0;

  for (int i = 0; i < num_arrays; i++) {
    sumSizes += sizes[i]; 
  }

  int *joined_array = (int *) calloc(sumSizes + 1, sizeof(int)); 
   
  int j_array_index = 0;

  for (int j = 0; j < num_arrays; j++) {
    for (int k = 0; k < sizes[j]; k++) { 
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

  int *sortedUniques = (int *) calloc(unique+1, sizeof(int));
  sortedUniques[0] = unique;

  int sortedCounter = 1;

  for(int unique_sorted_vals = 0; unique_sorted_vals < j_array_index; unique_sorted_vals++) {
    if (joined_array[unique_sorted_vals]==joined_array[unique_sorted_vals+1]){
      continue;
    } else {
      sortedUniques[sortedCounter] = joined_array[unique_sorted_vals];
      sortedCounter++;
    }
  }

  return sortedUniques;
}
