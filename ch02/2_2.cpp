#include <iostream>

int main() {
  int distance;

  std::cout << "Please input a distance number in the unit of Long: ";
  std::cin >> distance;

  int yard = distance * 220;

  std::cout << "The distance transform in yard is: " << yard << '\n';

  return 0;
}