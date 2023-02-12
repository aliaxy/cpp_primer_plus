#include <cctype>
#include <iostream>
#include <string>

void uppercase(std::string &);

int main() {
  std::string st;

  std::cout << "Enter a string (q to quit): ";
  std::getline(std::cin, st);

  while (st != "q") {
    uppercase(st);

    std::cout << st << '\n';
    std::cout << "Next string (q to quit): ";

    std::getline(std::cin, st);
  }

  return 0;
}

void uppercase(std::string &s) {
  for (int i = 0; i < s.size(); i++) {
    s[i] = std::toupper(s[i]);
  }
}