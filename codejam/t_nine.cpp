#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<iostream>

void main(void) {
  int dict[] = {2, 22, 222,
                3, 33, 333,
                4, 44, 444,
                5, 55, 555,
                6, 66, 666,
                7, 77, 777, 7777,
                8, 88, 888,
                9, 99, 999, 9999};

  int N;
  std::cin >> N;

  int i;
  int k;
  signed int z;
  signed int w;
  for (i = 0; i < N; i++) {
    char *word = (char*)malloc(1000*(sizeof(char)));
    if (i < 1) {
      std::cin.getline(word, 1000);
    }
    std::cin.getline(word, 1000);
    int len = strlen(word);
    printf("Case #%i: ", i + 1);
    for (k = 0; k < len; k++) {
      if (k != 0) {
       z = (dict[(int)(word[k] - 97)] % 10);
       w = (dict[(int)(word[k-1] - 97)] % 10);
      }
      if (k != 0) {
        if (z == w || (word[k] == ' ' && word[(k-1)] == ' ')) {
          printf(" ");
        }
      }
      if (word[k] == ' ') {
        printf("0");
        continue;
      }
    printf("%i", dict[(word[k] - 97)]);
    }
    printf("\n");
    free(word);
  }
  return;
}
