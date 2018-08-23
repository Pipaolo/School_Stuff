#pragma once

// Collection of programs in Activity 2

void num_ones(unsigned int initial_num) {
	switch (initial_num) {
	case 1:
		cout << "one ";
		break;
	case 2:
		cout << "two ";
		break;
	case 3:
		cout << "three ";
		break;
	case 4:
		cout << "four ";
		break;
	case 5:
		cout << "five ";
		break;
	case 6:
		cout << "six ";
		break;
	case 7:
		cout << "seven ";
		break;
	case 8:
		cout << "eight ";
		break;
	case 9:
		cout << "nine ";
		break;
	case 10:
		cout << "ten ";
		break;
	case 11:
		cout << "eleven ";
		break;
	case 12:
		cout << "twelve ";
		break;
	case 13:
		cout << "thirteen ";
		break;
	case 14:
		cout << "fourteen ";
		break;
	case 15:
		cout << "fifteen ";
		break;
	case 16:
		cout << "sixteen ";
		break;
	case 17:
		cout << "seventeen ";
		break;
	case 18:
		cout << "eighteen ";
		break;
	case 19:
		cout << "nineteen ";
		break;
	}
}

void num_ones_capital(unsigned int initial_num) {
	switch (initial_num) {
	case 1:
		cout << "One ";
		break;
	case 2:
		cout << "Two ";
		break;
	case 3:
		cout << "Three ";
		break;
	case 4:
		cout << "Four ";
		break;
	case 5:
		cout << "Five ";
		break;
	case 6:
		cout << "Six ";
		break;
	case 7:
		cout << "Seven ";
		break;
	case 8:
		cout << "Eight ";
		break;
	case 9:
		cout << "Nine ";
		break;
	case 10:
		cout << "Ten ";
		break;
	case 11:
		cout << "Eleven ";
		break;
	case 12:
		cout << "Twelve ";
		break;
	case 13:
		cout << "Thirteen ";
		break;
	case 14:
		cout << "Fourteen ";
		break;
	case 15:
		cout << "Fifteen ";
		break;
	case 16:
		cout << "Sixteen ";
		break;
	case 17:
		cout << "Seventeen ";
		break;
	case 18:
		cout << "Eighteen ";
		break;
	case 19:
		cout << "Nineteen ";
		break;
	}
}

void num_tens(unsigned int initial_num) {
	switch (initial_num) {
	case 2:
		cout << "twenty ";
		break;
	case 3:
		cout << "thirty ";
		break;
	case 4:
		cout << "forty ";
		break;
	case 5:
		cout << "fifty ";
		break;
	case 6:
		cout << "sixty ";
		break;
	case 7:
		cout << "seventy ";
		break;
	case 8:
		cout << "eighty ";
		break;
	case 9:
		cout << "ninety ";
		break;
	default:
		cout << "";
		break;
	}
}

void num_tens_capital(unsigned int initial_num) {
	switch (initial_num) {
	case 2:
		cout << "Twenty ";
		break;
	case 3:
		cout << "Thirty ";
		break;
	case 4:
		cout << "Forty ";
		break;
	case 5:
		cout << "Fifty ";
		break;
	case 6:
		cout << "Sixty ";
		break;
	case 7:
		cout << "Seventy ";
		break;
	case 8:
		cout << "Eighty ";
		break;
	case 9:
		cout << "Ninety ";
		break;
	default:
		cout << "";
		break;
	}
}

void num_hundred() {
	cout << "hundred ";
}

void num_thousand() {
	cout << "thousand ";
}

void num_million() {
	cout << "million ";
}

void convert_ones(unsigned int initial_num) {
	num_ones_capital(initial_num);
}

void convert_tens(unsigned int initial_num) {
	int check = initial_num % 10;
	if (check < 10) {
		num_tens_capital(initial_num / 10);
		num_ones(initial_num % 10);
	}
	else {
		num_tens(initial_num / 10);
	}
}

