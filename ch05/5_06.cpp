#include <iostream>
#include <string>

const std::string Month[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
                             "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

int main() {
  int sale_amount[3][12] = {};
  unsigned sum = 0;

  for (int i = 0; i < 3; i++) {
    std::cout << "Starting " << i + 1 << " year's data.\n";
    for (int j = 0; j < 12; j++) {
      std::cout << "Enter the sale amount of " << Month[j] << " : ";
      std::cin >> sale_amount[i][j];
    }
    std::cout << "End of " << i + 1 << " year's data.\n";
  }

  std::cout << "Input DONE!\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 12; j++) {
      std::cout << Month[j] << " SALE : " << sale_amount[i][j] << '\n';
      sum += sale_amount[i][j];
    }
    std::cout << "Total sale is " << sum << " in " << i + 1 << " year.\n";
  }

  return 0;
}