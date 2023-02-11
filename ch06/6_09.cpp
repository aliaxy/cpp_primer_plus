#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

struct patrons {
  std::string full_name;
  double fund;
};

int main() {
  std::ifstream fin;
  std::string file_name;

  std::cout << "Enter the file name: ";
  std::getline(std::cin, file_name);

  fin.open(file_name);

  if (!fin.is_open()) {
    std::cout << "Error to open file.\n";
    std::exit(EXIT_FAILURE);
  }

  int patrons_number;
  patrons *ppatrons;
  int id = 0;
  bool empty = true;

  fin >> patrons_number;
  if (patrons_number <= 0) {
    std::exit(EXIT_FAILURE);
  }

  ppatrons = new patrons[patrons_number];
  fin.get();

  while (!fin.eof() && id < patrons_number) {
    std::getline(fin, ppatrons[id].full_name);
    std::cout << "Read Name: " << ppatrons[id].full_name << '\n';
    fin >> ppatrons[id].fund;
    std::cout << "Read fund: " << ppatrons[id].fund << '\n';

    fin.get();
    id++;
  }

  fin.close();

  std::cout << "Grand Patrons\n";

  for (int i = 0; i < patrons_number; i++) {
    if (ppatrons[i].fund >= 10000) {
      std::cout << ppatrons[i].full_name << " : " << ppatrons[i].fund << '\n';
      empty = false;
    }
  }

  if (empty) {
    std::cout << "NONE\n";
  }

  empty = true;
  std::cout << "Patrons\n";
  for (int i = 0; i < patrons_number; i++) {
    if (ppatrons[i].fund < 10000) {
      std::cout << ppatrons[i].full_name << " : " << ppatrons[i].fund << '\n';
      empty = false;
    }
  }

  if (empty) {
    std::cout << "NONE\n";
  }

  delete[] ppatrons;

  return 0;
}