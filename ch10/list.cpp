#include "list.h"
#include <iostream>

List::List() { top = 0; }

bool List::isempty() const { return top == 0; }

bool List::isfull() const { return top == MAX; }

bool List::add(const Item &item) {
  if (top < MAX) {
    items[top++] = item;
    return true;
  } else {
    return false;
  }
}

void List::visit(void (*pf)(Item &)) {
  for (int i = 0; i < top; i++) {
    pf(items[i]);
  }
}

void visit_Item(Item &item) {
  std::cout << "The Item's info: " << item << '\n';
}