#ifndef COW_H_
#define COW_H_

class Cow {
private:
  char name[20];
  char *hobby;
  double weight;

public:
  Cow();
  Cow(const char *, const char *, double);
  Cow(const Cow &);
  ~Cow();

  Cow &operator=(const Cow &);
  void ShowCow() const;
};

#endif