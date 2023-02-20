#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

class unexpected_mean : public std::logic_error {
private:
  double v1;
  double v2;

public:
  unexpected_mean(double = 0, double = 0, std::string = "mean error");
  virtual void mesg() = 0;
};

class bad_hmean : public unexpected_mean {
public:
  bad_hmean(double = 0, double = 0, std::string = "HMean");
  void mesg();
};

class bad_gmean : public unexpected_mean {
public:
  bad_gmean(double = 0, double = 0, std::string = "GMean");
  void mesg();
};

double hmean(double, double);
double gmean(double, double);

int main() {
  double x, y, z;

  std::cout << "Enter two numbers: ";
  while (std::cin >> x >> y) {
    try {
      std::cout << "Harmonic mean of " << x << " and " << y << " is "
                << hmean(x, y) << '\n'
                << "Geometric mean of " << x << " and " << y << " is "
                << gmean(x, y) << '\n';
      std::cout << "Enter next set of numbers <q to quit>: ";
    } catch (unexpected_mean &bg) {
      if (typeid(bg) == typeid(bad_hmean)) {
        bad_hmean *ph = dynamic_cast<bad_hmean *>(&bg);
        ph->mesg();
      } else if (typeid(bg) == typeid(bad_gmean)) {
        bad_gmean *pg = dynamic_cast<bad_gmean *>(&bg);
        pg->mesg();
      }
      std::cout << "Try again.\n";
      continue;
    }
  }

  std::cout << "Bye!\n";

  return 0;
}

inline void unexpected_mean::mesg() { std::cout << v1 << ' ' << v2 << '\n'; }

unexpected_mean::unexpected_mean(double a, double b, std::string s)
    : v1(a), v2(b), std::logic_error(s) {}

bad_hmean::bad_hmean(double a, double b, std::string s)
    : unexpected_mean(a, b, s) {}

inline void bad_hmean::mesg() {
  std::cout << "bad_HMean() now!\n"
            << what() << '\n'
            << "Hmean invalid arguments\n";
  unexpected_mean::mesg();
}

bad_gmean::bad_gmean(double a, double b, std::string s)
    : unexpected_mean(a, b, s) {}

inline void bad_gmean::mesg() {
  std::cout << "bad_GMean() now!\n"
            << what() << '\n'
            << "Gmean invalid arguments\n";
  unexpected_mean::mesg();
}

double hmean(double a, double b) {
  if (a == -b) {
    throw bad_hmean(a, b);
  }
  return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
  if (a < 0 || b < 0) {
    throw bad_gmean(a, b);
  }
  return std::sqrt(a * b);
}