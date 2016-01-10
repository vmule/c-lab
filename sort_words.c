#include <stdio.h>
#include <string.h>

void namesort(char words[][20], int);

int main(){
  int i;
  int n;

  printf("Enter number of words: ");
  while (scanf("%d",&n) != 1) {
    printf("You did not enter a valid number\n");
    printf("Enter number of words: ");
    scanf("%*s");
  }

  char words[n][20];
  for(i = 0; i < n; i++){
    printf("Enter word: ");
    scanf("%s", words[i]);
  }
  namesort(words, n);
  printf("Sorted words:\n");
  for(i = 0; i < n; i++)
    printf("%s\n",words[i]);
  printf("\n");
  return 0;
}

void namesort(char words[][20], int n){
  int i,j;
  char temp[20];
  for(i = 0; i < n; i++){
    for(j = 0; j < n - 1; j++){
      if(strcmp(words[j], words[j + 1])>0){
        strncpy(temp, words[j], 20);
        strncpy(words[j], words[j + 1], 20);
        strncpy(words[j + 1], temp, 20);
      }
    }
  }
}
