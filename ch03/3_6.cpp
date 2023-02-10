#include <iostream>

int main() {
  double kilometer, oil_liter;

  std::cout << "Enter the distance that you've driver in kilometer: ";
  std::cin >> kilometer;

  std::cout << "Enter the consumption of oil: ";
  std::cin >> oil_liter;

  double kilometer_per_liter = kilometer / oil_liter;

  std::cout << "The average oil consumption is " << 100 / kilometer_per_liter
            << " L/100km.\n";

  return 0;
}