#include <iostream>

const int Max = 5;

double *fill_array(double *, double *);
void show_array(double *, double *);
void revalue(double, double *, double *);

int main() {
  double properties[Max];
  double *pend = fill_array(properties, properties + Max);

  show_array(properties, pend);
  if (pend - properties > 0) {
    std::cout << "Enter revalue factor: ";
    double factor;
    while (!(std::cin >> factor)) {
      std::cin.clear();
      while (std::cin.get() != '\n') {
        continue;
      }
      std::cout << "bad input; Please input a number: ";
    }
    revalue(factor, properties, pend);
    show_array(properties, pend);
  }

  std::cout << "Done.\n";

  return 0;
}

double *fill_array(double *begin, double *end) {
  double temp, *p;
  for (p = begin; p != end; p++) {
    std::cout << "Enter value #" << (p - begin) + 1 << ": ";
    std::cin >> temp;
    if (!std::cin) {
      while (std::cin.get() != '\n') {
        continue;
      }
      std::cout << "bad input; input porcess terminated.\n";
      break;
    } else if (temp < 0) {
      break;
    }
    *p = temp;
  }
  return p;
}

void show_array(double *begin, double *end) {
  for (double *p = begin; p != end; p++) {
    std::cout << "Property #" << (p - begin) + 1 << ":$";
    std::cout << *p << '\n';
  }
}

void revalue(double r, double *begin, double *end) {
  for (double *p = begin; p != end; p++) {
    *p = r;
  }
}