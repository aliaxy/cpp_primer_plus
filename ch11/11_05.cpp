#include "stonewt.h"
#include <iostream>

int main() {
  Stonewt incognito = 275;
  std::cout << "incognito: " << incognito << '\n';

  Stonewt wolfe(285.7);
  std::cout << "wolfe: " << wolfe << '\n';
  Stonewt taft(21, 8);
  std::cout << "taft: " << taft << '\n';

  incognito = 276.8;
  std::cout << "incognito: " << incognito << '\n';

  std::cout << "wolfe: " << wolfe * 2.3 << '\n';
  taft = incognito + wolfe + 200;
  std::cout << "taft: " << taft << '\n';

  wolfe.Set_Style(Stonewt::FLOATPOUNDS);
  wolfe = wolfe * 2.3;
  std::cout << "wolfe: " << wolfe * 2.3 << '\n';
  return 0;
}