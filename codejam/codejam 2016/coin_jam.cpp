#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

unsigned long long isPrime(unsigned long long num) {
  if  (num % 11)  {
    return 1;
  }
  return 0;
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
    unsigned long long Q = 0;
    int pow_idx = (N-1);
    for (int z = 0; z < N; z++) {
      Q += (array[z] * (long)pow(10, pow_idx));
      pow_idx--;
    }
//    std::cout << Q << "\n";
    unsigned long long  q = isPrime(Q);

    if ((q == 1) || (std::find(coins.begin(), coins.end(), Q) != coins.end())) {
      int indx = rand() % (N-4) + 2;
      int value = rand() % 2;
      array[indx] = value;
    } else {
      for (int i = 0; i < N; i++) {
        std::cout << array[i];
      }
      std::cout << " 3 4 5 6 7 8 9 10 11\n";
      coins_count++;
      coins.push_back(Q);
      int indx = rand() % (N-4) + 2;
      int value = rand() % 2;
      array[indx] = value;
    }
  }
}
