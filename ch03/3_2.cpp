#include <iostream>

const int Foot2Inch = 12;
const double Inch2Meter = 0.0254;
const double Kg2Pound = 2.2;

double BMI(double weight, double height) { return weight / (height * height); }

int main() {
  double height_foot, height_inch, weight_pound;

  std::cout << "Please enter your height in foot and Inch2Meter.\n";
  std::cout << "Enter the foot of height: __\b\b";
  std::cin >> height_foot;

  std::cout << "Enter the inch of height: __\b\b";
  std::cin >> height_inch;

  std::cout << "Enter the pound of weight: __\b\b";
  std::cin >> weight_pound;

  double weight_kg = weight_pound / Kg2Pound;
  double height_meter = (height_foot * Foot2Inch + height_inch) * Inch2Meter;

  double bmi = BMI(weight_kg, height_meter);
  std::cout << "Your BMI is: " << bmi << '\n';
  return 0;
}