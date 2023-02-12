#include <iostream>
#include <string>

void strcount(const std::string);

int main() {
  std::string input;
  char next;

  std::cout << "Enter a line:\n";
  std::getline(std::cin, input);

  while (input != "") {
    strcount(input);
    std::cout << "Enter next line (empty line to quit):\n";
    std::getline(std::cin, input);
  }
  std::cout << "Bye\n";

  return 0;
}

void strcount(const std::string str) {
  static int total = 0;
  int count = 0;

  std::cout << "\"" << str << "\" contains ";

  count = str.length();
  total += count;

  std::cout << count << " characters\n" << total << " characters total\n";
}