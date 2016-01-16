#include<stdio.h>

int main(void) {
  int testnum;
  scanf("%d\n", &testnum);

  int i;
  int k;
  int z;
  int max_shyness;
  char audience[1001];
  int standing = 0;
  int added_friend = 0;

  for (i = 0; i < testnum; i++) {
    scanf("%d", &max_shyness);
    scanf("%s\n", audience);

    for (k = 0; k <= max_shyness ; k++) {
      standing += ((int)audience[k] - 48);
      if (standing < (k + 1)) {
        added_friend += k + 1 - standing;
        standing = k + 1;
      }
    }

    printf("Case #%i: %d\n", (i +1), added_friend);
    added_friend = 0;
    standing = 0;
  }
  return 0;
}
