#include "vect.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(std::time(nullptr));
  double direction;
  VECTOR::Vector step;
  VECTOR::Vector result(0.0, 0.0);
  unsigned long steps = 0;
  double target;
  double dstep;

  unsigned long Max = 0;
  unsigned long Min = 0;
  unsigned long Sum = 0;
  unsigned int count = 0;

  std::cout << "Enter target distance (q to quit): ";
  while (std::cin >> target) {
    std::cout << "Enter step length: ";
    if (!(std::cin >> dstep)) {
      break;
    }

    while (result.magval() < target) {
      direction = std::rand() % 360;
      step.reset(dstep, direction, VECTOR::Vector::POL);
      result = result + step;
      steps++;
    }
    std::cout << "After " << steps << " steps, the subject "
              << "has the following locations:\n"
              << result << '\n';
    result.polar_mode();
    std::cout << " or\n"
              << "Acerage outward distance per step = "
              << result.magval() / steps << '\n';

    if (Max < steps) {
      Max = steps;
    }
    if (Min > steps) {
      Min = steps;
    }
    Sum += steps;
    count++;
    steps = 0;
    result.reset(0.0, 0.0);
    std::cout << "Enter target distance (q to quit): ";
  }

  std::cout << "Your input " << count << " times, and statistics info:\n"
            << "Max Step = " << Max << '\n'
            << "Min Step = " << Min << '\n'
            << "Average Step = " << Sum / count << '\n';

  std::cout << "Bye!\n";
  std::cin.clear();
  while (std::cin.get() != '\n') {
    continue;
  }

  return 0;
}