#include <iostream>

const int SIZE = 20;

int Fill_array(double[], int);
void Show_array(double[], int);
void Reverse_array(double[], int);

int main() {
  double Array[SIZE];

  int size = Fill_array(Array, SIZE);

  Show_array(Array, size);

  Reverse_array(Array, size);
  Show_array(Array, size);

  Reverse_array(Array + 1, size - 2);
  Show_array(Array, size);

  return 0;
}

int Fill_array(double arr[], int size) {
  int count = 0;
  double temp;

  std::cout << "Enter the number seperate by blank, 's' to stop : ";
  std::cin >> temp;

  while (count < size) {
    std::cin.clear();
    if (std::cin.get() == 's') {
      return count;
    }
    arr[count++] = temp;
    std::cin >> temp;
  }

  return count;
}

void Show_array(double arr[], int size) {
  std::cout << "The array's data: \n";
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << '\t';
  }
  std::cout << '\n';
}

void Reverse_array(double arr[], int size) {
  for (int i = 0; i < size / 2; i++) {
    double temp = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = temp;
  }
}