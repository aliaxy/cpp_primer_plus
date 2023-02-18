#ifndef QUEUETP_H_
#define QUEUETP_H_

#include <iostream>
#include <string>

class Worker {
private:
  std::string fullname;
  long id;

protected:
  void Data() const;
  void get();

public:
  Worker();
  Worker(const std::string &, long);
  ~Worker();

  void Set();
  void Show() const;
};

template <class T> class QueueTp {
private:
  enum { Q_SIZE = 10 };
  struct Node {
    T item;
    Node *next;
  };

  Node *front;
  Node *rear;
  int items;
  const int qsize;

public:
  QueueTp(const QueueTp &);
  QueueTp &operator=(const QueueTp &);
  QueueTp(int qs = 10) : qsize(qs) {
    front = rear = nullptr;
    items = 0;
  }
  ~QueueTp() {
    Node *temp;
    while (front != nullptr) {
      temp = front;
      front = front->next;
      delete temp;
    }
  }

  bool isempty() const;
  bool isfull() const;
  int queuecount() const;
  bool enqueue(const T &);
  bool dequeue(T &);
};

template <class T> bool QueueTp<T>::isempty() const { return items == 0; }

template <class T> bool QueueTp<T>::isfull() const { return items == qsize; }

template <class T> int QueueTp<T>::queuecount() const { return items; }

template <class T> bool QueueTp<T>::enqueue(const T &item) {
  if (isfull()) {
    return false;
  }

  Node *temp = new Node;
  temp->item = item;
  temp->next = nullptr;
  items++;

  if (front == nullptr) {
    front = temp;
  } else {
    rear->next = temp;
  }
  rear = temp;
  return true;
}

template <class T> bool QueueTp<T>::dequeue(T &item) {
  if (isempty()) {
    return false;
  }

  item = front->item;
  items--;

  Node *temp = front;
  front = front->next;
  delete temp;

  if (items == 0) {
    rear = nullptr;
  }

  return true;
}
#endif