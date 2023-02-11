#include <iostream>

const int SIZE = 10;

int set_mark(int[], int);
void display_mark(int[], int);
double average_mark(int[], int);

int main() {
  int size, golf_mark[SIZE];

  size = set_mark(golf_mark, SIZE);
  display_mark(golf_mark, size);

  std::cout << "The average marks is : " << average_mark(golf_mark, size)
            << '\n';

  return 0;
}

int set_mark(int arr[], int size) {
  int i = 0;
  do {
    std::cout << "Enter the No." << i + 1 << " golf marks: ";
    std::cin >> arr[i++];
    std::cin.get();

    std::cout << "Press enter to continue, or 's' for STOP input: ";
    if (std::cin.get() == 's') {
      for (int j = i; j < size; j++) {
        arr[j] = 0;
      }
      break;
    }
  } while (i < size);

  return i;
}

void display_mark(int arr[], int size) {
  std::cout << "The marks is below:\n";
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << '\t';
  }
  std::cout << '\n';
}

double average_mark(int arr[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return 1.0 * sum / size;
}