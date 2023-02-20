#include "sales.h"
#include <iostream>

int main() {
  double vals1[12] = {1220, 1100, 1122, 2212, 1232, 2334,
                      2884, 2393, 3302, 2922, 3002, 3544};
  double vals2[12] = {12, 11, 22, 21, 32, 34, 28, 29, 33, 29, 32, 35};

  Sales sales1(2011, vals1, 12);
  LabeledSales sales2("Blogstar", 2012, vals2, 12);

  std::cout << "Frist try block:\n";
  try {
    int i;
    std::cout << "Year = " << sales1.Year() << '\n';
    for (int i = 0; i < 12; i++) {
      std::cout << sales1[i] << ' ';
      if (i % 6 == 5) {
        std::cout << '\n';
      }
    }
    std::cout << "Year = " << sales2.Year() << '\n';
    std::cout << "Label = " << sales2.Year() << '\n';
    for (int i = 0; i < 12; i++) {
      std::cout << sales2[i] << ' ';
      if (i % 6 == 5) {
        std::cout << '\n';
      }
    }
    std::cout << "End of try block 1.\n";
  } catch (Sales::bad_index &bad) {
    if (typeid(LabeledSales::nbad_index) == typeid(bad)) {
      LabeledSales::nbad_index *p =
          dynamic_cast<LabeledSales::nbad_index *>(&bad);
      std::cout << p->what();
      std::cout << "Company: " << p->label_val() << '\n'
                << "bad index: " << p->bi_val() << '\n';
    } else if (typeid(Sales::bad_index) == typeid(bad)) {
      std::cout << bad.what();
      std::cout << "bad index: " << bad.bi_val() << '\n';
    }
  }
  std::cout << "\nNext try block:\n";

  try {
    sales2[2] = 37.5;
    sales1[20] = 23345;
    std::cout << "End of try block 2.\n";
  } catch (Sales::bad_index &bad) {
    if (typeid(LabeledSales::nbad_index) == typeid(bad)) {
      LabeledSales::nbad_index *p =
          dynamic_cast<LabeledSales::nbad_index *>(&bad);
      std::cout << p->what();
      std::cout << "Company: " << p->label_val() << '\n'
                << "bad index: " << p->bi_val() << '\n';
    } else if (typeid(Sales::bad_index) == typeid(bad)) {
      std::cout << bad.what();
      std::cout << "bad index: " << bad.bi_val() << '\n';
    }
  }

  std::cout << "done\n";

  return 0;
}