#include<stdio.h>
#include<stdlib.h>

int mergeSort(int *A, int n);
int merge(int *A, int *L, int max_L, int *R, int max_R);

int main() {
  int i;
  int A[] = {3,1,1,4,5,2,2,3,4,5,6,5,4,55,66,52,4,8,7,66666,4,3,4,2,2222,3,4,55,6,7,5,3456,234,4356,234,1887,435};
  int n = sizeof(A)/sizeof(int);
  printf("size of array: %d\n", n);
  printf("Initial Array\n");
  for (i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  mergeSort(A, n);
  printf("Sorted Array\n");
  for (i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}

int merge(int *A, int *L, int max_L, int *R, int max_R) {

  int i = 0;
  int k = 0;
  int j = 0;
  while (i < max_L && j < max_R) {
    if (L[i] < R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < max_L) {
    A[k] = L[i];
    i++;
    k++;
  }
  while (j < max_R) {
    A[k] = R[j];
    j++;
    k++;
  }
 return 0;
}

int mergeSort(int *A, int n) {
  if (n < 2) {
    return 0;
  }
  int i;
  int mid;
  mid = (n/2);
  printf("mid: %d\n", mid);
  printf("n - mid: %d\n", (n-mid));
  int *L;
  L = malloc(mid*sizeof(int));
  int *R;
  R = malloc((n - mid)*sizeof(int));

  printf("Left array: \n");
  for (i = 0; i < mid; i++) {
    L[i] = A[i];
    printf("%d ", A[i]);
  }
  printf("\n");

  printf("Right array: \n");
  for (i = mid; i < n; i++) {
    R[i-mid] = A[i];
    printf("%d ", A[i]);
  }
  printf("\n");
  mergeSort(L, mid);
  mergeSort(R, (n - mid));
  merge(A, L, mid, R, (n - mid));
  free(L);
  free(R);
  return 0;
}

