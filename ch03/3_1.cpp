#include <iostream>

const int foot2inch = 12;

int main() {
  std::cout << "Please input your height in inch: __\b\b";

  int height;
  std::cin >> height;

  int height_foot = height / foot2inch;
  int height_inch = height % foot2inch;

  std::cout << "Your height in inch is: " << height
            << "; transforming in foot and inch is: " << height_foot << " foot "
            << height_inch << " inch.\n";

  return 0;
}