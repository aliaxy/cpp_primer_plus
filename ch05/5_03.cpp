#include <iostream>

int main() {
  double temp, sum = 0;

  do {
    std::cout << "Input a numeral to add: ";
    std::cin >> temp;

    sum += temp;

    std::cout << "The sum = " << sum << '\n';
  } while (temp != 0);

  std::cout << "Input end.\n"
            << "The sum = " << sum << '\n';

  return 0;
}