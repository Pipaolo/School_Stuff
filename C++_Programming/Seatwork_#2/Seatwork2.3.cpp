#include <iostream>
#include <string>
//tip: use modulo operator for problem 4
/*
#include <iomanip>

double pi = 3.14.16;
std::cout << pi << std::endl;
std::cout << fixed;
std::cout << setprecision(2);
std::cout << pi;
*/
int converter(int initial_hours){
	int weeks;
	int final_days;
	int final_hours;
	weeks = initial_hours / 168;
	final_days = (initial_hours % 168) / 24;
	final_hours = initial_hours % 24;
	std::cout << "Your have " << weeks << " weeks, " << final_days << " days, and " << final_hours << " hours to live." << std::endl;
	
}
int main() {
	
	int input;
	std::cout << "Hours to Weeks, Days, and Hours Converter" << std::endl;
	std::cout << "Enter Hours: ";
	std::cin >> input;
	converter(input);

}
