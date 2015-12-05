// CS50 week1: Print mario-like pyramid make of $.

#include <stdio.h>

int void main() {

  int height = 0;

  while (height == 0 || height < 0 || height > 23) {
    printf("Enter the eight of the pyramid:");
    if ((scanf("%d", &height) == 0) || (height < 0 || height > 23)) {
      fseek(stdin,0,SEEK_END);
    }
    else {
      printf("Pyramid height is: %i\n", height);
    }
  }

  for (int x = 1; x < height; x++) {
    for (int j = 0; j < height; j++) {
      if (j < height - x -1 ) {
        printf(" ");
      }
      else {
        printf("#");
      }
    }
    printf("\n");
  }
  return 0;
}
