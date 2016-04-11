#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

unsigned long long isPrime(unsigned long long num) {
  if ((num % 2) == 0 && num != 2) {
   return 2;
  }
  for (unsigned long long i = 2; i <= sqrt(num); i += 2) {
    if (i % 2 == 0) {
      i++;
    }
    if ((num % i) == 0 && i != num) {
      return i;
    }
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

  unsigned long long base_array[11];
  unsigned long long divisor_array[11];
  std::vector<unsigned long long> coins(J);
  srand(time(NULL));

  std::cout << "Case #1:\n";
  int coins_count  = 0;
  while (coins_count < J) {
    int isprime = 1;
    for (int i = 2; i < 11; i++) {
      unsigned long long P = 0;
      int pow_idx = (N - 1);
      for (int z = 0; z < N; z++) {
          P += (array[z] * (pow(i, pow_idx)));
          pow_idx--;
        }
      unsigned long long  p = isPrime(P);
      if (p > 1) {
        base_array[i] = P;
        divisor_array[i] = p;
        P = 0;
      } else {
        isprime = 0;
        P = 0;
        break;
      }
    }
    if (!isprime || (std::find(coins.begin(), coins.end(), base_array[10]) != coins.end())) {
      isprime = 1;
      int indx = rand() % (N-2) + 1;
      int value = rand() % 2;
      array[indx] = value;
      continue;
    } else {
      for (int i = 0; i < N; i++) {
        std::cout << array[i];
      }
      std::cout << " ";
      for (int i = 2; i < 11; i++) {
       std::cout << divisor_array[i]  << " ";
      }
      std::cout << "\n";
      coins_count++;
      coins.push_back(base_array[10]);
      int indx = rand() % (N-2) + 1;
      int value = rand() % 2;
      array[indx] = value;
    }
  }
}
