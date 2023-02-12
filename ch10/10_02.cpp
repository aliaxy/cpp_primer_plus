#include <cstring>
#include <iostream>
#include <string>

class Person {
private:
  static const int LIMIT = 25;
  std::string lname;
  char fname[LIMIT];

public:
  Person();
  Person(const std::string &, const char * = "Heyyou");
  void Show() const;
  void FormalShow() const;
};

int main() {
  Person one;
  Person two("Smythecraft");
  Person three("Dimwiddy", "Sam");

  std::cout << '\n';
  one.FormalShow();
  two.FormalShow();
  three.FormalShow();

  return 0;
}

Person::Person() {
  lname = "";
  fname[0] = '\0';
}

Person::Person(const std::string &ln, const char *fn) {
  lname = ln;
  std::strcpy(fname, fn);
}

void Person::Show() const {
  if (lname == "" && fname[0] == '\0') {
    std::cout << "No Name.\n";
  } else {
    std::cout << "Person Name: " << fname << "." << lname << '\n';
  }
}

void Person::FormalShow() const {
  if (lname == "" && fname[0] == '\0') {
    std::cout << "No Name.\n";
  } else {
    std::cout << "Person Name: " << lname << "." << fname << '\n';
  }
}