#include <iostream>

int main() {
  double degrees, minutes, seconds;

  std::cout << "Enter a latitude in degree, minutes, and seconds:\n";
  std::cout << "First, enter the degree: ";
  std::cin >> degrees;

  std::cout << "Next, enter the minutes of arc: ";
  std::cin >> minutes;

  std::cout << "Finally, enter the seconds of arc: ";
  std::cin >> seconds;

  double degree_new = degrees + minutes / 60 + seconds / 3600;

  std::cout << degrees << " degrees, " << minutes << " minutes, " << seconds
            << " seconds = " << degree_new << " degrees.\n";

  return 0;
}