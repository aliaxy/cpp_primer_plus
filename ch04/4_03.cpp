#include <cstring>
#include <iostream>

int main() {
  char first_name[20], last_name[20];
  char name[40];

  std::cout << "Enter your first name: ";
  std::cin >> first_name;

  std::cout << "Enter your last name: ";
  std::cin >> last_name;

  std::strcpy(name, last_name);
  std::strcat(name, ", ");
  std::strcat(name, first_name);

  std::cout << "Here's the information in a single string: " << name << ".\n";

  return 0;
}