#include "stack.h"
#include <iostream>

int main() {
  Stack st;
  customer cust;
  double sum_payment = 0;
  char select;

  std::cout << "Select a(add), p(pop) or q(quit): ";
  while (std::cin.get(select) && select != 'q') {
    while (std::cin.get() != '\n') {
      continue;
    }
    if (select == 'a') {
      std::cout << "Enter a customer's name: ";
      std::cin.getline(cust.fullname, 35);

      std::cout << "Enter a customer's payment: ";
      std::cin >> cust.payment;

      while (std::cin.get() != '\n') {
        continue;
      }

      st.push(cust);
      std::cout << "Item pushed.\n";
    }
    if (select == 'p') {
      st.pop(cust);
      sum_payment += cust.payment;

      std::cout << "Pop Item's info:\n"
                << "Name: " << cust.fullname << '\n'
                << "Payment: " << cust.payment << '\n'
                << "Now, sum of payments: " << sum_payment << '\n';
    }
    std::cout << "Select a(add), p(pop) or q(quit): ";
  }

  std::cout << "Bye\n";

  return 0;
}