#include "classic1.h"
#include <cstddef>
#include <cstring>
#include <iostream>

Cd::Cd(const char *s1, const char *s2, int n, double x) {
  performers = new char[std::strlen(s1) + 1];
  std::strcpy(performers, s1);
  label = new char[std::strlen(s2) + 1];
  std::strcpy(label, s2);
  selections = n;
  playtime = x;
}

Cd::Cd(const Cd &d) {
  performers = new char[std::strlen(d.performers) + 1];
  std::strcpy(performers, d.performers);
  label = new char[std::strlen(d.label) + 1];
  std::strcpy(label, d.label);
  selections = d.selections;
  playtime = d.playtime;
}

Cd::Cd() {
  performers = nullptr;
  label = nullptr;
  selections = 0;
  playtime = 0.0;
}

Cd::~Cd() {
  if (performers != nullptr) {
    delete[] performers;
  }
  if (label != nullptr) {
    delete[] label;
  }
}

void Cd::Report() const {
  if (performers == nullptr || label == nullptr) {
    std::cout << "Error, empty Object.\n";
  } else {
    std::cout << "Performers: " << performers << '\n'
              << "Label: " << label << '\n'
              << "Selections: " << selections << '\n'
              << "Playtime: " << playtime << '\n';
  }
}

Cd &Cd::operator=(const Cd &d) {
  if (this == &d) {
    return *this;
  }
  if (performers != nullptr) {
    delete[] performers;
  }
  if (label != nullptr) {
    delete[] label;
  }
  performers = new char[std::strlen(d.performers) + 1];
  std::strcpy(performers, d.performers);
  label = new char[std::strlen(d.label) + 1];
  std::strcpy(label, d.label);
  selections = d.selections;
  playtime = d.playtime;
  return *this;
}

Classic::Classic() : Cd() { works = nullptr; }

Classic::Classic(const Classic &c) : Cd(c) {
  works = new char[std::strlen(c.works) + 1];
  std::strcpy(works, c.works);
}

Classic::Classic(const char *s1, const char *s2, const char *s3, int n,
                 double x)
    : Cd(s1, s2, n, x) {
  works = new char[std::strlen(s3) + 1];
  std::strcpy(works, s3);
}

Classic::~Classic() { delete[] works; }

void Classic::Report() const {
  Cd::Report();
  if (works != nullptr) {
    std::cout << "Works: " << works << '\n';
  }
}

Classic &Classic::operator=(const Classic &c) {
  if (this == &c) {
    return *this;
  }
  Cd::operator=(c);
  works = new char[std::strlen(c.works) + 1];
  std::strcpy(works, c.works);
  return *this;
}