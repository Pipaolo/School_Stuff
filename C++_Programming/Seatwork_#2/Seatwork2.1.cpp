#include <iostream>
#include <iomanip>

//tip: use modulo operator for problem 4
/*
#include <iomanip>

double pi = 3.14.16;
std::cout << pi << std::endl;
std::cout << fixed;
std::cout << setprecision(2);
std::cout << pi;
*/

int main() {
	//Problem 2
	//2.54 centimeters in each inch and 12 inches in each foot
	//Centimeters to feet and inches 2nd Problem
	double centimeters;
	std::cout << "Centimeter to feet and inches converter" << std::endl;
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	std::cout << "Enter Centimeter: ";
	std::cin >> centimeters;
	double inches = centimeters / 2.54;
	double feet = inches / 12;
	std::cout << "Your converted value is: " << feet << "ft and " << inches << "inch";
	return 0;
}

