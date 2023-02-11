#include <cstring>
#include <iostream>

const int SIZE = 20;
const char FINISHED[] = "done";

int main() {
  int counter = 0;
  char words[SIZE];

  std::cout << "Enter words (to stop, type the word done):\n";

  while (std::strcmp(FINISHED, words) != 0) {
    counter++;
    std::cin >> words;
    std::cin.get();
  }

  std::cout << "Your entered a total of " << counter - 1 << " words.\n";

  return 0;
}