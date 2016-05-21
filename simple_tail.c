#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define BUFF_SIZE 4096

void
walkFile(FILE *file, long nlines);

void
printLine(FILE *file, off_t startline);

int
main(int argc, char **argv)
{
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    perror("fopen");
    exit(errno);
  }
  walkFile(file, atol(argv[2]));
  fclose(file);
  return 0;
}

void
walkFile(FILE *file, long nlines)
{
  fseek(file, 0, SEEK_END);
  off_t fposition = ftell(file);
  off_t index = fposition;
  off_t end = fposition;

  for(; index >= 0; index--) {
    if (fgetc(file) == '\n' && (end - index) > 1) {
      //printf("index: %lld\n", index);
      nlines--;
      if (nlines == 0) {
        break;
      }
    }
    //printf("position: %lld\n", fposition);
    fposition--;
    fseek(file,fposition,SEEK_SET);
  }
  printLine(file, fposition);
}

void
printLine(FILE *file, off_t startline)
{
  char buffer[BUFF_SIZE];
  fseek(file, (startline + 1), SEEK_SET);
  while (fgets(buffer, BUFF_SIZE, file)) {
    fputs(buffer, stdout);
  }
}
