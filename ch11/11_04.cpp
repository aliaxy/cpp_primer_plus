#include "mytime.h"
#include <iostream>

int main() {
  Time aida(3, 35);
  Time tosca(2, 48);
  Time temp;

  std::cout << "Aida and Tosca:\n";
  std::cout << aida << ", " << tosca << '\n';

  temp = aida + tosca;
  std::cout << "Aida + Tosca: " << temp << '\n';

  temp = aida * 1.17;
  std::cout << "Aida * 1.17: " << temp << '\n';
  std::cout << "10.0 * Tosca: " << 10.0 * tosca << '\n';

  return 0;
}