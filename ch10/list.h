#ifndef LIST_H_
#define LIST_H_

using Item = unsigned long;

void visit_Item(Item &);

class List {
private:
  enum { MAX = 10 };
  Item items[MAX];
  int top;

public:
  List();
  bool isempty() const;
  bool isfull() const;
  bool add(const Item &);
  void visit(void (*)(Item &));
};

#endif