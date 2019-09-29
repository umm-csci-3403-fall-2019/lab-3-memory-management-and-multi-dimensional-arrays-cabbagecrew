#include "mergesort.h"

void mergeRanges(int* values, int startIndex, int midPoint, int endIndex){
    int rangeSize = endIndex - startIndex;
    int* destination = (int)calloc(rangeSize, sizeof(int)); 
    int firstIndex = startIndex;
    int secondIndex = midPoint;
    int copyIndex = 0;
    
    while (firstIndex < midPoint && secondIndex < endIndex) {
      if (values[firstIndex] < values[secondIndex]) {
        destination[copyIndex] = values[firstIndex];
        ++firstIndex;
      } else {
        destination[copyIndex] = values[secondIndex];
        ++secondIndex;
      }
      ++copyIndex;
    }
    while (firstIndex < midPoint) {
      destination[copyIndex] = values[firstIndex];
      ++copyIndex;
      ++firstIndex;
    }
    while (secondIndex < endIndex) {
      destination[copyIndex] = values[secondIndex];
      ++copyIndex;
      ++secondIndex;
    }
    for (int i = 0; i < rangeSize; ++i) {
      values[i + startIndex] = destination[i];
    }
  }
}

boolean needsSorting(int rangeSize){
    return rangeSize >= 2;
}

void mergesortRange(int* values, int startIndex, int endIndex) {
    int rangeSize;
    return;
}

void mergesort(int size, int* values) {
    return;
}

void main(int argc) {
    printf("Main runs");
}
