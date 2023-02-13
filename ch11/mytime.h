#ifndef MYTIME_H_
#define MYTIME_H_

#include <iostream>
#include <ostream>

class Time {
private:
  int hours;
  int minutes;

public:
  Time();
  Time(int, int = 0);
  void AddMin(int);
  void AddHr(int);
  void Reset(int = 0, int = 0);

  friend Time operator+(const Time &, const Time &);
  friend Time operator-(const Time &, const Time &);
  friend Time operator*(const Time &, double);

  friend Time operator*(double, const Time &);
  friend std::ostream &operator<<(std::ostream &, const Time &);
};

#endif