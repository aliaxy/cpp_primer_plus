#include <iostream>
#include <string>

const std::string Month[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
                             "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

int main() {
  int sale_amount[12] = {};
  unsigned sum = 0;

  for (int i = 0; i < 12; i++) {
    std::cout << "Enter the sale amount of " << Month[i] << " : ";
    std::cin >> sale_amount[i];
  }

  std::cout << "Input DONE!\n";

  for (int i = 0; i < 12; i++) {
    std::cout << Month[i] << " SALE : " << sale_amount[i] << '\n';
    sum += sale_amount[i];
  }

  std::cout << "Total sale is " << sum << " this year.\n";

  return 0;
}