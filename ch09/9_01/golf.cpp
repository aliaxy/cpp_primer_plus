#include "golf.h"
#include <cstring>
#include <iostream>

void setgolf(golf &g, const char *name, int hc) {
  std::strcpy(g.fullname, name);
  g.headicap = hc;
}

int setgolf(golf &g) {
  char name[Len];
  int hc;

  std::cout << "Please enter the name: ";
  std::cin.getline(name, Len);

  std::cout << "Please enter the handicap: ";
  while (!(std::cin >> hc)) {
    std::cin.clear();
    while (std::cin.get() != '\n') {
      continue;
    }
    std::cout << "Please enter the golf's handicap: ";
  }

  if (name[0] != '\0') {
    setgolf(g, name, hc);
    return 1;
  } else {
    return 0;
  }
}

void handicap(golf &g, int hc) { g.headicap = hc; }

void showgolf(const golf &g) {
  std::cout << "Name : " << g.fullname << ", Handicap is " << g.headicap
            << '\n';
}