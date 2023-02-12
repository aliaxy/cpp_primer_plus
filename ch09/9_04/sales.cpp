#include "sales.h"
#include <iostream>

void SALES::setSales(Sales &s, const double ar[], int n) {
  double sum = 0;
  if (n >= QUARTERS) {
    for (int i = 0; i < QUARTERS; i++) {
      s.sales[i] = ar[i];
    }
  } else {
    for (int i = 0; i < n; i++) {
      s.sales[i] = ar[i];
    }
    for (int i = n; i < QUARTERS; i++) {
      s.sales[i] = 0;
    }
  }

  s.max = s.min = s.sales[0];
  for (int i = 0; i < QUARTERS; i++) {
    sum += s.sales[i];
    if (s.min > s.sales[i]) {
      s.min = s.sales[i];
    }
    if (s.max < s.sales[i]) {
      s.max = s.sales[i];
    }
  }
  s.average = sum / QUARTERS;
}

void SALES::setSales(Sales &s) {
  double ar[QUARTERS] = {};

  int i = 0;
  do {
    std::cout << "Enter a number: ";
    if (!(std::cin >> ar[i])) {
      std::cin.clear();
      while (std::cin.get() != '\n') {
        continue;
      }
      std::cout << "ERROR, Reenter a number: ";
      std::cin >> ar[i];
    }
    i++;
  } while (i < QUARTERS);

  setSales(s, ar, QUARTERS);
}

void SALES::showSales(const Sales &s) {
  std::cout << "This Sales' quarter list info:\n";
  for (int i = 0; i < QUARTERS; i++) {
    std::cout << "No." << i + 1 << ": sales: " << s.sales[i] << '\n';
  }
  std::cout << "AVERAGE: " << s.average << '\n'
            << "MAX: " << s.max << '\n'
            << "MIN: " << s.min << '\n';
}