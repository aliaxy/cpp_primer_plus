#include "winec0.h"
#include <iostream>

template <class T1, class T2>
Pair<T1, T2>::Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}

template <class T1, class T2> Pair<T1, T2>::Pair() {}

template <class T1, class T2> T1 &Pair<T1, T2>::first() { return a; }

template <class T1, class T2> T2 &Pair<T1, T2>::second() { return b; }

template <class T1, class T2> T1 Pair<T1, T2>::first() const { return a; }

template <class T1, class T2> T2 Pair<T1, T2>::second() const { return b; }

Wine::Wine(const char *l, int y)
    : label(l), year(y), info(ArrayInt(0, 0), ArrayInt(0, 0)) {}

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
    : label(l), year(y), info(ArrayInt(yr, y), ArrayInt(bot, y)) {}

void Wine::GetBottles() {
  std::cout << "Enter " << label << " data for " << year << " year(s):\n";
  info.first().resize(year);
  info.second().resize(year);
  for (int i = 0; i < year; i++) {
    std::cout << "Enter year: ";
    std::cin >> info.first()[i];
    std::cout << "Enter bottles for that year: ";
    std::cin >> info.second()[i];
  }
}

const std::string &Wine::Label() const { return label; }

int Wine::sum() const { return info.second().sum(); }

void Wine::Show() {
  std::cout << "Wine: " << label << "\n      Year Bottles\n";
  for (int i = 0; i < year; i++) {
    std::cout << "      " << info.first()[i] << " " << info.second()[i] << '\n';
  }
}