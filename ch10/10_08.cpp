#include "list.h"
#include <iostream>

void visit_Item(Item &);

int main() {
  List list;
  Item item = 0;

  std::cout << "Enter the unsigned long number: ";
  std::cin >> item;

  while (item != 0) {
    std::cin.get();
    list.add(item);

    std::cout << "Enter the unsigned long number: ";
    std::cin >> item;
  }

  std::cout << "Now end of add element, start to visit:\n";
  list.visit(visit_Item);

  return 0;
}