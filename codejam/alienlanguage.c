// https://code.google.com/codejam/contest/dashboard?c=90101

#include<stdio.h>
#include<regex.h>
#include<string.h>

regex_t regex;
int match;




int main(void) {

  int i, j, z, L, D, N;

  scanf("%d %d %d", &L, &D, &N);
  //  printf("%d %d %d\n", L, D, N);

  char array[D][L+1];
  char array2[500][500];

   for (i = 0; i < D; i++) {
     scanf("%s\n", array[i]);
     // printf("%s\n", array[i]);
   }
   i = 0;
   while (scanf("%s", array2[i]) != EOF) {
     j = 0;
     while(array2[i][j] != '\0') {
       if (array2[i][j] == '(') {
         array2[i][j] = '[';
       } else if (array2[i][j] == ')') {
         array2[i][j] = ']';
       }
       j++;
     }

     // printf("regex is: %s\n", array2[i]);
     match = regcomp(&regex, array2[i], 0);
     int k = 0;
     z = 0;
     for (k = 0; k < D; k++) {
       // printf("string to match is: %s\n", array[k]);
       match = regexec(&regex, array[k], 0, NULL, 0);
       if (!match) {
        // printf("match\n");
         z++;
       }
     }
     printf("Case #%i: %i\n", (i+1), z);
     z = 0;
     memset(&regex, 0, 1);
     i++;
   }

  return 0;
}

