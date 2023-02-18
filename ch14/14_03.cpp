#include "queuetp.h"
#include <cstring>
#include <iostream>

int main() {
  QueueTp<Worker> lolas;
  Worker w1;
  w1.Set();
  lolas.enqueue(w1);
  Worker w2;
  lolas.dequeue(w2);
  w2.Show();
  std::cout << "Bye.\n";

  return 0;
}