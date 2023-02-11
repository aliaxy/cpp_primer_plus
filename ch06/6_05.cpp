#include <iostream>

int main() {
  double tax, salary = 0.0;

  std::cout << "Hello, enter your salary to calculate tax: ";
  std::cin >> salary;

  while (salary > 0) {
    if (salary <= 5000) {
      tax = 0;
    } else if (salary <= 15000) {
      tax = (salary - 5000) * 0.1;
    } else if (salary <= 35000) {
      tax = 10000 * 0.10 + (35000 - 15000) * 0.15;
    } else {
      tax = 10000 * 0.10 + 20000 * 0.15 + (salary - 35000) * 0.20;
    }

    std::cout << "Your salary is " << salary << " tvarps, and you should pay "
              << tax << " tvarps.\n";

    std::cout << "Enter your salary to calculate tax: ";
    std::cin >> salary;
  }

  std::cout << "Bye!\n";

  return 0;
}