#include <iostream>

const int SLEN = 30;

struct student {
  char fullname[SLEN];
  char hobby[SLEN];
  int ooplevel;
};

int getinfo(student[], int);

void display1(student);

void display2(const student *);

void display3(const student[], int);

int main() {
  std::cout << "Enter the class size: ";
  int class_size;
  std::cin >> class_size;

  while (std::cin.get() != '\n') {
    continue;
  }

  student *ptr_stu = new student[class_size];
  int entered = getinfo(ptr_stu, class_size);

  for (int i = 0; i < class_size; i++) {
    display1(ptr_stu[i]);
    display2(ptr_stu + i);
  }

  display3(ptr_stu, entered);

  delete[] ptr_stu;

  std::cout << "Done\n";
}

int getinfo(student pa[], int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    std::cout << "Enter the info of student name: ";
    std::cin >> pa[i].fullname;

    std::cout << "Enter the info of student hobby: ";
    std::cin >> pa[i].hobby;

    std::cout << "Enter the info of student level: ";
    std::cin >> pa[i].ooplevel;

    if (!std::cin) {
      std::cin.clear();
      while (std::cin.get() != '\n') {
        continue;
      }
      std::cout << "Bad input. procerss terminated\n";
      break;
    }
  }
  return i;
}

void display1(student st) {
  std::cout << "Student Name: " << st.fullname << '\n'
            << "Student hobby: " << st.hobby << '\n'
            << "Student level: " << st.ooplevel << "\n\n";
}

void display2(const student *ps) {
  std::cout << "Student Name: " << ps->fullname << '\n'
            << "Student hobby: " << ps->hobby << '\n'
            << "Student level: " << ps->ooplevel << "\n\n";
}

void display3(const student pa[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << "Student Name: " << pa[i].fullname << '\n'
              << "Student hobby: " << pa[i].hobby << '\n'
              << "Student level: " << pa[i].ooplevel << "\n\n";
  }
}
