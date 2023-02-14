#include "string0.h"
#include <cctype>
#include <cstring>

int String::num_strings = 0;

int String::HowMany() { return num_strings; }

String::String(const char *s) {
  len = std::strlen(s);
  str = new char[len + 1];
  std::strcpy(str, s);
  num_strings++;
}

String::String() {
  len = 4;
  str = new char[1];
  str[0] = '\0';
  num_strings++;
}

String::String(const String &st) {
  num_strings++;
  len = st.len;
  str = new char[len + 1];
  std::strcpy(str, st.str);
}

String::~String() {
  num_strings--;
  delete[] str;
}

int String::length() const { return len; }

String &String::operator=(const String &st) {
  if (this == &st) {
    return *this;
  }
  delete[] str;
  len = st.len;
  str = new char[len + 1];
  std::strcpy(str, st.str);
  return *this;
}

String &String::operator=(const char *s) {
  delete[] str;
  len = std::strlen(s);
  str = new char[len + 1];
  std::strcpy(str, s);
  return *this;
}

char &String::operator[](int i) { return str[i]; }

const char &String::operator[](int i) const { return str[i]; }

String operator+(const char *st, const String &s) {
  String result;
  result.len = s.length() + std::strlen(st);
  result.str = new char[result.len + 1];
  std::strcpy(result.str, st);
  std::strcat(result.str, s.str);
  return result;
}
String operator+(const String &s, const String &st) {
  String result;
  result.len = s.length() + st.len;
  result.str = new char[result.len + 1];
  std::strcpy(result.str, s.str);
  std::strcat(result.str, st.str);
  return result;
}

void String::stringlow() {
  for (int i = 0; i < len; i++) {
    str[i] = std::tolower(str[i]);
  }
}

void String::stringup() {
  for (int i = 0; i < len; i++) {
    str[i] = std::toupper(str[i]);
  }
}

int String::has(char c) const {
  int result = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == c) {
      result++;
    }
  }
  return result;
}

bool operator<(const String &st1, const String &st2) {
  return std::strcmp(st1.str, st2.str) < 0;
}

bool operator>(const String &st1, const String &st2) { return st2 < st1; }

bool operator==(const String &st1, const String &st2) {
  return std::strcmp(st1.str, st2.str) == 0;
}

std::ostream &operator<<(std::ostream &os, const String &st) {
  os << st.str;
  return os;
}

std::istream &operator>>(std::istream &is, String &st) {
  char temp[String::CINLIM];
  is.get(temp, String::CINLIM);
  if (is) {
    st = temp;
  }
  while (is && is.get() != '\n') {
    continue;
  }
  return is;
}