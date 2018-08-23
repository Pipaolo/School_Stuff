#pragma once
using std::cin;
using std::cout;
using std::endl;
using std::string;
// Collection of programs in Activity 2

void M_to_KM() {
	double miles;
	cout << "Miles to Km converter" << std::endl;
	cout << std::fixed;
	cout << std::setprecision(2);
	cout << "Enter Miles: ";
	cin >> miles;
	double kilometer = (((miles * 5280) * 12) * 2.54) / 100000;
	cout << "Your converted value is: " << kilometer << "km\n";
}

void CM_convert() {
	double centimeters;
	cout << "Centimeter to feet and inches converter" << std::endl;
	cout << std::fixed;
	cout << std::setprecision(2);
	cout << "Enter Centimeter: ";
	cin >> centimeters;
	double inches = centimeters / 2.54;
	double feet = inches / 12;
	cout << "Your converted value is: " << feet << "ft and " << inches << "inch\n";
}

void Lbs_to_G() {
	double pounds;
	cout << "Pound to Grams Converter" << std::endl;
	cout << std::fixed;
	cout << std::setprecision(2);
	cout << "Enter Pounds: ";
	cin >> pounds;
	double grams = pounds * 454;
	cout << "Your original value is: " << pounds << "lbs" << endl;
	cout << "Your converted value is: " << grams << "g\n";
}

void Int_hrs() {
	int weeks;
	int final_days;
	int final_hours;
	int input;

	cout << "Hours to Weeks, Days, and Hours Converter" << endl;
	cout << "Enter Hours: ";
	cin >> input;

	weeks = input / 168;
	final_days = (input % 168) / 24;
	final_hours = input % 24;
	cout << "Your have " << weeks << " weeks, " << final_days << " days, and " << final_hours << " hours to live." << endl;
}

void Int_secs() {

	int initial_seconds;
	cout << "Seconds to Hours, Minutes, and Seconds Converter" << std::endl;
		cout << "Enter Seconds: ";
		cin >> initial_seconds;
		int minutes = initial_seconds / 60;
		int final_seconds = initial_seconds % 60;
		int hours = minutes / 60;
		cout << "You have " << hours % 24 << " hours, " << minutes % 60 << " minutes, and " << final_seconds << " seconds to live." << endl;
}