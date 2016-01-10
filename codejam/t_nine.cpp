/* https://code.google.com/codejam/contest/351101/dashboard#s=p2 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

const int dict[] = {2, 22, 222,
                    3, 33, 333,
                    4, 44, 444,
                    5, 55, 555,
                    6, 66, 666,
                    7, 77, 777, 7777,
                    8, 88, 888,
                    9, 99, 999, 9999};

const int MAGIC_NO = 97;
const int SPACE_NO = 32;
const char *SPACE = " ";
const char *NEWLINE = "\n";

void t_nine(char* word);

int main(void) {

  int WORDS_NUM;
  std::cin >> WORDS_NUM;

  int word_i;
  char *word = new char[1000];
  for (word_i = 0; word_i < WORDS_NUM; word_i++) {
    if (word_i < 1) {
      std::cin.getline(word, 1000);
    }
    std::cin.getline(word, 1000);
    std::cout << "Case #" << (word_i + 1) << ":";;
    t_nine(word);
  }
  delete [] word;
  return 0;
}

void t_nine(char* word) {

  signed int current_word;
  signed int previous_word;
  int char_k;
  int len = strlen(word);

  for (char_k = 0; char_k < len; char_k++) {
    if (char_k != 0) {
     current_word  = (dict[abs((int)(word[char_k] - MAGIC_NO))] % 10);
     previous_word = (dict[abs((int)(word[char_k-1] - MAGIC_NO))] % 10);
    }
    if (char_k != 0) {
      if (((int)word[char_k] == (int)SPACE[0]
           && (int)word[(char_k-1)] == (int)SPACE[0])
          || current_word == previous_word) {
        std::cout << SPACE[0];
      }
    }
    if ((int)word[char_k] == (int)SPACE[0]) {
      std::cout << "0";
      continue;
    }
  std::cout << (dict[(word[char_k] - MAGIC_NO)]);
  }
  std::cout << NEWLINE[0];
  return;
}

