#include <iostream>

const double Km2Mile = 0.6214;
const double Gallon2Litre = 3.875;

int main() {
  double fuel_en;
  std::cout << "Enter the fuel consumption in European standard: ";
  std::cin >> fuel_en;

  double fuel_us = (100 * Km2Mile) / (fuel_en / Gallon2Litre);

  std::cout << "The fuel consumption in US standatd is " << fuel_us
            << " Miles/Gallon.\n";

  return 0;
}