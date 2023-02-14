#include "classic0.h"
#include <cstring>
#include <iostream>

Cd::Cd(const char *s1, const char *s2, int n, double x) {
  std::strncpy(performers, s1, 50);
  if (std::strlen(s1) >= 50) {
    performers[40] = '\0';
  } else {
    performers[std::strlen(s1)] = '\0';
  }
  std::strncpy(label, s2, 20);
  if (std::strlen(s2) >= 20) {
    label[19] = '\0';
  } else {
    label[std::strlen(s2)] = '\0';
  }
  selections = n;
  playtime = x;
}

Cd::Cd(const Cd &d) {
  std::strcpy(performers, d.performers);
  std::strcpy(label, d.label);
  selections = d.selections;
  playtime = d.playtime;
}

Cd::Cd() {
  performers[0] = '\0';
  label[0] = '\0';
  selections = 0;
  playtime = 0.0;
}

Cd::~Cd() {}

void Cd::Report() const {
  std::cout << "Performers: " << performers << '\n'
            << "Label: " << label << '\n'
            << "Selections: " << selections << '\n'
            << "Playtime: " << playtime << '\n';
}

Cd &Cd::operator=(const Cd &d) {
  if (this == &d) {
    return *this;
  }
  std::strcpy(performers, d.performers);
  std::strcpy(label, d.label);
  selections = d.selections;
  playtime = d.playtime;
  return *this;
}

Classic::Classic() : Cd() { works[0] = '\0'; }

Classic::Classic(const Classic &c) : Cd(c) { std::strcpy(works, c.works); }

Classic::Classic(const char *s1, const char *s2, const char *s3, int n,
                 double x)
    : Cd(s1, s2, n, x) {
  std::strncpy(works, s2, 50);
  if (std::strlen(s3) >= 50) {
    works[49] = '\0';
  } else {
    works[std::strlen(s3)] = '\0';
  }
}

Classic::~Classic() {}

void Classic::Report() const {
  Cd::Report();
  std::cout << "Works: " << works << '\n';
}

Classic &Classic::operator=(const Classic &c) {
  if (this == &c) {
    return *this;
  }
  Cd::operator=(c);
  std::strcpy(works, c.works);
  return *this;
}