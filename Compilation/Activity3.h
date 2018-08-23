#pragma once
using std::setprecision;
using std::fixed;
// Collection of programs in Activity 3

void Letter_to_num() {

	char input;
	cout << "Letters to Number Converter in Telephone Format" << endl;
	cout << "Please Enter Letter: ";
	cin >> input;

	if (input == 'A' or input == 'B' or input == 'C' or input == 'a' or input == 'b' or input == 'c') {
		cout << "The Corresponding number is: ";
		cout << '2' << endl;
	}
	else if (input == 'D' or input == 'E' or input == 'F' or input == 'd' or input == 'e' or input == 'f') {
		cout << "The Corresponding number is: ";
		cout << '3' << endl;
	}
	else if (input == 'G' or input == 'H' or input == 'I' or input == 'g' or input == 'h' or input == 'i') {
		cout << "The Corresponding number is: ";
		cout << '4' << endl;
	}
	else if (input == 'J' or input == 'K' or input == 'L' or input == 'j' or input == 'k' or input == 'l') {
		cout << "The Corresponding number is: ";
		cout << '5' << endl;
	}
	else if (input == 'M' or input == 'N' or input == 'O' or input == 'm' or input == 'n' or input == 'o') {
		cout << "The Corresponding number is: ";
		cout << '6' << endl;
	}
	else if (input == 'P' or input == 'Q' or input == 'R' or input == 'S' or input == 'p' or input == 'q' or input == 'r' or input == 's') {
		cout << "The Corresponding number is: ";
		cout << '7' << endl;
	}
	else if (input == 'T' or input == 'U' or input == 'V' or input == 't' or input == 'u' or input == 'v') {
		cout << "The Corresponding number is: ";
		cout << '8' << endl;
	}
	else {
		cout << "The Corresponding number is: ";
		cout << '9' << endl;
	}
}

void Calc() {
	int num1;
	int num2;
	int add;
	int subtract;
	int divide;
	int multiply;
	string op;

start:
	system("cls");
	cout << "Calculator Simulator" << endl;
	cout << "Please enter first number: " << endl;
	cin >> num1;
	cout << "Please enter second number: " << endl;
	cin >> num2;
	cout << "Please enter operator symbol(e.g +, -, /, *): " << endl;
	cin >> op;

	if (op == "+") {
		add = num1 + num2;
		cout << num1 << " + " << num2 << " is equals to " << add << endl;

	}
	else if (op == "-") {
		subtract = num1 - num2;
		cout << num1 << " - " << num2 << " is equals to " << subtract << endl;

	}
	else if (op == "*") {
		multiply = num1 * num2;
		cout << num1 << " * " << num2 << " is equals to " << multiply << endl;

	}
	else if (op == "/") {
		if (num2 == 0) {
			cout << "Invalid divisor";
		}
		else {
			divide = num1 / num2;
			cout << num1 << " / " << num2 << " is equals to " << divide << endl;
		}
	} else {
		cout << "Invalid Input";
		goto start;
	}
}

void Cart_plane() {
	int x;
	int y;

	cout << "Enter x-axis: ";
	cin >> x;
	cout << "Enter y-axis: ";
	cin >> y;

	if (x > 0 && y > 0) {
		cout << "The given coordinate is in Quadrant I." << endl;
	}
	else if (x < 0 && y > 0) {
		cout << "The given coordinate is in Quadrant II." << endl;
	}
	else if (x < 0 && y < 0) {
		cout << "The given coordinate is in Quadrant III." << endl;
	}
	else if (x > 0 && y < 0) {
		cout << "The given coordinate is in Quadrant IV." << endl;
	}
	else if (x == 0 && y < 0 or y > 0) {
		cout << "The given coordinate is in x-axis." << endl;
	}
	else if (y == 0 && x < 0 or x > 0) {
		cout << "The given coordinate is in y-axis." << endl;
	}
	else {
		cout << "The given coordinate is at the origin." << endl;
	}
}

void Calc_dec() {
	double num1;
	double num2;
	double add;
	double subtract;
	double divide;
	double multiply;
	string op;
start:
	cout << "Calculator Simulator with decimal places" << endl;
	cout << "Please enter first number: " << endl;
	cin >> num1;
	cout << "Please enter second number: " << endl;
	cin >> num2;
	cout << "Please enter operator symbol(e.g +, -, /, *): " << endl;
	cin >> op;

	if (op == "+") {
		add = num1 + num2;
		cout << num1 << " + " << num2 << " is equals to " << add << endl;
	} else if (op == "-") {
		subtract = num1 - num2;
		cout << num1 << " - " << num2 << " is equals to " << subtract << endl;
	} else if (op == "*") {
		multiply = num1 * num2;
		cout << num1 << " * " << num2 << " is equals to " << multiply << endl;
	} else if (op == "/") {
		if (num2 == 0) {
			cout << "Invalid divisor";
		} else {
			divide = num1 / num2;
			cout << fixed;
			cout << setprecision(2);
			cout << num1 << " / " << num2 << " is equals to " << divide << endl;
		}
	} else {
		cout << "Invalid Input";
		goto start;
	}
}