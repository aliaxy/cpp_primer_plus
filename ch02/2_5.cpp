#include <iostream>

double celsiu2fahrenit(double celsius) { return celsius * 1.8 + 32.0; }

int main() {
  std::cout << "Please enter a Calsius value: ";

  double celsius;
  std::cin >> celsius;

  std::cout << celsius << " degrees Celsius is " << celsiu2fahrenit(celsius)
            << " degree Fahrenit.\n";
  return 0;
}