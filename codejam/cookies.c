// https://code.google.com/codejam/contest/2974486/dashboard#s=p1

#include<stdio.h>

int main(void) {

  FILE *fd = fopen("./file", "r");
  FILE *fd2 = fopen("./file.out", "w");

  int T;
  fscanf(fd, "%d\n", &T);

  int i;
  for (i = 0; i < T; i++) {
    double C, F, X;

    fscanf(fd, "%lf", &C);
    fscanf(fd, "%lf", &F);
    fscanf(fd, "%lf\n", &X);

    double CS = 2.0000000;
    double seconds = 0.0000000;

    while ( (seconds + X/CS) > (seconds + (C/CS) + (X/(CS + F))) ) {
      seconds += (C/CS);
      CS += F;
    }
    fprintf(fd2, "Case #%d: %.7f\n", (i + 1), (seconds + (X/CS)));
  }
  return 0;
}
