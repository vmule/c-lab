#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   /* Intializes random number generator */
   srand(time(NULL) + 17);

   /* Print random number from 1 to 6 */
      printf("%d\n", (rand() % 5) + 1);
   return 0;
}
