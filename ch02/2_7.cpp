#include <iostream>

void display_time(int hours, int minutes) {
  std::cout << "Time: " << hours << ':' << minutes << '\n';
  return;
}

int main() {
  int hours, minutes;
  std::cout << "Enter the number of hours: ";
  std::cin >> hours;

  std::cout << "Enter the number of minutes: ";
  std::cin >> minutes;

  display_time(hours, minutes);

  return 0;
}