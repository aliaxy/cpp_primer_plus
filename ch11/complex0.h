#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

class complex {
private:
  double real;
  double imaginary;

public:
  complex(double = 0.0, double = 0.0);
  ~complex();

  complex operator+(const complex &) const;
  complex operator-(const complex &) const;
  complex operator*(const complex &) const;
  complex operator~() const;

  friend complex operator*(double, const complex &);
  friend std::istream &operator>>(std::istream &, complex &);
  friend std::ostream &operator<<(std::ostream &, const complex &);
};

#endif