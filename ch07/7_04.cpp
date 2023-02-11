#include <cmath>
#include <iostream>

long double probability(double, double, double);

int main() {
  std::cout << "Field number is 45, and special number is 27.\n";

  std::cout << "The probability is one of the: " << probability(45, 27, 5)
            << '\n';

  return 0;
}

long double probability(double fnumbers, double snumbers, double picks) {
  long double result = 1.0;
  long double n;
  unsigned p;

  for (n = fnumbers, p = picks; p > 0; n--, p--) {
    result *= n / p;
  }
  return result / snumbers;
}