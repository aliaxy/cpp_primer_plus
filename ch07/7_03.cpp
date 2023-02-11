#include <iostream>

struct box {
  char maker[40];
  float height;
  float width;
  float length;
  float volume;
};

void display(box);
void calc_volume(box *);

int main() {
  box Orange = {"China", 12, 12, 12, 0};

  calc_volume(&Orange);

  display(Orange);

  return 0;
}

void display(box b) {
  std::cout << "This box made by " << b.maker << ".\n"
            << "And height = " << b.height << ", width = " << b.width
            << ", length = " << b.length << ", volume = " << b.volume << ".\n";
}

void calc_volume(box *pb) {
  pb->volume = pb->width * pb->height * pb->length;
  std::cout << "Calculate box'x volume done.\n";
}