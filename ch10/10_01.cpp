#include <iostream>
#include <string>

class BankAccount {
private:
  std::string fullname;
  std::string account;
  double deposit;

public:
  BankAccount();
  BankAccount(const std::string, const std::string, double);
  ~BankAccount();
  void init_account(const std::string, const std::string, double);
  void print_info() const;
  void save(double);
  void withdraw(double);
};

int main() {
  BankAccount ba("Nik", "0001", 1200);

  ba.print_info();
  ba.init_account("Nik Swit", "", 1500);
  ba.print_info();
  ba.save(223.5);
  ba.print_info();

  return 0;
}

BankAccount::BankAccount() { deposit = 0; }

BankAccount::BankAccount(std::string name, std::string id, double f) {
  fullname = name;
  account = id;
  deposit = f;
}

BankAccount::~BankAccount() { std::cout << "All Done!\n"; }

void BankAccount::init_account(const std::string name, const std::string id,
                               double f) {
  std::cout << "Initializing Account information...\n";
  if (name != "") {
    fullname = name;
  }
  if (id != "") {
    account = id;
  }
  deposit = f;
}

void BankAccount::print_info() const {
  std::cout << "The Account info:\n"
            << "Full Name: " << fullname << '\n'
            << "Account ID: " << account << '\n'
            << "Deposit: " << deposit << '\n';
}

void BankAccount::save(double f) { deposit += f; }

void BankAccount::withdraw(double f) { deposit -= f; }