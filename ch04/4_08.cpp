#include <iostream>

struct Pizza {
  char company[40];
  double diameter;
  double weight;
};

int main() {
  Pizza *ppizza = new Pizza;

  std::cout << "Enter the Pizza's information:\n";

  std::cout << "Pizza's diameter(inchs): ";
  std::cin >> ppizza->diameter;

  getchar();

  std::cout << "Pizza's Company: ";
  std::cin.getline(ppizza->company, 40);

  std::cout << "Pizza's weight(pounds): ";
  std::cin >> ppizza->weight;

  std::cout << "The lunch pizza is " << ppizza->company << ".\n"
            << "And its diameter is " << ppizza->diameter << " inch, weight is "
            << ppizza->weight << " pounds.\n";

  delete ppizza;

  return 0;
}