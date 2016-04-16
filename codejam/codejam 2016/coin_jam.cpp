// https://code.google.com/codejam/contest/6254486/dashboard#s=p2
#include <iostream>
#include <bitset>
#include <string>
#include <boost/dynamic_bitset.hpp>

int main(void) {
  int T;
  std::cin >> T;
  int N, J;
  std::cin >> N >> J;

  int coins_count  = 0;
  int count = 0;
  std::string buf;

  std::cout << "Case #1:\n";
  while (coins_count < J) {
      std::string binary_10 = "1";
      boost::dynamic_bitset<> bin((N-2), count);
      to_string(bin, buf);
      binary_10.append(buf);
      binary_10.append("1");
      long binary_3 = std::stol(binary_10, nullptr, 3);
      long binary_2 = std::stol(binary_10, nullptr, 2);
      if (binary_2 % (long)3 == 0 && binary_3 % (long)4 == 0) {
        std::cout << binary_10;
        std::cout << " 3 4 5 6 7 8 9 10 11\n";
        count++;
        coins_count++;
      } else {
        count++;
      }
  }
}
