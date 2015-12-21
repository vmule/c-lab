#include<stdio.h>
#include<stdlib.h>

int mergeSort(int *A, int n);
int merge(int *A, int *L, int max_L, int *R, int max_R);

int main() {
  int i;
  int A[] = {3,5,6,2,1,7,9,4};
  int n = sizeof(A)/sizeof(A[0]);
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
  while (i < max_L && k < max_R) {
    if (L[i] < R[k]) {
      A[j] = L[i];
      i++;
    }
    else {
      A[j] = R[k];
      k++;
    }
    j++;
  }

  while (i < max_L) {
    A[j] = L[i];
    i++;
  }
  while (j < max_R) {
    A[j] = R[k];
    k++;
  }
  j++;

  return 0;
}

int mergeSort(int *A, int n) {
  if (n < 2) {
    return 0;
  }
  int i;
  int mid;
  mid = n/2;
  int *L = (int*)malloc(mid*sizeof(int));
  int *R = (int*)malloc((n - mid)*sizeof(int));

  for (i = 0; i < mid; i++) {
    L[i] = A[i];
//    printf("%d ", A[i]);
  }

  for (i = mid; i < n; i++) {
    R[i-mid] = A[i];
//    printf("%d ", A[i]);
  }
   mergeSort(L, mid);
   mergeSort(R, (n - mid));
   merge(A,L,mid,R,(n - mid));
   free(L);
   free(R);

   return 0;
}

