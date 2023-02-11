#include <cctype>
#include <cstring>
#include <iostream>

int main() {
  char words[40];
  int vowel, consonant, others;
  vowel = consonant = others = 0;

  std::cout << "Enter words (q to quit):\n";
  std::cin >> words;

  while (std::strcmp(words, "q") != 0) {
    if (!std::isalpha(words[0])) {
      others++;
    } else {
      switch (words[0]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        vowel++;
        break;
      default:
        consonant++;
      }
    }

    std::cin >> words;
  }

  std::cout << vowel << " words beginning with vowels\n"
            << consonant << " words beginning with consonant\n"
            << others << " others\n";

  return 0;
}