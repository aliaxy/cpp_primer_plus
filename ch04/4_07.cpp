#include <iostream>

struct Pizza {
  char company[40];
  double diameter;
  double weight;
};

int main() {
  Pizza dinner;

  std::cout << "Enter the Pizza's information:\n";
  std::cout << "Pizza's Company: ";
  std::cin.getline(dinner.company, 40);

  std::cout << "Pizza's diameter(inchs): ";
  std::cin >> dinner.diameter;

  std::cout << "CandBar's weight(pounds): ";
  std::cin >> dinner.weight;

  std::cout << "The lunch pizza is " << dinner.company << ".\n"
            << "And its diameter is " << dinner.diameter << " inch, weight is "
            << dinner.weight << " pounds.\n";

  return 0;
}