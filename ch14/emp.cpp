#include "emp.h"
#include <cstdlib>

abstr_emp::abstr_emp() : lname("none"), fname("none"), job("none") {}

abstr_emp::abstr_emp(const std::string &fn, const std::string &ln,
                     const std::string &j)
    : fname(fn), lname(ln), job(j) {}

abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll() const {
  std::cout << "NAME: " << fname << '.' << lname << '\n'
            << "JOB TITLE: " << job << '\n';
}

void abstr_emp::SetAll() {
  std::cout << "Enter the first name: ";
  std::getline(std::cin, fname);

  std::cout << "Enter the last name: ";
  std::getline(std::cin, lname);

  std::cout << "Enter the job title: ";
  std::getline(std::cin, job);
}

std::ostream &operator<<(std::ostream &os, const abstr_emp &e) {
  os << "NAME: " << e.fname << '.' << e.lname << '\n'
     << "JOB NAME: " << e.job << '\n';
  return os;
}

employee::employee() : abstr_emp() {}

employee::employee(const std::string &fn, const std::string &ln,
                   const std::string &j)
    : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const { abstr_emp::ShowAll(); }

void employee::SetAll() { abstr_emp::SetAll(); }

int manager::InChargeOf() const { return inchargeof; }
int &manager::InChargeOf() { return inchargeof; }

manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const std::string &fn, const std::string &ln,
                 const std::string &j, int ico)
    : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e) {
  inchargeof = ico;
}

manager::manager(const manager &m) : abstr_emp(m) { inchargeof = m.inchargeof; }

void manager::ShowAll() const {
  abstr_emp::ShowAll();
  std::cout << "IN CHARGE OF: " << inchargeof << '\n';
}

void manager::SetAll() {
  abstr_emp::SetAll();
  std::cout << "Enter the number of in charge: ";
  std::cin >> inchargeof;
  while (std::cin.get() != '\n') {
    continue;
  }
}

const std::string fink::Reportsto() const { return reportsto; }

std::string &fink::Reportsto() { return reportsto; }

fink::fink() : abstr_emp(), reportsto("none") {}

fink::fink(const std::string &fn, const std::string &ln, const std::string &j,
           const std::string &rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp &e, const std::string &rpo)
    : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink &e) : abstr_emp(e) { reportsto = e.reportsto; }

void fink::ShowAll() const {
  abstr_emp::ShowAll();
  std::cout << "REPORT TO: " << reportsto << '\n';
}

void fink::SetAll() {
  abstr_emp::SetAll();
  std::cout << "Enter the reports to whom: ";
  std::getline(std::cin, reportsto);
}

highfink::highfink() {}

highfink::highfink(const std::string &fn, const std::string &ln,
                   const std::string &j, const std::string &rpo, int ico)
    : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo){};

highfink::highfink(const abstr_emp &e, const std::string &rpo, int ico)
    : abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink &f, int ico)
    : abstr_emp(f), fink(f), manager(f, ico) {}

highfink::highfink(const manager &m, const std::string &rpo)
    : abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink &h) : abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const {
  manager::ShowAll();

  std::cout << "Enter the reportsto: " << Reportsto() << '\n';
  std::cout << '\n';
}

void highfink::SetAll() {
  manager::SetAll();

  std::cout << "Enter the reportsto: ";
  std::getline(std::cin, fink::Reportsto());
}
