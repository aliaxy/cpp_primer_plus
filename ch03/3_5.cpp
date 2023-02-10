#include <iostream>

int main() {
  long long population_world, population_China;

  std::cout << "Enter the world's population: ";
  std::cin >> population_world;

  std::cout << "Enter the population of China: ";
  std::cin >> population_China;

  double rate = (double)population_China / population_world * 100;

  std::cout << "The population of China is " << rate
            << "% of the world population.\n";
  return 0;
}