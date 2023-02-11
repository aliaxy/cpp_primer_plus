#include <iostream>
#include <string>

const char FINISHED[] = "char";

int main() {
  int counter = 0;
  std::string words;

  std::cout << "Enter words (to stop, type the word done):\n";

  while (words != FINISHED) {
    counter++;
    std::cin >> words;
    std::cin.get();
  }

  std::cout << "Your entered a total of " << counter - 1 << " words.\n";

  return 0;
}