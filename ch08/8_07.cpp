#include <iostream>

template <typename T> void ShowArray(T[], int);
template <typename T> void ShowArray(T *[], int);

template <typename T> T SumArray(T[], int);
template <typename T> T SumArray(T *[], int);

struct debts {
  char name[50];
  double amount;
};

int main() {
  int things[6] = {13, 31, 103, 301, 310, 130};
  debts mr_E[3] = {
      {"Ima Wolfe", 2400.0}, {"Ura Foxe", 1300.0}, {"Iby Stout", 1800.0}};
  double *pd[3];

  for (int i = 0; i < 3; i++) {
    pd[i] = &mr_E[i].amount;
  }

  std::cout << "Listing Mr. E's counts of things:\n";
  ShowArray(things, 6);
  std::cout << "Listing Mr. E's debts:\n";
  ShowArray(pd, 3);
  std::cout << "The sum of things: " << SumArray(things, 6) << '\n'
            << "The sum of pd: " << SumArray(pd, 3) << '\n';

  return 0;
}

template <typename T> void ShowArray(T arr[], int n) {
  std::cout << "template A\n";
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

template <typename T> void ShowArray(T *arr[], int n) {
  std::cout << "template B\n";
  for (int i = 0; i < n; i++) {
    std::cout << *arr[i] << ' ';
  }
  std::cout << '\n';
}

template <typename T> T SumArray(T arr[], int n) {
  T sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

template <typename T> T SumArray(T *arr[], int n) {
  T sum = *arr[0] - *arr[0];
  for (int i = 0; i < n; i++) {
    sum += *arr[i];
  }
  return sum;
}