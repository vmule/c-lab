// https://code.google.com/codejam/contest/2974486/dashboard#s=p1

#include<stdio.h>

int main(void) {

  int T;
  scanf("%d\n", &T);

  int i;
  for (i = 0; i < T; i++) {
    double C, F, X;

    scanf("%lf", &C);
    scanf("%lf", &F);
    scanf("%lf\n", &X);

    float CS = 2.0;
    float seconds = 0;

    if (C > X) {
      printf("Case #%d: %.7f\n", (i + 1), (seconds +1));
      continue;
    }

    while ( (seconds + X/CS) > (seconds + (C/CS) + (X/(CS + F))) ) {
      seconds += (C/CS);
      CS += F;
    }
    printf("Case #%d: %.7f\n", (i + 1), (seconds + (X/CS)));
  }
  return 0;
}
