#ifndef CLASSIC1_H
#define CLASSIC1_H

class Cd {
private:
  char *performers;
  char *label;
  int selections;
  double playtime;

public:
  Cd(const char *, const char *, int, double);
  Cd(const Cd &);
  Cd();
  virtual ~Cd();
  virtual void Report() const;
  virtual Cd &operator=(const Cd &);
};

class Classic : public Cd {
private:
  char *works;

public:
  Classic();
  Classic(const Classic &);
  Classic(const char *, const char *, const char *, int, double);
  ~Classic();

  virtual void Report() const;
  Classic &operator=(const Classic &);
};

#endif