void convert_hundreds(unsigned int initial_num) {
	int check = initial_num % 100;
	if (check == 0) {
		num_ones_capital(initial_num / 100);
		num_hundred();
	}
	else if (check < 20) {
		num_ones_capital(initial_num / 100);
		num_hundred();
		num_ones(initial_num % 100);
	}
	else {
		num_ones_capital(initial_num / 100);
		num_hundred();
		num_tens((initial_num % 100) / 10);
		num_ones(initial_num % 10);
	}
}

void convert_thousands(unsigned int initial_num) {
	int check = initial_num % 1000;
	int check_ones = initial_num % 100;
	if (check == 0) {
		num_ones_capital(initial_num / 1000);
		num_thousand();
	}
	else if (check < 20) {
		num_ones_capital(initial_num / 1000);
		num_thousand();
		num_ones(initial_num % 100);
	}
	else if (check >= 20 && check < 100) {
		num_ones_capital(initial_num / 1000);
		num_thousand();
		num_tens((initial_num % 1000) / 10);
		num_ones(initial_num % 10);
	}
	else {
		num_ones_capital(initial_num / 1000);
		num_thousand();
		num_ones((initial_num % 1000) / 100);
		num_hundred();
		num_tens((initial_num % 100) / 10);
		if (check_ones < 20) {
			num_ones(initial_num % 100);
		}
		else {
			num_ones(initial_num % 10);
		}
	}
}

void Int_to_words() {
	unsigned int input;
	unsigned int num;

start:
	system("cls");
	cout << "Welcome to the Numbers to Words Converter!" << endl;

	cout << "Please enter a positive integer: ";
	cin >> input;

	if (input < 20) {

		cout << "Here is the result: ";
		convert_ones(input);
		cout << "\n";
	}
	else if (input >= 20 && input < 100) {
		
		cout << "Here is the result: ";
		convert_tens(input);
		cout << "\n";

	}
	else if (input >= 100 && input < 1000) {

		cout << "Here is the result: ";
		convert_hundreds(input);
		cout << "\n";
	}
	else if (input >= 1000 && input < 10000) {

		cout << "Here is the result: ";
		convert_thousands(input);
		cout << "\n";
	}
	else {

		cout << "Invalid Range.\n";
		system("pause");
		goto start;

	}
}

void roman_nums_ones(int initial_input) {
	switch (initial_input) {
	case 1:
		cout << "I";
		break;
	case 2:
		cout << "II";
		break;
	case 3:
		cout << "III";
		break;
	case 4:
		cout << "IV";
		break;
	case 5:
		cout << "V";
		break;
	case 6:
		cout << "VI";
		break;
	case 7:
		cout << "VII";
		break;
	case 8:
		cout << "VIII";
		break;
	case 9:
		cout << "IX";
		break;
	default:
		break;
	}
}

void roman_nums_tens(int initial_input) {
	switch (initial_input) {
	case 1:
		cout << "X";
		break;
	case 2:
		cout << "XX";
		break;
	case 3:
		cout << "XXX";
		break;
	case 4:
		cout << "XL";
		break;
	case 5:
		cout << "L";
		break;
	case 6:
		cout << "LX";
		break;
	case 7:
		cout << "LXX";
		break;
	case 8:
		cout << "LXXX";
		break;
	case 9:
		cout << "XC";
		break;
	default:
		break;
	}

}
void roman_nums_hundreds(int initial_input) {

	switch (initial_input) {
	case 1:
		cout << "C";
		break;
	case 2:
		cout << "CC";
		break;
	case 3:
		cout << "CCC";
		break;
	case 4:
		cout << "CD";
		break;
	case 5:
		cout << "D";
		break;
	case 6:
		cout << "DC";
		break;
	case 7:
		cout << "DCC";
		break;
	case 8:
		cout << "DCCC";
		break;
	case 9:
		cout << "CM";
		break;
	default:
		break;
	}
}

void roman_nums_thousands(int initial_input) {

	switch (initial_input) {
	case 1:
		cout << "M";
		break;
	case 2:
		cout << "MM";
		break;
	case 3:
		cout << "MMM";
		break;
	default:
		cout << "Unknown Range.";
		break;
	}
}

void convert_ones(int initial_input) {
	roman_nums_ones(initial_input);
}

