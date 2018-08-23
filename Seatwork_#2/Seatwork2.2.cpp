#include <iostream>
#include <iomanip>

//using namespace std;
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
	//Problem 3
	//454 grams in a pound
	//Centimeters to feet and inches 2nd Problem
	double pounds;
	std::cout << "Pound to Grams Converter" << std::endl;
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	std::cout << "Enter Pounds: ";
	std::cin >> pounds;
	double grams = pounds * 454;
	std::cout << "Your original value is: " << pounds << "lbs" << std::endl;
	std::cout << "Your converted value is: " << grams << "g";
	return 0;
}

