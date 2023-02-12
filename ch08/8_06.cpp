#include <cstring>
#include <iostream>
#include <string>

template <typename T> T maxn(T[], int);
template <> char *maxn<char *>(char *[], int);

int main() {
  int arr[5] = {1, 2, 5, 4, 3};
  double arr_d[5] = {19.6, 12, 19.8, 100.8, 98.4};
  std::string ss[] = {"Hello", "Hello World!"};

  std::cout << "The Max Element of int array: " << maxn(arr, 5) << '\n'
            << "The Max Element of double array: " << maxn(arr_d, 5) << '\n'
            << "The Max Element of string: " << maxn(ss, 2) << '\n';

  return 0;
}

template <typename T> T maxn(T st[], int n) {
  T max = st[0];
  for (int i = 1; i < n; i++) {
    if (max < st[i]) {
      max = st[i];
    }
  }
  return max;
}

template <> char *maxn<char *>(char *sst[], int n) {
  int pos = 0;
  for (int i = 0; i < n; i++) {
    if (std::strlen(sst[pos]) < std::strlen(sst[i])) {
      pos = i;
    }
  }
  return sst[pos];
}