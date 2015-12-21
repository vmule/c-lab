// Exercise from http://jsperf.com/fb-interview-question-test/2

#include<stdio.h>
#include<string.h>

float counts[7] = {};
float max = 0;

char word[];
//char word[] = "coffee break";

int main() {
printf("Please enter a word:\n");
scanf("%s", &word);

  int i;
  int sizeword = strlen(word);
  printf("Size of word is: %i\n", sizeword);
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

  int k;
  int sizecounts = sizeof(counts)/sizeof(counts[0]);
  for (k = 0; k < sizecounts; k++) {
    printf("k is: %i\n", k);
    printf("count is: %f\n", counts[k]);
    if (counts[k] > max) {
      max = counts[k];
    }
  }
  printf("max num words is: %.1f\n",  max);

  return 0;
}
