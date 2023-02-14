#ifndef CLASSIC0_H
#define CLASSIC0_H

class Cd {
private:
  char performers[50];
  char label[20];
  int selections;
  double playtime;

public:
  Cd(const char *, const char *, int, double);
  Cd(const Cd &);
  Cd();
  virtual ~Cd();
  virtual void Report() const;
  Cd &operator=(const Cd &);
};

class Classic : public Cd {
private:
  char works[50];

public:
  Classic();
  Classic(const Classic &);
  Classic(const char *, const char *, const char *, int, double);
  ~Classic();

  virtual void Report() const;
  Classic &operator=(const Classic &);
};

#endif