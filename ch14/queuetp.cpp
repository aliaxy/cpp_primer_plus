#include "queuetp.h"
#include <string>

Worker::Worker() : fullname("no one"), id(0L) {}

Worker::Worker(const std::string &s, long n) : fullname(s), id(n) {}

Worker::~Worker() {}

void Worker::Set() {
  std::cout << "Enter worker's name: ";
  std::getline(std::cin, fullname);

  std::cout << "Enter worker's ID: ";
  std::cin >> id;

  while (std::cin.get() != '\n') {
    continue;
  }
}

void Worker::Show() const {
  std::cout << "Name: " << fullname << '\n' << "Employee ID: " << id << '\n';
}

template <class T> QueueTp<T>::QueueTp(const QueueTp &q) : qsize(0) {}

template <class T> QueueTp<T> &QueueTp<T>::operator=(const QueueTp &q) {
  return *this;
}