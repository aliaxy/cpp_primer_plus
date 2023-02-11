#include <iostream>

double harmonic(double, double);

int main() {
  double input_num1, input_num2;

  std::cout << "Enter the two number (seperate by blank): ";
  std::cin >> input_num1 >> input_num2;

  while (input_num1 != 0 || input_num2 != 0) {
    std::cout << "The " << input_num1 << " and " << input_num2
              << " harmonic mean is " << harmonic(input_num1, input_num2)
              << '\n';

    std::cout << "Enter the operand (seperate by blank): ";
    std::cin >> input_num1 >> input_num2;
  }

  return 0;
}

double harmonic(double x, double y) {
  double result = 2.0 * x * y / (x + y);
  return result;
}