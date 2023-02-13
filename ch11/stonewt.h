#ifndef STONEWT_H_
#define STONEWT_H_

#include <ostream>
class Stonewt {
public:
  enum Style { STONE, POUNDS, FLOATPOUNDS };

private:
  enum { Lbs_per_stn = 14 };
  int stone;
  double pds_left;
  double pounds;
  Style style;

public:
  Stonewt(double);
  Stonewt(int, double);
  Stonewt();
  ~Stonewt();

  void show_lbs() const;
  void show_stn() const;
  void Set_Style(Style);

  Stonewt operator+(const Stonewt &) const;
  Stonewt operator-(const Stonewt &) const;
  Stonewt operator*(double) const;

  bool operator<(const Stonewt &) const;
  bool operator<=(const Stonewt &) const;
  bool operator>(const Stonewt &) const;
  bool operator>=(const Stonewt &) const;
  bool operator==(const Stonewt &) const;
  bool operator!=(const Stonewt &) const;

  friend std::ostream &operator<<(std::ostream &, const Stonewt &);
};

#endif