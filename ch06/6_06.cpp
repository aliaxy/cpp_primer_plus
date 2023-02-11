#include <iostream>
#include <string>

struct patrons {
  std::string full_name;
  double fund;
};

int main() {
  int patrons_number;
  patrons *ppartrons;

  std::cout << "How many patrons? ";
  std::cin >> patrons_number;
  std::cin.get();

  ppartrons = new patrons[patrons_number];

  int id = 0;
  bool empty = true;

  std::cout << "Starting to input patrons' info:\n";

  while (id < patrons_number) {
    std::cout << "Enter the full name of partrons: ";
    std::getline(std::cin, ppartrons[id].full_name);

    std::cout << "Enter the fund of " << ppartrons[id].full_name << " : ";
    std::cin >> ppartrons[id].fund;
    std::cin.get();

    id++;
    std::cout << "Continue to input, or press (f) to finished.\n";
    if (std::cin.get() == 'f') {
      break;
    }
  }

  std::cout << "Grand Patrons\n";

  for (int i = 0; i < patrons_number; i++) {
    if (ppartrons[i].fund >= 1000) {
      std::cout << ppartrons[i].full_name << " : " << ppartrons[i].fund << '\n';
      empty = false;
    }
  }

  if (empty) {
    std::cout << "NONE\n";
  }

  empty = true;
  std::cout << "Patrons\n";
  for (int i = 0; i < patrons_number; i++) {
    if (ppartrons[i].fund < 1000) {
      std::cout << ppartrons[i].full_name << " : " << ppartrons[i].fund << '\n';
      empty = false;
    }
  }

  if (empty) {
    std::cout << "NONE\n";
  }

  return 0;
}