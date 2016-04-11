#include <iostream>

int main(void) {

  int T;
  std::cin >> T;

  for (int i = 0; i < T; i++) {
    int k = 1;
    int tracking_array[10] = {0};
    int tracking_value = 0;
    int N;
    int M, R;
    std::cin >> N;
    if (N == 0) {
      std::cout << "Case #" << (i + 1) << ": " << "INSOMNIA\n";
      continue;
    }
    while (tracking_value < 10) {
      M = k * N;
      while (M != 0) {
        R = M % 10;
        if (tracking_array[R] == 0) {
          tracking_value++;
          tracking_array[R] = 1;
        }
        M = M / 10;
      }
      k++;
    }
    std::cout << "Case #" << (i + 1) << ": " << N * (k-1) << "\n";
    tracking_value = 0;
    k = 1;
  }
  return 0;
}

