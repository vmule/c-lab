#include<stdio.h>

int main(void) {

  int N;

  printf("Enter the number of primes: ");
  scanf("%d", &N);

  if (N < 2 ) {
    printf("Please enter a number greater than 2: ");
    scanf("%d", &N);
    return 1;
  }

  if (N < 999 ) {
    printf("Please enter a number smaller than 1000: ");
    scanf("%d", &N);
    return 1;
  }

  printf("Prime numbers:\n");
  printf("2 ");

  int i;
  int k;
  for (i = 3; i <= N; i++) {
    for (k = 2; k <= i; k++) {
      if ((i % k) == 0) {
        break;
      }
    }
    if (i == k) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
