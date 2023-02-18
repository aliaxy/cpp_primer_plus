#ifndef WINEC0_H_
#define WINEC0_H_

#include <iostream>
#include <string>
#include <valarray>

template <class T1, class T2> class Pair;

using ArrayInt = std::valarray<int>;
using PairArray = Pair<ArrayInt, ArrayInt>;

template <class T1, class T2> class Pair {
private:
  T1 a;
  T2 b;

public:
  Pair(const T1 &, const T2 &);
  Pair();

  T1 &first();
  T2 &second();
  T1 first() const;
  T2 second() const;
};

class Wine {
private:
  std::string label;
  PairArray info;
  int year;

public:
  Wine(const char *, int);
  Wine(const char *, int, const int[], const int[]);

  void GetBottles();
  const std::string &Label() const;
  int sum() const;
  void Show();
};

#endif