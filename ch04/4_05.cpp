#include <iostream>
#include <string>

struct CandyBar {
  std::string name;
  double weight;
  int calories;
};

int main() {
  CandyBar snack = {"Mocha Munch", 2.3, 350};

  std::cout << "The name of the CandyBar: " << snack.name << '\n'
            << "The weight of the CandyBar: " << snack.weight << '\n'
            << "The calories of the CandyBar: " << snack.calories << '\n';

  return 0;
}