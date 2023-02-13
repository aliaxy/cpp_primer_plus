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
              << result << '\n'
              << "Average outward distance per step = "
              << result.magval() / steps << '\n';
    steps = 0;
    result.reset(0.0, 0.0);
    std::cout << "Enter target distance (q to quit): ";
  }
  std::cout << "Bye!\n";

  return 0;
}