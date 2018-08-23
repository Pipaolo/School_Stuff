#include <iostream>
#include <iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
	//Problem 1
	//5280 per feet per mile, 12 inches per foot, 2.54 centimeters per inch, 100,000 centimeters per kilometer
	//Miles to Kilometers 1st Problem
	double miles;
	std::cout << "Miles to Km converter" << std::endl;
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	std::cout << "Enter Miles: ";
	std::cin >> miles;
	double kilometer = (((miles * 5280) * 12) * 2.54) / 100000;
	std::cout << "Your converted value is: " << kilometer << "km";
	return 0;
}
