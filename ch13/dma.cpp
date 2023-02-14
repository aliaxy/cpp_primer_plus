#include "dma.h"
#include <cstring>
#include <ostream>

ABC::~ABC() {}

void ABC::View() { std::cout << "This is ABC View(), it is empty.\n"; }

baseDMA::baseDMA(const char *l, int r) {
  label = new char[std::strlen(l) + 1];
  std::strcpy(label, l);
  rating = r;
}

baseDMA::baseDMA(const baseDMA &rs) {
  label = new char[std::strlen(rs.label) + 1];
  std::strcpy(label, rs.label);
  rating = rs.rating;
}

baseDMA::~baseDMA() { delete[] label; }

void baseDMA::View() { std::cout << "Now in baseDMA.\n" << *this; }

baseDMA &baseDMA::operator=(const baseDMA &rs) {
  if (this == &rs) {
    return *this;
  }
  delete[] label;
  label = new char[std::strlen(rs.label) + 1];
  std::strcpy(label, rs.label);
  rating = rs.rating;
  return *this;
}

std::ostream &operator<<(std::ostream &os, const baseDMA &rs) {
  os << "Label: " << rs.label << '\n' << "Rating: " << rs.rating << '\n';
  return os;
}

lacksDMA::lacksDMA(const char *c, const char *l, int r) : baseDMA(l, r) {
  std::strncpy(color, c, 39);
  color[39] = '\0';
}

lacksDMA::lacksDMA(const char *c, const baseDMA &rs) : baseDMA(rs) {
  std::strncpy(color, c, COL_LEN - 1);
  color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() { std::cout << "Now in lacksDMA.\n" << *this; }

std::ostream &operator<<(std::ostream &os, const lacksDMA &ls) {
  os << (const baseDMA &)ls;
  os << "Color: " << ls.color << '\n';
  return os;
}

hasDMA::hasDMA(const char *s, const char *l, int r) : baseDMA(l, r) {
  style = new char[std::strlen(s) + 1];
  std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA &rs) : baseDMA(rs) {
  style = new char[std::strlen(s) + 1];
  std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs) : baseDMA(hs) {
  style = new char[std::strlen(hs.style) + 1];
  std::strcpy(style, hs.style);
}

hasDMA::~hasDMA() { delete[] style; }

void hasDMA::View() { std::cout << "Now in hasDMA\n" << *this; }

hasDMA &hasDMA::operator=(const hasDMA &hs) {
  if (this == &hs) {
    return *this;
  }
  hasDMA::operator=(hs);
  delete[] style;
  style = new char[std::strlen(hs.style) + 1];
  std::strcpy(style, hs.style);
  return *this;
}

std::ostream &operator<<(std::ostream &os, const hasDMA &hs) {
  os << (const baseDMA &)hs;
  os << "Style: " << hs.style << '\n';
  return os;
}