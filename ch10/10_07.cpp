#include <cstring>
#include <iostream>

const int SIZE = 19;

class plorg {
private:
  char name[SIZE];
  int CI;

public:
  plorg(const char[] = "Plorga", int = 50);
  void reset_ci(int);
  void print_info() const;
};

int main() {
  plorg p1;

  p1.print_info();
  p1.reset_ci(98);
  p1.print_info();

  plorg pm("Stenom", 87);

  pm.print_info();

  return 0;
}

plorg::plorg(const char st[], int ci) {
  std::strcpy(name, st);
  CI = ci;
}

void plorg::reset_ci(int ci) { CI = ci; }

void plorg::print_info() const {
  std::cout << "plorg name: " << name << ", CI = " << CI << '\n';
}