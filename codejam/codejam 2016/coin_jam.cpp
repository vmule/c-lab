#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

unsigned long long isPrime(unsigned long long num) {
  if  ((num % 3) == 0 || num == 0)  {
    return 0;
  }
  return 1;
}

int main(void) {

  int T;
  std::cin >> T;
  int N, J;
  std::cin >> N >> J;

  int array[N];
  for (int i = 0; i < N; i++) {
    array[i] = 0;
  }
  array[0] = 1;
  array[1] = 1;
  array[N-1] = 1;
  array[N-2] = 1;

  std::vector<unsigned long long> coins(J);

  std::cout << "Case #1:\n";
  int coins_count  = 0;
  int isprime = 1;
  while (coins_count < J) {
    unsigned long long P = 0;
    int pow_idx = (N - 1);
    for (int z = 2; z < (N - 2); z++) {
//      std::cout << P << "\n";
      P += (array[z] * (long)pow(2, pow_idx));
      pow_idx--;
    }
    unsigned long long  p = isPrime(P);
    if (p || (std::find(coins.begin(), coins.end(), P) != coins.end())) {
      int indx = rand() % (N-4) + 2;
      int value = rand() % 2;
      array[indx] = value;
    } else {
      for (int i = 0; i < N; i++) {
        std::cout << array[i];
      }
      std::cout << " 3 4 5 6 7 8 9 10 11 \n";
      coins_count++;
      coins.push_back(P);
      int indx = rand() % (N-4) + 2;
      int value = rand() % 2;
      array[indx] = value;
    }
  }
}
