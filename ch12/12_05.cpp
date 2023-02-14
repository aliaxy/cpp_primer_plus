#include "queue.h"
#include <cstdlib>
#include <ctime>
#include <ios>
#include <iostream>

const int MIN_PER_HR = 60;
const int MIN_SIM_HOURS = 150;

bool newcustomer(double);

int main() {
  std::srand(std::time(nullptr));

  std::cout << "Case Study: Bank of Heather Automatic Teller\n"
            << "Enter maximum size of qeue: ";

  int qs;
  std::cin >> qs;
  Queue line(qs);
  std::cout << "The number of simulation hours >= 100.\n";

  int hours = MIN_SIM_HOURS;
  long cyclelimit = MIN_PER_HR * hours;

  double perhour = 0;
  Item temp;
  double average_wait = 0;

  while (average_wait < 1) {
    double min_per_cust;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    perhour++;
    if (!line.isempty()) {
      line.dequeue(temp);
    }

    for (int cycle = 0; cycle < cyclelimit; cycle++) {
      min_per_cust = MIN_PER_HR / perhour;
      if (newcustomer(min_per_cust)) {
        if (line.isfull()) {
          turnaways++;
        } else {
          customers++;
          temp.set(cycle);
          line.enqueue(temp);
        }
      }
      if (wait_time <= 0 && !line.isempty()) {
        line.dequeue(temp);
        wait_time = temp.ptime();
        line_wait += cycle - temp.when();
        served++;
      }
      if (wait_time > 0) {
        wait_time--;
      }
      sum_line += line.queuecount();
    }
    average_wait = (double)line_wait / served;
    if (average_wait < 1) {
      if (customers > 0) {
        std::cout << "customers accepted: " << customers << '\n'
                  << "  customers serced: " << served << '\n'
                  << "    turnaways: " << turnaways << '\n'
                  << "average queue size: ";
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << (double)sum_line / cyclelimit << '\n';
        std::cout << " average wait time: " << (double)line_wait / served
                  << " minutes\n";
      } else {
        std::cout << "No customers!\n";
      }
      std::cout << "The average " << perhour
                << " of arrival per hour, and average wait time is "
                << average_wait << '\n';
    }
  }

  std::cout << "Done!\n";

  return 0;
}

bool newcustomer(double x) { return std::rand() * x / RAND_MAX < 1; }