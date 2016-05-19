#include <stdio.h>
#include <stdlib.h>

int mostRecurrNum(int* array, int size) {
  int i;
  int max = array[0];
  for (i = 0; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  max += 1;

  int* brray = (int*)calloc(max, sizeof(int));
  for (i = 0; i < size; i++) {
    int index = array[i];
    brray[index] += 1;
  }

  int bmax = 0;
  int imax = 0;
  for (i = 0; i < max; i++) {
    if (brray[i] > bmax) {
      bmax = brray[i];
      imax = i;
    }
  }
  return imax;
}

int main(void) {

  int A[] = {4,5,5,5,5,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,23,423,32,2,3,44,5,4,5,6,5,6,5,6,54};
  int size = sizeof(A)/sizeof(A[0]);

  int index = mostRecurrNum(A, size);

  printf("Most recurring num is: %d\n", index);
  return 0;
}
