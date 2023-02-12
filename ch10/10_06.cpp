#include <iostream>

class Move {
private:
  double x;
  double y;

public:
  Move(double = 0, double = 0);
  void showmove() const;
  Move add(const Move &);
  void reset(double = 0, double = 0);
};

int main() {
  Move a, b(12.5, 19);
  double x, y;

  a.showmove();
  b.showmove();

  std::cout << "Enter X and Y: ";
  std::cin >> x >> y;

  std::cout << "Reset Object A:\n";

  a.reset(x, y);
  a.showmove();
  b.showmove();

  std::cout << "Object A and B:\n";

  a = a.add(b);
  a.showmove();
  b.showmove();

  return 0;
}

Move::Move(double a, double b) {
  x = a;
  y = b;
}

void Move::showmove() const {
  std::cout << "Current x = " << x << ", y = " << y << '\n';
}

Move Move::add(const Move &m) {
  Move temp;
  temp.x = x + m.x;
  temp.y = y + m.y;
  return temp;
}

void Move::reset(double a, double b) {
  x = a;
  y = b;
}