#ifndef STRING0_H_
#define STRING0_H_

#include <iostream>

class String {
private:
  char *str;
  int len;
  static int num_strings;
  static const int CINLIM = 80;

public:
  String(const char *);
  String();
  String(const String &);
  ~String();

  int length() const;

  String &operator=(const String &);
  String &operator=(const char *);
  char &operator[](int);
  const char &operator[](int) const;

  friend String operator+(const char *, const String &);
  friend String operator+(const String &, const String &);

  void stringlow();
  void stringup();
  int has(char) const;

  friend bool operator<(const String &, const String &);
  friend bool operator>(const String &, const String &);
  friend bool operator==(const String &, const String &);
  friend std::ostream &operator<<(std::ostream &, const String &);
  friend std::istream &operator>>(std::istream &, String &);

  static int HowMany();
};

#endif