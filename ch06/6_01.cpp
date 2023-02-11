#include <cctype>
#include <iostream>

int main() {
  char input;

  std::cout << "Enter the character: ";
  std::cin.get(input);
  while (input != '@') {
    if (std::isdigit(input)) {
      std::cin.get(input);
      continue;
    } else if (std::islower(input)) {
      input = std::toupper(input);
    } else if (std::isupper(input)) {
      input = std::tolower(input);
    }
    std::cout << input;
    std::cin.get(input);
  }

  return 0;
}