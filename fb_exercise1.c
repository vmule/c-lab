// Exercise from http://jsperf.com/fb-interview-question-test/2
#include<stdio.h>
#include<string.h>

float counts[7] = {};
float counts_magic[30] = {};
float max = 0;
// word can be maximum 100 chars long.
char word[100];

void getCount(char* word);
void getCountMagic(char* word);
void printCounts(float* counts, int sizeArray);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Please enter a word:\n");
    scanf("%s", word);
    getCount(word);
    getCountMagic(word);
  }
  else {
  getCount(argv[1]);
  getCountMagic(argv[1]);
  }
  return 0;
}

void getCount(char* word) {

  int i;
  int sizeword = strlen(word);
  for (i = 0; i < sizeword; i++) {
    char letter = word[i];
    switch(letter) {
      case 'f': counts[0]++; break;
      case 'a': counts[1]++; break;
      case 'c': counts[2]++; break;
      case 'e': counts[3]++; break;
      case 'b': counts[4]++; break;
      case 'o': counts[5] = (counts[5] + 0.5); break;
      case 'k': counts[6]++; break;
      default: break;
    }
  }
  printCounts(counts, 7);
  return;
}

void getCountMagic(char* word) {
  int i;
  int k;
  int sizeword = strlen(word);
  for (i = 0; i < sizeword; i++) {
    k = word[i] - 97;
    counts_magic[k]++;
  }
  counts_magic[14] = (counts_magic[14] * 0.5);
  printCounts(counts_magic, 30);
  return;
}

void printCounts(float* counts, int sizeArray) {
  int k;
  for (k = 0; k < sizeArray; k++) {
    if (counts[k] > max) {
      max = counts[k];
    }
  }
  printf("max num words is: %.2f\n",  max);
  return;
}


