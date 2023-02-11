#include <iostream>

const int DEPOSIT_BASE = 100;

int main() {
  double daphne_deposit = DEPOSIT_BASE;
  double cleo_deposit = DEPOSIT_BASE;

  int year = 0;
  while (daphne_deposit >= cleo_deposit) {
    std::cout << "In " << year++ << " year: Daphne = " << daphne_deposit << '\n'
              << "\tCelo = " << cleo_deposit << '\n';

    daphne_deposit += 0.1 * DEPOSIT_BASE;
    cleo_deposit += 0.05 * cleo_deposit;
  }

  std::cout << "In " << year << " year: Daphne = " << daphne_deposit << '\n'
            << "\tCleo = " << cleo_deposit << '\n';

  return 0;
}