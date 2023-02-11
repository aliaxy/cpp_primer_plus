#include <cstring>
#include <iostream>

const int strsize = 40;
const int usersize = 40;

struct bop {
  char fullname[strsize];
  char title[strsize];
  char bopname[strsize];
  int preference;
};

bop bop_user[usersize] = {{"Wimp Macho", "Programmer", "MIPS", 0},
                          {"Raki Rhodes", "Junior Programmer", "", 1},
                          {"Celia Laiter", "", "MIPS", 2},
                          {"Hoppy Hipman", "Analyst Trainee", "", 1},
                          {"Pat Hand", "", "LOOPY", 2}};

void showmenu();
void print_by_name();
void print_by_pref();
void print_by_title();
void print_by_bopname();
void create_info();

int main() {
  char choice;
  // create_info();
  showmenu();
  std::cin.get(choice);

  while (choice != 'q') {
    switch (choice) {
    case 'a':
      print_by_name();
      break;
    case 'b':
      print_by_title();
      break;
    case 'c':
      print_by_bopname();
      break;
    case 'd':
      print_by_pref();
      break;
    default:
      std::cout << "Please enter character a, b, c, d, or q: ";
    }

    std::cin.get();
    std::cout << "Next choice: ";
    std::cin.get(choice);
  }

  std::cout << "Bye!\n";

  return 0;
}

void showmenu() {
  std::cout << "a. display by name \t\tb. display by title\n"
            << "c. display by bopname \t\td. display bt preference\n"
            << "q. quit\n";
}

void print_by_name() {
  for (int i = 0; i < usersize; i++) {
    if (std::strlen(bop_user[i].fullname) == 0) {
      break;
    } else {
      std::cout << bop_user[i].fullname << '\n';
    }
  }
}

void print_by_pref() {
  for (int i = 0; i < usersize; i++) {
    if (std::strlen(bop_user[i].fullname) == 0) {
      break;
    } else {
      switch (bop_user[i].preference) {
      case 0:
        std::cout << bop_user[i].fullname << '\n';
      case 1:
        std::cout << bop_user[i].title << '\n';
      case 2:
        std::cout << bop_user[i].bopname << '\n';
      }
    }
  }
}

void print_by_title() {
  for (int i = 0; i < usersize; i++) {
    if (std::strlen(bop_user[i].fullname) == 0) {
      break;
    } else {
      std::cout << bop_user[i].title << '\n';
    }
  }
}

void print_by_bopname() {
  for (int i = 0; i < usersize; i++) {
    if (std::strlen(bop_user[i].fullname) == 0) {
      break;
    } else {
      std::cout << bop_user[i].bopname << '\n';
    }
  }
}

void create_info() {
  for (int i = 0; i < usersize; i++) {
    std::cout << "Enter the user's full name: ";
    std::cin.getline(bop_user[i].fullname, strsize);

    std::cout << "Enter the user's title: ";
    std::cin.getline(bop_user[i].title, strsize);

    std::cout << "Enter the user's bopname: ";
    std::cin.getline(bop_user[i].bopname, strsize);

    std::cout << "Enter thr user's preference: ";
    std::cin >> bop_user[i].preference;

    std::cin.get();
    if (std::cin.get() == 'f') {
      break;
    }
  }
}