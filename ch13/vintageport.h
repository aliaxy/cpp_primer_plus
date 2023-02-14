#ifndef VINTAGEPORT_H_
#define VINTAGEPORT_H_

#include <iostream>

class Port {
private:
  char *brand;
  char style[20];
  int bottles;

public:
  Port(const char * = "none", const char * = "none", int = 0);
  Port(const Port &);
  virtual ~Port();

  Port &operator=(const Port &);
  Port &operator+=(int);
  Port &operator-=(int);

  int BottleCount() const;
  virtual void Show() const;

  friend std::ostream &operator<<(std::ostream &, const Port &);
};

class Vintageport : public Port {
private:
  char *nickname;
  int year;

public:
  Vintageport();
  Vintageport(const char *, int, const char *, int);
  Vintageport(const Vintageport &);
  ~Vintageport();

  Vintageport &operator=(const Vintageport &);
  void Show() const;

  friend std::ostream &operator<<(std::ostream &, const Vintageport &);
};

#endif