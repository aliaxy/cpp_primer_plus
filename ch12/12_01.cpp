#include "cow.h"
#include <cstring>
#include <iostream>

int main() {
  std::cout << "Initialize, and show No.1:\n";

  Cow cow_list[2] = {{"Tom", "Sleeppy", 200}};
  cow_list[0].ShowCow();

  std::cout << "No.2 's default values: \n";
  cow_list[1].ShowCow();

  std::cout << "Now using operator=(). to init No.2\n";
  cow_list[1] = cow_list[0];
  cow_list[1].ShowCow();

  std::cout << "Now, using copy constructor to init No.3.\n";
  Cow copy(cow_list[0]);
  copy.ShowCow();

  return 0;
}