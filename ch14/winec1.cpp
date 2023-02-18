#include "winec1.h"
#include <iostream>

template <class T1, class T2>
Pair<T1, T2>::Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}

template <class T1, class T2> Pair<T1, T2>::Pair() {}

template <class T1, class T2> T1 &Pair<T1, T2>::first() { return a; }

template <class T1, class T2> T2 &Pair<T1, T2>::second() { return b; }

template <class T1, class T2> T1 Pair<T1, T2>::first() const { return a; }

template <class T1, class T2> T2 Pair<T1, T2>::second() const { return b; }

Wine::Wine(const char *l, int y)
    : std::string(l), year(y), PairArray(ArrayInt(0, 0), ArrayInt(0, 0)) {}

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
    : std::string(l), year(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {}

void Wine::GetBottles() {
  std::cout << "Enter " << (const std::string &)(*this) << " data for " << year
            << " year(s):\n";
  this->first().resize(year);
  this->second().resize(year);
  for (int i = 0; i < year; i++) {
    std::cout << "Enter year: ";
    std::cin >> this->first()[i];
    std::cout << "Enter bottles for that year: ";
    std::cin >> this->second()[i];
  }
}

const std::string &Wine::Label() const { return (const std::string &)(*this); }

int Wine::sum() const { return this->second().sum(); }

void Wine::Show() {
  std::cout << "Wine: " << (const std::string &)(*this)
            << "\n      Year Bottles\n";
  for (int i = 0; i < year; i++) {
    std::cout << "      " << this->first()[i] << " " << this->second()[i]
              << '\n';
  }
}