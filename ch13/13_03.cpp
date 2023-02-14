#include "dma.h"
#include <cstring>
#include <iostream>

const int CLIENTS = 4;

int main() {
  ABC *p_clients[CLIENTS];

  char kind;
  for (int i = 0; i < CLIENTS; i++) {
    std::cout << "Select 1) ABC, 2) baseDMA, 3) lacksDMA, 4) hasDMA: ";

    while (std::cin >> kind &&
           (kind != '1' && kind != '2' && kind != '3' && kind != '4')) {
      while (std::cin.get() != '\n') {
        continue;
      }
      std::cout << "Enter either 1 2 3 or 4: ";
    }

    if (kind == '1') {
      p_clients[i] = new ABC();
    } else if (kind == '2') {
      while (std::cin.get() != '\n') {
        continue;
      }
      char l[40];
      int r;
      std::cout << "Enter baseDMA's label: ";
      std::cin.getline(l, 40);
      std::cout << "Enter baseDMA's rating: ";
      std::cin >> r;
      p_clients[i] = new baseDMA(l, r);
    } else if (kind == '3') {
      while (std::cin.get() != '\n') {
        continue;
      }
      char l[40], c[40];
      int r;
      std::cout << "Enter lacksDMA's label: ";
      std::cin.getline(l, 40);
      std::cout << "Enter lacksDMA's color: ";
      std::cin.getline(c, 40);
      std::cout << "Enter lacksDMA's rating: ";
      std::cin >> r;
      p_clients[i] = new lacksDMA(c, l, r);
    } else if (kind == '4') {
      while (std::cin.get() != '\n') {
        continue;
      }
      char l[40], s[40];
      int r;
      std::cout << "Enter lacksDMA's label: ";
      std::cin.getline(l, 40);
      std::cout << "Enter lacksDMA's style: ";
      std::cin.getline(s, 40);
      std::cout << "Enter lacksDMA's rating: ";
      std::cin >> r;
      p_clients[i] = new hasDMA(s, l, r);
    }

    while (std::cin.get() != '\n') {
      continue;
    }
  }

  std::cout << '\n';

  for (int i = 0; i < CLIENTS; i++) {
    p_clients[i]->View();
    std::cout << '\n';
  }

  for (int i = 0; i < CLIENTS; i++) {
    delete p_clients[i];
  }

  std::cout << "Done.\n";

  return 0;
}