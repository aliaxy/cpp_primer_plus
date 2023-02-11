#include <array>
#include <iostream>

const int ArSize = 101;

int main() {
  std::array<long double, ArSize> factorial;
  factorial[1] = factorial[0] = 1;

  for (int i = 2; i < ArSize; i++) {
    factorial[i] = i * factorial[i - 1];
  }

  for (int i = 0; i < ArSize; i++) {
    std::cout << i << "! = " << factorial[i] << '\n';
  }

  return 0;
}