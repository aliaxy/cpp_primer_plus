#include "sales.h"
#include <stdexcept>

Sales::bad_index::bad_index(int ix, const std::string &s)
    : std::logic_error(s), bi(ix) {}

int Sales::bad_index::bi_val() const { return bi; }

Sales::bad_index::~bad_index() throw() {}

Sales::Sales(int yy) {
  year = yy;
  for (int i = 0; i < MONTHS; i++) {
    gross[i] = 0;
  }
}

Sales::Sales(int yy, const double *gr, int n) {
  year = yy;
  int lim = (n < MONTHS) ? n : MONTHS;
  int i;
  for (int i = 0; i < lim; i++) {
    gross[i] = gr[i];
  }
  for (; i < MONTHS; i++) {
    gross[i] = 0;
  }
}

Sales::~Sales() {}

int Sales::Year() const { return year; }

double Sales::operator[](int i) const {
  if (i < 0 || i >= MONTHS) {
    throw bad_index(i);
  }
  return gross[i];
}

double &Sales::operator[](int i) {
  if (i < 0 || i >= MONTHS) {
    throw bad_index(i);
  }
  return gross[i];
}

LabeledSales::nbad_index::nbad_index(const std::string &lb, int ix,
                                     const std::string &s)
    : Sales::bad_index(ix, s) {
  lbl = lb;
}

const std::string &LabeledSales::nbad_index::label_val() const { return lbl; }

LabeledSales::nbad_index::~nbad_index() throw() {}

LabeledSales::LabeledSales(const std::string &lb, int yy) : Sales(yy) {
  label = lb;
}

LabeledSales::LabeledSales(const std::string &lb, int yy, const double *gr,
                           int n)
    : Sales(yy, gr, n) {
  label = lb;
}

LabeledSales::~LabeledSales() {}

const std::string &LabeledSales::Label() const { return label; }

double LabeledSales::operator[](int i) const {
  if (i < 0 || i >= MONTHS) {
    throw nbad_index(Label(), i);
  }
  return Sales::operator[](i);
}

double &LabeledSales::operator[](int i) {
  if (i < 0 || i >= MONTHS) {
    throw nbad_index(Label(), i);
  }
  return Sales::operator[](i);
}