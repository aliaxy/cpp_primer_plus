#include <iostream>

template <typename T> T max5(T[]);

int main() {
  int arr[5] = {1, 2, 5, 4, 3};
  double arr_d[5] = {19.6, 12, 19.8, 100.8, 98.4};

  std::cout << "The Max Element of int array: " << max5(arr) << '\n';
  std::cout << "The Max Element of double array: " << max5(arr_d) << '\n';

  return 0;
}

template <typename T> T max5(T st[]) {
  T max = st[0];
  for (int i = 1; i < 5; i++) {
    if (max < st[i]) {
      max = st[i];
    }
  }
  return max;
}