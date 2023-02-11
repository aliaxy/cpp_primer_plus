#include <array>
#include <iostream>

int main() {
  std::array<double, 10> donation;
  double input;
  int counter = 0;
  double average, sum = 0;
  int bigger = 0;

  std::cout << "Enter the double numerial: ";
  std::cin >> input;

  while (input != 0 && counter < 10) {
    donation[counter++] = input;
    std::cout << "No." << counter << " Data input to Array.\n";
    std::cout << "Enter the double numerial: ";
    std::cin >> input;
  }

  for (int i = 0; i < counter; i++) {
    sum += donation[i];
  }

  average = sum / counter;

  for (int i = 0; i < counter; i++) {
    if (donation[i] > average) {
      bigger++;
    }
  }

  std::cout << "The Average is " << average << " and " << bigger
            << " data bigger than average.\n";

  return 0;
}