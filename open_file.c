#include <stdio.h>

int main(void) {

  char file_input[32];
  char file_output[32];

  printf("Enter file to read:\n");
  scanf("%s", file_input);
  printf("Enter file to write:\n");
  scanf("%s", file_output);

  FILE *fd = fopen(file_input, "r");
  FILE *fd2 = fopen(file_output, "w");

  int n;
  fscanf(fd, "%d", &n);
  fprintf(fd2, "aloha %d\n", n);

  return 0;
}

