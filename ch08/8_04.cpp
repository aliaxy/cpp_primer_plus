#include <cstring>
#include <iostream>
#include <string>

struct stringy {
  char *str;
  int ct;
};

void show(const std::string &, int n = 0);
void show(const stringy &, int n = 0);
void set(stringy &, char *);

int main() {
  stringy beany;
  char testing[] = "Reality isn't what it used to be.";

  set(beany, testing);
  show(beany);
  show(beany, 2);

  testing[0] = 'D';
  testing[1] = 'u';

  show(testing);
  show(testing, 3);
  show("Done!");

  delete beany.str;

  return 0;
}

void show(const std::string &st, int n) {
  if (n == 0) {
    n++;
  }
  for (int i = 0; i < n; i++) {
    std::cout << st << '\n';
  }
}

void show(const stringy &sty, int n) {
  if (n == 0) {
    n++;
  }
  for (int i = 0; i < n; i++) {
    std::cout << sty.str << '\n';
  }
}

void set(stringy &sty, char *st) {
  sty.ct = std::strlen(st);
  sty.str = new char[sty.ct];

  std::strcpy(sty.str, st);
}