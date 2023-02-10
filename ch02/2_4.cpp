#include <iostream>

int main() {
  int years;

  std::cout << "Enter your age: ";
  std::cin >> years;

  int months = years * 12;
  std::cout << years << " years is " << months << " months.\n";

  return 0;
}