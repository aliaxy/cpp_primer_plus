#include "complex0.h"
#include <iostream>

int main() {
  complex a(3.0, 4.0);
  complex c;

  std::cout << "Enter a complex number (q to quit):\n";

  while (std::cin >> c) {
    std::cout << "c is " << c << '\n'
              << "complex conjugate is " << ~c << '\n'
              << "a is " << a << '\n'
              << "a + c is " << a + c << '\n'
              << "a - c is " << a - c << '\n'
              << "a * c is " << a * c << '\n'
              << "2 * c is " << 2 * c << '\n'
              << "Enter a complex number (q to quit):\n";
  }

  std::cout << "Done!\n";
  return 0;
}