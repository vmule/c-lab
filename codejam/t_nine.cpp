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
                    9, 99, 999, 9999, 0};

const int MAGIC_NO = 97;
const int MAGIC_SPACE = 59;
const char SPACE = ' ';
const char NEWLINE = '\n';

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
    std::cout << "Case #" << (word_i + 1) << ":" << SPACE;
    t_nine(word);
  }
  delete [] word;
  return 0;
}

void t_nine(char* word) {

  signed int current_word;
  signed int previous_word = 666;
  int char_k;
  int len = strlen(word);

  for (char_k = 0; char_k < len; char_k++) {
     if (word[char_k] == SPACE) {
       current_word  = 0;
     } else {
         current_word  = (dict[abs((int)(word[char_k] - MAGIC_NO))] % 10);
       }
    if (char_k != 0) {
      if (((int)word[char_k] == (int)SPACE
           && (int)word[(char_k-1)] == (int)SPACE)
          || current_word == previous_word) {
        std::cout << SPACE;
      }
    }
    if ((int)word[char_k] == (int)SPACE) {
      std::cout << dict[27];
      continue;
    }
  std::cout << (dict[(word[char_k] - MAGIC_NO)]);
  previous_word = current_word;
  }
  std::cout << NEWLINE;
  return;
}

