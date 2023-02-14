#ifndef DMA_H_
#define DMA_H_

#include <iostream>

class ABC {
public:
  virtual ~ABC();
  virtual void View();
};

class baseDMA : public ABC {
private:
  char *label;
  int rating;

public:
  baseDMA(const char * = "null", int = 0);
  baseDMA(const baseDMA &);
  virtual ~baseDMA();

  virtual void View();
  baseDMA &operator=(const baseDMA &);

  friend std::ostream &operator<<(std::ostream &, const baseDMA &);
};

class lacksDMA : public baseDMA {
private:
  enum { COL_LEN = 40 };
  char color[COL_LEN];

public:
  lacksDMA(const char * = "blank", const char * = "null", int = 0);
  lacksDMA(const char *, const baseDMA &);

  virtual void View();

  friend std::ostream &operator<<(std::ostream &, const lacksDMA &);
};

class hasDMA : public baseDMA {
private:
  char *style;

public:
  hasDMA(const char * = "none", const char * = "null", int = 0);
  hasDMA(const char *, const baseDMA &);
  hasDMA(const hasDMA &);
  ~hasDMA();

  virtual void View();

  hasDMA &operator=(const hasDMA &);

  friend std::ostream &operator<<(std::ostream &, const hasDMA &);
};

#endif