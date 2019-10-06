// #include <cstdio>
#include "../mergesort/mergesort.c"
#include "../mergesort/mergesort.h"
#include <stdio.h>

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
