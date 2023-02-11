#include <iostream>

void showmenu();

int main() {
  char choice;
  showmenu();
  std::cin.get(choice);

  while (choice != 'c' && choice != 'p' && choice != 't' && choice != 'g') {
    std::cin.get();
    std::cout << "Please enter a c, p, t or g: ";
    std::cin.get(choice);

    switch (choice) {
    case 'c':
      break;
    case 'p':
      break;
    case 't':
      std::cout << "A maple is a tree.\n";
      break;
    case 'g':
      break;
    }
  }

  return 0;
}

void showmenu() {
  std::cout << "Please enter one of the following choices:\n"
            << "c) carnivore\t\t\tp) pianist\n"
            << "t) tree\t\t\t\tg) game\n";
}