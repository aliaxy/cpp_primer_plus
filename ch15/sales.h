#ifndef SALES_H_
#define SALES_H_

#include <stdexcept>
#include <string>

class Sales {
public:
  enum { MONTHS = 12 };
  class bad_index : public std::logic_error {
  private:
    int bi;

  public:
    explicit bad_index(
        int, const std::string & = "Index error in LabeledSales object\n");
    int bi_val() const;
    virtual ~bad_index() throw();
  };

  explicit Sales(int = 0);
  Sales(int, const double *gr, int);
  virtual ~Sales();
  int Year() const;
  virtual double operator[](int) const;
  virtual double &operator[](int);

private:
  double gross[MONTHS];
  int year;
};

class LabeledSales : public Sales {
public:
  class nbad_index : public Sales::bad_index {
  private:
    std::string lbl;

  public:
    nbad_index(const std::string &, int,
               const std::string & = "Index error in LabeledSales object\n");
    const std::string &label_val() const;
    virtual ~nbad_index() throw();
  };

  explicit LabeledSales(const std::string & = "none", int = 0);
  LabeledSales(const std::string &, int, const double *, int);
  virtual ~LabeledSales();
  const std::string &Label() const;
  virtual double operator[](int) const;
  virtual double &operator[](int);

private:
  std::string label;
};

#endif