#include <array>
#include <iostream>

int main() {
  std::array<double, 3> record_list;
  double average;

  std::cout << "Please input three record of 40 miles.\n";

  std::cout << "First record: ";
  std::cin >> record_list[0];

  std::cout << "Second record: ";
  std::cin >> record_list[1];

  std::cout << "Third record: ";
  std::cin >> record_list[2];

  std::cout << "Ok, you input:\n1. " << record_list[0] << "\n2. "
            << record_list[1] << "\n3. " << record_list[2] << '\n';

  average = (record_list[0] + record_list[1] + record_list[2]) / 3;

  std::cout << "Congratulate, your average performance is " << average << ".\n";

  return 0;
}