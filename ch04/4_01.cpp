#include <iostream>

int main() {
  char first_name[40], last_name[40], grade;
  int age;

  std::cout << "What is your first name? ";
  std::cin.getline(first_name, 40);

  std::cout << "What is your last name? ";
  std::cin.getline(last_name, 40);

  std::cout << "What letter grade do you deserve? ";
  std::cin >> grade;

  std::cout << "What is your age? ";
  std::cin >> age;

  std::cout << "Name: " << last_name << ", " << first_name << '\n'
            << "Grade: " << char(grade + 1) << '\n'
            << "Age: " << age << '\n';

  return 0;
}