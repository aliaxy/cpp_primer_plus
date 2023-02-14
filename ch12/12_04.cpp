#include "stack.h"
#include <iostream>

const int MAX = 5;

int main() {
  Stack st(MAX);
  Item item;

  for (int i = 0; i < MAX; i++) {
    std::cout << "Enter a unsigned long number: ";
    std::cin >> item;

    while (std::cin.get() != '\n') {
      continue;
    }

    st.push(item);
    std::cout << "Item pushed.\n";
  }

  Stack st_new(st);

  for (int i = 0; i < MAX; i++) {
    st_new.pop(item);
    std::cout << "Item poped: " << item << '\n';
  }

  std::cout << "Bye\n";

  return 0;
}