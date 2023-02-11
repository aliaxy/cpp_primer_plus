#include <iostream>

int main() {
  int min, max, sum = 0;

  std::cout << "Enter the first numeral: ";
  std::cin >> min;

  std::cout << "Enter the second numeral: ";
  std::cin >> max;

  for (int i = min; i <= max; i++) {
    sum += i;
  }

  std::cout << "The sum of " << min << " +...+ " << max << " is ";
  std::cout << sum << '\n';

  return 0;
}