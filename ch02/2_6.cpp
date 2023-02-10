#include <iostream>

double light_years2astromonical_unit(double light_years) {
  return light_years * 63240;
}

int main() {
  std::cout << "Enter the number of light years: ";

  double light_years;
  std::cin >> light_years;

  std::cout << light_years
            << " light years = " << light_years2astromonical_unit(light_years)
            << " astromonical units.\n";

  return 0;
}