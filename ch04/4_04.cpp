#include <iostream>
#include <string>

int main() {
  std::string first_name, last_name;
  std::string name;

  std::cout << "Enter your first name: ";
  std::getline(std::cin, first_name);

  std::cout << "Enter your last name: ";
  std::getline(std::cin, last_name);

  name = last_name + ", " + first_name;

  std::cout << "Here's the information in a single string: " << name << '\n';

  return 0;
}