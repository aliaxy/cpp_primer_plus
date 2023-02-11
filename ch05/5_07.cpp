#include <iostream>
#include <string>

struct car_info {
  std::string manufacturer;
  int date;
};

int main() {
  int car_number;
  car_info *pcar;

  std::cout << "How many cars do you wish to catalog? ";
  std::cin >> car_number;
  std::cin.get();
  pcar = new car_info[car_number];

  for (int i = 0; i < car_number; i++) {
    std::cout << "Car #" << i + 1 << ":\n";

    std::cout << "Please enter the maker: ";
    std::getline(std::cin, pcar[i].manufacturer);

    std::cout << "Please enter the year made: ";
    std::cin >> pcar[i].date;

    std::cin.get();
  }

  std::cout << "Here is you collection:\n";

  for (int i = 0; i < car_number; i++) {
    std::cout << pcar[i].date << ' ' << pcar[i].manufacturer << '\n';
  }

  return 0;
}