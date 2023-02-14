#ifndef QUEUE_H_
#define QUEUE_H_

class Customer {
  long arrive;
  int processtime;

public:
  Customer();
  void set(long);
  long when() const;
  int ptime() const;
};

using Item = Customer;

class Queue {
private:
  struct Node {
    Item item;
    struct Node *next;
  };
  enum { Q_SIZE = 10 };

  Node *front;
  Node *rear;
  int items;
  const int qsize;

  Queue(const Queue &);
  Queue &operator=(const Queue &q);

public:
  Queue(int = Q_SIZE);
  ~Queue();

  bool isempty() const;
  bool isfull() const;
  int queuecount() const;
  bool enqueue(const Item &);
  bool dequeue(Item &);
};

#endif