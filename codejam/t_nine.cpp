/* https://code.google.com/codejam/contest/351101/dashboard#s=p2 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

const int MAGIC_NO = 97;
const int SPACE_NO = 32;
const char *SPACE = " ";
const char *NEWLINE = "\n";
int WORDS_NUM;

int i;
int k;
signed int current_word;
signed int previous_word;

int main(void) {

  int dict[] = {2, 22, 222,
                3, 33, 333,
                4, 44, 444,
                5, 55, 555,
                6, 66, 666,
                7, 77, 777, 7777,
                8, 88, 888,
                9, 99, 999, 9999};

  std::cin >> WORDS_NUM;

  for (i = 0; i < WORDS_NUM; i++) {
    char *word = new char[1000];
    if (i < 1) {
      std::cin.getline(word, 1000);
    }
  std::cin.getline(word, 1000);
  int len = strlen(word);
  printf("Case #%i: ", i + 1);
  for (k = 0; k < len; k++) {
    if (k != 0) {
     current_word  = (dict[abs((int)(word[k] - MAGIC_NO))] % 10);
     previous_word = (dict[abs((int)(word[k-1] - MAGIC_NO))] % 10);
    }
    if (k != 0) {
      if (((int)word[k] == (int)SPACE[0] && (int)word[(k-1)] == (int)SPACE[0]) || current_word == previous_word) {
        std::cout << SPACE[0];
      }
    }
    if ((int)word[k] == (int)SPACE[0]) {
      std::cout << "0";
      continue;
    }
  std::cout << (dict[(word[k] - MAGIC_NO)]);
  }
  std::cout << NEWLINE[0];
  delete [] word;
  }
  return 0;
}
