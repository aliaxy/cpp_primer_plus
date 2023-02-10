#include <iostream>

const int Day2Hour = 24;
const int Hour2Minute = 60;
const int Minute2Second = 60;

int main() {
  long tot_seconds;
  std::cout << "Enter the number of seconds: ";
  std::cin >> tot_seconds;

  int days = tot_seconds / (Day2Hour * Hour2Minute * Minute2Second);
  int hours = tot_seconds % (Day2Hour * Hour2Minute * Minute2Second) /
              (Hour2Minute * Minute2Second);
  int minutes = tot_seconds % (Day2Hour * Hour2Minute * Minute2Second) %
                (Hour2Minute * Minute2Second) / Minute2Second;
  int seconds = tot_seconds % (Day2Hour * Hour2Minute * Minute2Second) %
                (Hour2Minute * Minute2Second) % Minute2Second;
  std::cout << tot_seconds << " seconds = " << days << " days, " << hours
            << " hours, " << minutes << " minutes, " << seconds
            << " seconds.\n";

  return 0;
}