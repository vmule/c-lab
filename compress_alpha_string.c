#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* str) {
    int i;
    int z = 0;
    int k = 1;
    int size_str = strlen(str);
    char *compress_str = malloc(size_str + 1);
    if (size_str < 2) {
        return str;
    }

    compress_str[0] = str[0];
    for (i = 1; i < size_str; i++) {
      if (str[i] == str[i-1]) {
          k++;
          if ( k > 9 && k < 99) {
          compress_str[z + 1] = (k / 10) + 48;
          compress_str[z + 2] =  (k % 10) + 48;
          } else if (k > 99) {
              compress_str[z + 1] = (k / 100) + 48;
              compress_str[z + 2] =  ((k / 10) % 10) + 48;
              compress_str[z + 3] =  (k % 10) + 48;
          } else {
              compress_str[z + 1] = k + 48;
          }
       } else {
           if (k > 9 && k < 100) {
               z = z + 3;
               k = 1;
               compress_str[z] = str[i];
           } else if  (k > 99) {
              z = z + 4;
              k = 1;
              compress_str[z] = str[i];
           } else if (k > 1 && k < 10) {
               z = z + 2;
               k = 1;
               compress_str[z] = str[i];
           } else if (k == 1){
               z++;
               compress_str[z] = str[i];
           }
       }
   }

  if (k > 9  && k < 100) {
    z = z + 3;
  } else if  (k > 99) {
    z = z + 4;
  } else if (k > 1 && k < 10) {
    z = z + 2;
  } else if (k == 1){
    z++;
  }

  compress_str[z] = '\0';
  return compress_str;
}

int main() {
    char* res;
    char* str;
    str = (char *)malloc(10240 * sizeof(char));
    str[10240] = '\0';
    scanf("\n%[^\n]", str);

    res = compress(str);
    printf("%s\n", res);
    return 0;
}
