#include <iostream>

long long factorial(int);

int main() {
  int n;

  std::cout << "Enter a number to calc factorial: ";
  std::cin >> n;

  while (n > 0) {
    std::cout << n << "! = " << factorial(n) << '\n';
    std::cout << "Enter a number to calc factorial: ";
    std::cin >> n;
  }

  std::cout << "DONE!\n";

  return 0;
}

long long factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}