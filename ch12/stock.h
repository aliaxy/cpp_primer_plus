#ifndef STOCK_H_
#define STOCK_H_

#include <ostream>
#include <string>

class Stock {
private:
  char *company;
  int shares;
  double share_val;
  double total_val;
  void set_tot();

public:
  Stock();
  Stock(const char *, long = 0, double = 0.0);
  ~Stock();

  void buy(long, double);
  void sell(long, double);
  void update(double);
  const Stock &topval(const Stock &) const;

  friend std::ostream &operator<<(std::ostream &, const Stock &);
};

#endif