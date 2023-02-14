#ifndef STACK_H_
#define STACK_H_

using Item = unsigned long;

class Stack {
private:
  enum { MAX = 10 };
  Item *pitems;
  int size;
  int top;

public:
  Stack(int = MAX);
  Stack(const Stack &);
  ~Stack();

  bool isempty() const;
  bool isfull() const;
  bool push(const Item &);
  bool pop(Item &);

  Stack &operator=(const Stack &);
};

#endif