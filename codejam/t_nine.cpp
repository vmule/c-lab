/* https://code.google.com/codejam/contest/351101/dashboard#s=p2 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

int i;
int k;
signed int z;
signed int w;
int N;

int main(void) {

  int dict[] = {2, 22, 222,
                3, 33, 333,
                4, 44, 444,
                5, 55, 555,
                6, 66, 666,
                7, 77, 777, 7777,
                8, 88, 888,
                9, 99, 999, 9999};

  std::cin >> N;

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
     z = (dict[abs((int)(word[k] - 97))] % 10);
     w = (dict[abs((int)(word[k-1] - 97))] % 10);
    }
    if (k != 0) {
      if (((int)word[k] == 32 && (int)word[(k-1)] == 32) || z == w) {
        printf(" ");
      }
    }
    if ((int)word[k] == 32) {
      printf("0");
      continue;
    }
  printf("%i", dict[(word[k] - 97)]);
  }
  printf("\n");
  free(word);
  w = 666;
  }
  return 0;
}
