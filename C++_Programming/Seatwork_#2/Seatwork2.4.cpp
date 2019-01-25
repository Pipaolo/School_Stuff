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
 main() {
	//Problem 5 "Write a program that will convert the read in time in seconds to number of hours, minutes, and seconds"
	//minutes has 60 seconds hours has 360 seconds
	//Hours to weeks days and hours
	int restart = 1;
	
	int initial_seconds;
	std::cout << "Seconds to Hours, Minutes, and Seconds Converter" << std::endl;
	while ( restart <= 5){
	std::cout << "Enter Seconds: ";
	std::cin >> initial_seconds;
	int minutes = initial_seconds / 60;
	int final_seconds = initial_seconds % 60;
	int hours = minutes / 60;
	std::cout << "Your have " << hours % 24 << " hours, " << minutes % 60 << " minutes, and " << final_seconds << " seconds to live." << std::endl;
	restart++;
}
	return 0;
}
