//https://code.google.com/codejam/contest/2974486/dashboard

#include <stdio.h>

int main(void) {

  int T;
  scanf("%d", &T);
  int i;
  for (i = 1; i <= T; i++) {
    printf("Case #%d: ", i);

    int row_num1;
    scanf("%d", &row_num1);

    int i;
    int j;

    int ROWS1[4][4] = {0};
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        scanf("%d", &ROWS1[i][j]);
      }
    }

    int row_num2;
    scanf("%d", &row_num2);

    int ROWS2[4][4] = {0};
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        scanf("%d", &ROWS2[i][j]);
      }
    }

    int matches = 0;
    int card;

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        if ((ROWS1[row_num1 - 1][i] - ROWS2[row_num2 - 1][j]) == 0) {
          matches++;
          card = ROWS1[row_num1 - 1][i];
         }
      }
    }

    if (matches == 0) {
      printf("Volunteer cheated!\n");
      continue;
    }

    if (matches > 1) {
      printf("Bad magician!\n");
    } else {
      printf("%d\n", card);
    }
  }
  return 0;
}
