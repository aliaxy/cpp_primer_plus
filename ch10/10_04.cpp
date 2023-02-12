#include <iostream>

const int QUARTERS = 4;

class Sales {
private:
  double sales[QUARTERS];
  double average;
  double max;
  double min;

public:
  Sales();
  Sales(const double[], int);
  ~Sales() = default;
  void showSales() const;
};

int main() {
  double de[QUARTERS] = {12, 23, 45, 67};
  Sales s1{de, QUARTERS};
  Sales s2;

  s1.showSales();
  s2.showSales();

  return 0;
}

Sales::Sales() {
  double sum = 0;

  int i = 0;
  do {
    std::cout << "Enter a number: ";
    if (!(std::cin >> sales[i])) {
      std::cin.clear();
      while (std::cin.get() != '\n') {
        continue;
      }
      std::cout << "ERROR, Reenter a number: ";
      std::cin >> sales[i];
    }
    i++;
  } while (i < QUARTERS);

  max = min = sales[0];
  for (int i = 0; i < QUARTERS; i++) {
    sum += sales[i];
    if (min > sales[i]) {
      min = sales[i];
    }
    if (max < sales[i]) {
      max = sales[i];
    }
  }
  average = sum / QUARTERS;
}

Sales::Sales(const double ar[], int n) {
  double sum = 0;
  if (n >= QUARTERS) {
    for (int i = 0; i < QUARTERS; i++) {
      sales[i] = ar[i];
    }
  } else {
    for (int i = 0; i < n; i++) {
      sales[i] = ar[i];
    }
    for (int i = n; i < QUARTERS; i++) {
      sales[i] = 0;
    }
  }

  max = min = sales[0];
  for (int i = 0; i < QUARTERS; i++) {
    sum += sales[i];
    if (min > sales[i]) {
      min = sales[i];
    }
    if (max < sales[i]) {
      max = sales[i];
    }
  }
  average = sum / QUARTERS;
}

void Sales::showSales() const {
  std::cout << "This Sales' quarter list info:\n";
  for (int i = 0; i < QUARTERS; i++) {
    std::cout << "No." << i + 1 << ": sales: " << sales[i] << '\n';
  }
  std::cout << "AVERAGE: " << average << '\n'
            << "MAX: " << max << '\n'
            << "MIN: " << min << '\n';
}