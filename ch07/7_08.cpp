#include <iostream>

const int Season = 4;
const char *Sname[] = {"Spring", "Summer", "Fall", "Winter"};

void fill(double[], int);
void show(const double[], int);

int main() {
  double expenses[Season];

  fill(expenses, Season);
  show(expenses, Season);

  return 0;
}

void fill(double arr[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << "Enter " << Sname[i] << " expenses: ";
    std::cin >> arr[i];
  }
}

void show(const double arr[], int size) {
  double total = 0.0;
  std::cout << "\nEXPENSES\n";

  for (int i = 0; i < size; i++) {
    std::cout << Sname[i] << ":$ " << arr[i] << '\n';
    total += arr[i];
  }

  std::cout << "Total Expenses:$ " << total << '\n';
}