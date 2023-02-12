#include "sales.h"
#include <iostream>

int main() {
  SALES::Sales s1, s2;
  double de[SALES::QUARTERS] = {12, 23, 45, 67};

  SALES::setSales(s1, de, SALES::QUARTERS);
  SALES::showSales(s1);

  SALES::setSales(s2);
  SALES::showSales(s2);

  return 0;
}