void convert_tens(int initial_input) {
	int check_ones = initial_input % 10;
	if (check_ones == 0) {
		roman_nums_hundreds(initial_input / 100);
	}
	else {
		roman_nums_tens(initial_input / 10);
		roman_nums_ones(initial_input % 10);
	}
}

void convert_hundreds(int initial_input) {
	int check_ones = initial_input % 10;
	int check_tens = initial_input % 100;

	if (check_ones == 0 && check_tens == 0) {

		roman_nums_hundreds(initial_input / 100);

	}
	else if (check_ones < 10 && check_tens < 10) {
		roman_nums_hundreds(initial_input / 100);
		roman_nums_ones(initial_input % 10);

	}
	else {

		roman_nums_hundreds(initial_input / 100);
		roman_nums_tens((initial_input % 100) / 10);
		roman_nums_ones(initial_input % 10);
	}
}

void convert_thousands(int initial_input) {
	int check_ones = initial_input % 10;
	int check_tens = initial_input % 100;
	int check_hundreds = initial_input % 1000;

	if (check_ones == 0) {
		if (check_ones == 0 && check_tens == 0) {
			roman_nums_thousands(initial_input / 1000);

		}
		else if (check_tens < 100 && check_hundreds < 100) {

			roman_nums_thousands(initial_input / 1000);
			roman_nums_tens((initial_input % 100) / 10);

		}
		else {
			roman_nums_thousands(initial_input / 1000);
			roman_nums_hundreds((initial_input % 1000) / 100);
			roman_nums_tens((initial_input % 100) / 10);
		}

	}
	else {
		roman_nums_thousands(initial_input / 1000);
		roman_nums_hundreds((initial_input % 1000) / 100);
		roman_nums_tens((initial_input % 100) / 10);
		roman_nums_ones(initial_input % 10);
	}
}

void Int_to_RN() {
	int input;
start:
	system("cls");
	cout << "Welcome to the Numbers to Roman Numerals Converter!" << endl;
	cout << "Please enter a positive integer: ";
	cin >> input;
	if (input < 10) {
		cout << "Here is the results: ";
		convert_ones(input);
	}
	else if (input >= 10 && input < 100) {
		cout << "Here is the results: ";
		convert_tens(input);
	}
	else if (input >= 100 && input < 1000) {
		cout << "Here is the results: ";
		convert_hundreds(input);
	}
	else {
		cout << "Here is the results: ";
		convert_thousands(input);
	}
}

void Div_Two(int num){
	num %= 2;
	if (num == 0){
		cout << "The value that you have entered is divisible by 2\n";
	} else {
		cout << "The value that you have entered is not divisible by 2\n";
	}	
}

void Div_Three(int num){
	int num1 = num;
	int num2 = num;
	int num3 = num;
	int final;
	
	if (num < 100){
		num = (num % 100) / 10;
		num1 %= 10;
		final = (num + num1) % 3;
		if (final == 0){
			cout << "The value that you have entered is divisible by 3\n";
		} else {
			cout << "The value that you have entered is not divisible by 3\n";
		}
				
	} else {
		num = (num % 10000) / 1000;
		num1 = (num1 % 1000) / 100;
		num2 = (num2 % 100) / 10;
		num3 = num3 % 10;
		final = (num + num1 + num2 + num3) % 3;
		if (final == 0){
			cout << "The value that you have entered is divisible by 3\n";
		} else {
			cout << "The value that you have entered is not divisible by 3\n";
		}
	}
}

void Div_Five(int num){
	num %= 10;
	if (num == 5 || num == 0){
		cout << "The value that you have entered is divisible by 5\n";
	} else {
		cout << "The value that you have entered is not divisible by 5\n";
	}
}

void Divisible() {
int input;
	system("cls");
	cout << "Divisible Checker" << endl;
	cout << "Please Enter a Positive Number: ";
	cin >> input;
	if (input == 0 || input < 9){
		cout << "Invalid Value" << endl;
		system("pause");
	} else if (input >= 10000){
		cout << "Value cannot be higher than 9999" << endl;
		system("pause");
		
	} else {
		Div_Two(input);	
		Div_Three(input);
		Div_Five(input);
	}
}
