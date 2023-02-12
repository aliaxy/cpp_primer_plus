#include <cstring>
#include <iostream>

const int Len = 40;

class golf {
private:
  char fullname[Len];
  int handicap;

public:
  golf();
  golf(const char *, int);
  ~golf() = default;
  void sethandicap(int);
  void showgolf() const;
};

int main() {
  golf ann("Ann Bird free", 24);
  golf andy;

  ann.showgolf();
  andy.showgolf();

  return 0;
}

golf::golf(const char *name, int hc) {
  std::strcpy(fullname, name);
  handicap = hc;
}

golf::golf() {
  char name[Len] = {'\0'};
  int hc;

  std::cout << "Please enter the name: ";
  std::cin.getline(name, Len);

  std::cout << "Please enter the handicap: ";
  while (!(std::cin >> hc)) {
    std::cin.clear();
    while (std::cin.get() != '\n') {
      continue;
    }
    std::cout << "Please enter the golf's handicap: ";
  }
  std::cout << name << "::" << hc << '\n';

  std::strcpy(fullname, name);
  handicap = hc;
}

void golf::sethandicap(int hc) { handicap = hc; }

void golf::showgolf() const {
  std::cout << "Name : " << fullname << ", Handicap is " << handicap << '\n';
}