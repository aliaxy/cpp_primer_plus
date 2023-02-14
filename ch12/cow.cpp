#include "cow.h"
#include <cstring>
#include <iostream>

Cow::Cow() {
  name[0] = '\0';
  hobby = nullptr;
  weight = 0.0;
}

Cow::Cow(const char *nm, const char *ho, double wt) {
  std::strncpy(name, nm, 20);
  if (std::strlen(nm) >= 20) {
    name[19] = '\0';
  } else {
    name[std::strlen(nm)] = '\0';
  }
  hobby = new char[std::strlen(ho) + 1];
  std::strcpy(hobby, ho);
  weight = wt;
}

Cow::Cow(const Cow &c) {
  std::strcpy(name, c.name);
  hobby = new char[std::strlen(c.hobby) + 1];
  std::strcpy(hobby, c.hobby);
  weight = c.weight;
}

Cow::~Cow() { delete[] hobby; }

Cow &Cow::operator=(const Cow &c) {
  if (this == &c) {
    return *this;
  }
  if (hobby != nullptr) {
    delete[] hobby;
  }
  hobby = new char[std::strlen(c.hobby) + 1];
  std::strcpy(name, c.name);
  std::strcpy(hobby, c.hobby);
  weight = c.weight;
  return *this;
}

void Cow::ShowCow() const {
  if (hobby == nullptr) {
    std::cout << "This Cow's info is Empty!\n";
    return;
  }

  std::cout << "This is Information of Cow.\n"
            << "Name: " << name << '\n'
            << "Hobby: " << hobby << '\n'
            << "Weight: " << weight << '\n';
}