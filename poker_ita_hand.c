#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char suits[] = {'h', 's', 'c', 'd'};
const char cards[] = {'7', '8', '9', 'T',
                      'J', 'Q', 'K', 'A'};

int main(void) {

  int i;
  int suit;
  int card;
  char in_hand[4][8] = {0};

  for ( i = 5; i > 0; i--) {
    srand(time(NULL) - (rand() % 999));
    suit = rand() % 3;
    card = rand() % 7;
    if (!in_hand[suit][card]) {
      in_hand[suit][card] = '1';
      printf("%c%c ", suits[suit], cards[card]);
    } else {
        i++;
     }
  }
  printf("\n");
}
