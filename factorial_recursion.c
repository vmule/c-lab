#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int recursion(int x);
int num;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Please enter a number..\n");
    scanf("%d", &num);
  }
  else {
    num = atoi(argv[1]);
    //num = strtol(argv[1], NULL, 10);
  }

  int f = recursion(num);
  printf("Factor of %i is: %i.\n", num, f);
  return 0;
}


int recursion(int x) {

 if (x <= 1) {
   return(x);
 }


 else {
   x = x*(recursion(x-1));
   return(x);
 }
}
