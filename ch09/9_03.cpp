#include <cstring>
#include <iostream>

struct chaff {
  char dross[20];
  int slag;
};

int set_chaff(chaff &, char *, int);
void show_chaff(const chaff &);

int main() {
  char buffer[1024];
  char st[20];
  int slag, n = 0;
  chaff *pcf = new (buffer) chaff[2];

  std::cout << "Enter String to set chaff: ";
  std::cin.getline(st, 20);

  std::cout << "Enter a numner: ";
  std::cin >> slag;

  while (std::strlen(st) > 0) {
    std::cin.get();
    set_chaff(pcf[n++], st, slag);
    if (n >= 2) {
      break;
    }
    std::cout << "Enter String to set chaff: ";
    std::cin.getline(st, 20);

    std::cout << "Enter a number: ";
    std::cin >> slag;
  }

  for (int i = 0; i < 2; i++) {
    show_chaff(pcf[i]);
  }

  return 0;
}

int set_chaff(chaff &cf, char *str, int n) {
  if (std::strlen(str) > 0) {
    std::strcpy(cf.dross, str);
    cf.slag = n;
    return 1;
  }
  return 0;
}

void show_chaff(const chaff &cf) {
  std::cout << "Chaff's Dross: " << cf.dross << '\n'
            << "Chaff's slag: " << cf.slag << '\n';
}