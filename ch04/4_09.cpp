#include <cstring>
#include <iostream>

struct CandyBar {
  char brand[20];
  double weight;
  unsigned calorie;
};

int main() {
  CandyBar *pc = new CandyBar[3];

  std::strcpy(pc[0].brand, "Mocha Munch");
  pc[0].weight = 2.3;
  pc[0].calorie = 350;

  std::strcpy(pc[1].brand, "Hershey bar");
  pc[1].weight = 4.2;
  pc[1].calorie = 550;

  std::strcpy(pc[2].brand, "Musketeers");
  pc[2].weight = 2.6;
  pc[2].calorie = 430;

  std::cout << "My 1st CandyBar is " << pc->brand << ".\n"
            << "And its weight is " << pc->weight << ", calorie is "
            << pc->calorie << ".\n";

  std::cout << "My 2nd CandyBar is " << (pc + 1)->brand << ".\n"
            << "And its weight is " << (pc + 1)->weight << ", calorie is "
            << (pc + 1)->calorie << ".\n";

  std::cout << "My 3rd CandyBar is " << (pc + 2)->brand << ".\n"
            << "And its weight is " << (pc + 2)->weight << ", calorie is "
            << (pc + 2)->calorie << ".\n";

  delete[] pc;

  return 0;
}