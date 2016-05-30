#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* str) {
    char* compress_str = (char*)calloc(1024, sizeof(char));
    int i, j;
    int k = 1;
    int z = 0;
    int size_str = strlen(str);

    for (i = 0; i < size_str; i++) {
      j = i;
      while (str[i] == str[j+1]) {
        k++;
        j++;
      }
      if (k > 1) {
        compress_str[z] = str[i];
        z++;
        if (k < 10) {
          compress_str[z] = k  + 48;
          z++;
        } else if (k > 9 && k < 100) {
          compress_str[z] = (k / 10) + 48;
          z++; 
          compress_str[z] = (k % 10) + 48;
          z++;
        } else if (k > 99) {
          compress_str[z] = (k / 100) + 48;
          z++;
          compress_str[z] = ((k / 10) % 10) + 48;
          z++;
          compress_str[z] = (k % 10) + 48;
          z++;
        }
        k = 1;
        i = j;
      } else {
        compress_str[z] = str[i]; 
        z++;
      }
    }
    compress_str[z] = '\0';
    return compress_str;
}


int main(void) {
  char* str = "zbbbcccccccccccccccdefgjjjjjnnnnn";
  printf("Original string: %s\n", str);

  char* compress_str = compress(str);
  printf("Compressed string %s\n", compress_str);
  return 0;
}

