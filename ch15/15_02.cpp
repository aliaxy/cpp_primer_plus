#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

class bad_hmean : public std::logic_error {
public:
  bad_hmean(const std::string = "HMean, Invalid argument ");
};

class bad_gmean : public std::logic_error {
public:
  bad_gmean(const std::string = "GMean, Invalid argument ");
};

double hmean(double, double);
double gmean(double, double);

int main() {
  double x, y, z;

  std::cout << "Enter two numbers: ";
  while (std::cin >> x >> y) {
    try {
      z = hmean(x, y);
      std::cout << "Harmonic mean of " << x << " and " << y << " is " << z
                << '\n';
      std::cout << "Geometric mean of " << x << " and " << y << " is "
                << gmean(x, y) << '\n';
      std::cout << "Enter next set of numbers <q to quit>: ";
    } catch (bad_hmean &bg) {
      bg.what();
      std::cout << "Try again.\n";
      continue;
    } catch (bad_gmean &hg) {
      std::cout << hg.what();
      std::cout << "Sorry, you don't get to play any more.\n";
      break;
    }
  }

  std::cout << "Bye!\n";

  return 0;
}

bad_hmean::bad_hmean(const std::string what_arg) : std::logic_error(what_arg) {}

bad_gmean::bad_gmean(const std::string what_arg) : std::logic_error(what_arg) {}

double hmean(double a, double b) {
  if (a == -b) {
    throw bad_hmean();
  }
  return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
  if (a < 0 || b < 0) {
    throw bad_gmean();
  }
  return std::sqrt(a * b);
}
