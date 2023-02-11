#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream fin;
  std::string file_name;

  std::cout << "Enter the file name: ";
  std::getline(std::cin, file_name);

  fin.open(file_name);

  if (!fin.is_open()) {
    std::cerr << "Error to open file.\n";
    std::exit(EXIT_FAILURE);
  }

  char read_char;
  int char_conter = 0;

  while (!fin.eof()) {
    fin >> read_char;
    char_conter++;
  }

  std::cout << "The file " << file_name << " contains " << char_conter
            << " characters.\n";

  fin.close();

  return 0;
}