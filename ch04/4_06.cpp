#include <iostream>

struct CandyBar {
  char brand[20];
  double weight;
  unsigned calorie;
};

int main() {
  CandyBar snack[3] = {{"Mocha Much", 2.3, 350},
                       {"Hershey bar", 4.2, 550},
                       {"Musketeers", 2.6, 430}};

  std::cout << "My 1st CandyBar is " << snack[0].brand << ".\n"
            << "And its weight is " << snack[0].weight << ", calorie is "
            << snack[0].calorie << ".\n";

  std::cout << "My 2nd CandyBar is " << snack[1].brand << ".\n"
            << "And its weight is " << snack[1].weight << ", calorie is "
            << snack[1].calorie << ".\n";

  std::cout << "My 3rd CandyBar is " << snack[2].brand << ".\n"
            << "And its weight is " << snack[2].weight << ", calorie is "
            << snack[2].calorie << ".\n";
  return 0;
}