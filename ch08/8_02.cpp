#include <iostream>
#include <string>

struct CandyBar {
  std::string brand;
  double weight;
  int calorie;
};

void create_candy(CandyBar &candy, std::string s = "Millennium Munch",
                  double w = 2.85, int c = 350);

void show_candy(const CandyBar &candy);

int main() {
  CandyBar cb;

  create_candy(cb);
  show_candy(cb);

  create_candy(cb, "Nestle", 1.2, 200);
  show_candy(cb);

  return 0;
}

void create_candy(CandyBar &candy, std::string s, double w, int c) {
  candy.brand = s;
  candy.weight = w;
  candy.calorie = c;
}

void show_candy(const CandyBar &candy) {
  std::cout << "The candybar is made by " << candy.brand << " and its weight "
            << candy.weight << ", " << candy.calorie << " calorie\n";
}