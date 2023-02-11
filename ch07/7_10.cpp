#include <iostream>

double add(double, double);

double substract(double, double);

double calculate(double, double, double (*)(double, double));

int main() {
  double q = calculate(2.5, 10.4, add);
  std::cout << "The Answer of add is " << q << '\n';

  double t = calculate(2.5, 10.4, substract);
  std::cout << "The Answer of substract is " << t << '\n';

  return 0;
}

double add(double x, double y) { return x + y; }

double substract(double x, double y) { return x - y; }

double calculate(double x, double y, double (*pf)(double x1, double x2)) {
  return pf(x, y);
}