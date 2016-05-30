#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* str) {
    int size_str = strlen(str);
    char* compress_str = (char*)calloc((size_str+1), sizeof(char));
    int i, tmp_i;
    int rep_count = 1;
    int cstr_i = 0;

    for (i = 0; i < size_str; i++) {
      tmp_i = i;
      while (str[i] == str[tmp_i+1]) {
        rep_count++;
        tmp_i++;
      }
      if (rep_count > 1) {
        compress_str[cstr_i] = str[i];
        cstr_i++;
        if (rep_count < 10) {
          compress_str[cstr_i] = rep_count + 48;
          cstr_i++;
        } else if (rep_count > 9 && rep_count < 100) {
          compress_str[cstr_i] = (rep_count / 10) + 48;
          cstr_i++; 
          compress_str[cstr_i] = (rep_count % 10) + 48;
          cstr_i++;
        } else if (rep_count > 99) {
          compress_str[cstr_i] = (rep_count / 100) + 48;
          cstr_i++;
          compress_str[cstr_i] = ((rep_count / 10) % 10) + 48;
          cstr_i++;
          compress_str[cstr_i] = (rep_count % 10) + 48;
          cstr_i++;
        }
        rep_count = 1;
        i = tmp_i;
      } else {
        compress_str[cstr_i] = str[i]; 
        cstr_i++;
      }
    }
    compress_str[cstr_i] = '\0';
    return compress_str;
}


int main(void) {
  char* str = "zbbbcccccccccccccccdefgjjjjjnnnnn";
  printf("Original string: %s\n", str);

  char* compress_str = compress(str);
  printf("Compressed string %s\n", compress_str);
  return 0;
}

