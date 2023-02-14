#include "vintageport.h"
#include <cstring>

Port::Port(const char *br, const char *st, int b) {
  brand = new char[std::strlen(br) + 1];
  std::strcpy(brand, br);
  std::strcpy(style, st);
  bottles = b;
}

Port::Port(const Port &p) {
  brand = new char[std::strlen(p.brand) + 1];
  std::strcpy(brand, p.brand);
  std::strcpy(style, p.style);
  bottles = p.bottles;
}

Port::~Port() { delete[] brand; }

Port &Port::operator=(const Port &p) {
  if (this == &p) {
    return *this;
  }
  delete[] brand;
  brand = new char[std::strlen(p.brand) + 1];
  std::strcpy(brand, p.brand);
  std::strcpy(style, p.style);
  bottles = p.bottles;
  return *this;
}

Port &Port::operator+=(int b) {
  bottles += b;
  return *this;
}

Port &Port::operator-=(int b) {
  bottles -= b;
  return *this;
}

int Port::BottleCount() const { return bottles; }

void Port::Show() const {
  std::cout << "Brand: " << brand << '\n'
            << "Kind: " << style << '\n'
            << "Botttles: " << bottles << '\n';
}

std::ostream &operator<<(std::ostream &os, const Port &p) {
  os << p.brand << ", " << p.style << ", " << p.bottles;
  return os;
}

Vintageport::Vintageport() : Port() {
  nickname = new char[5];
  std::strcpy(nickname, "none");
  year = 0;
}

Vintageport::Vintageport(const char *br, int b, const char *nn, int y)
    : Port(br, "none", b) {
  nickname = new char[std::strlen(nn) + 1];
  std::strcpy(nickname, nn);
  year = y;
}

Vintageport::Vintageport(const Vintageport &vp) : Port(vp) {
  nickname = new char[std::strlen(vp.nickname) + 1];
  std::strcpy(nickname, vp.nickname);
  year = vp.year;
}

Vintageport::~Vintageport() { delete[] nickname; }

Vintageport &Vintageport::operator=(const Vintageport &vp) {
  if (this == &vp) {
    return *this;
  }
  Port::operator=(vp);
  delete[] nickname;
  nickname = new char[std::strlen(vp.nickname) + 1];
  std::strcpy(nickname, vp.nickname);
  year = vp.year;
  return *this;
}

void Vintageport::Show() const {
  Port::Show();
  std::cout << "NickName: " << nickname << '\n' << "Year: " << year << '\n';
}

std::ostream &operator<<(std::ostream &os, const Vintageport &vp) {
  os << (const Port &)vp;
  os << ", " << vp.nickname << "," << vp.year << '\n';
  return os;
}
