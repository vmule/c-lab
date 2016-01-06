#include <stdio.h>
#include <string.h>

int main(void) {

  int N;
  scanf("%i\n", &N);

  int i;
  int j = 0;
  char word[1000][30];
  char tmpword[1000];
  for (i = 0; i < N; i++) {
    int getword = 1;
    getword = scanf("%[a-z ]\n", tmpword);
    //printf("%s\n", tmpword);
    char *wordpointer = strtok(tmpword, " ");
    while (wordpointer != NULL) {
      strcpy(word[j], wordpointer);
      j++;
      // a null pointer may be specified, in which case the function continues scanning where a previous successful call to the function ended.
      wordpointer = strtok(NULL, " ");
    }
    printf("Case #%i: ", (i+1));

    for (j = (j - 1) ; j >= 0; j--) {
       printf("%s ", word[j]);
    }

    j = 0;
    printf("\n");
  }
  return 0;
}
