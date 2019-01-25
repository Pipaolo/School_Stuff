#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*
Problem 1:
Write a program that accepts a number and output its equivalent in words.
*/
	
void num_ones(unsigned int initial_num){
	switch (initial_num){
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

void num_ones_capital(unsigned int initial_num){
	switch (initial_num){
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

void num_tens(unsigned int initial_num){
	switch (initial_num){
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

void num_tens_capital(unsigned int initial_num){
	switch (initial_num){
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

void num_hundred(){
	cout << "hundred ";
}

void num_thousand(){
	cout << "thousand ";
}

void num_million(){
	cout << "million ";
}

void convert_ones(unsigned int initial_num){
	num_ones_capital(initial_num);
}

void convert_tens(unsigned int initial_num){
	int check = initial_num % 10;
	if (check < 10){
		num_tens_capital(initial_num / 10);
		num_ones(initial_num % 10);
	} else {
		num_tens(initial_num / 10);
	}
}

void convert_hundreds(unsigned int initial_num){
	int check = initial_num % 100;
	if (check == 0){
		num_ones_capital(initial_num / 100);
		num_hundred();
	} else if (check < 20){
		num_ones_capital(initial_num / 100);
		num_hundred();	
		num_ones(initial_num % 100);	
	} else {
		num_ones_capital(initial_num / 100);
		num_hundred();
		num_tens((initial_num % 100) / 10);
		num_ones(initial_num % 10);
	}
}

void convert_thousands(unsigned int initial_num){
	int check = initial_num % 1000;
	int check_ones = initial_num % 100;
	if (check == 0){
		num_ones_capital(initial_num / 1000);
		num_thousand();
	} else if (check < 20){
		num_ones_capital(initial_num / 1000);
		num_thousand();
		num_ones(initial_num % 100);
	} else if (check >= 20 && check < 100){
		num_ones_capital(initial_num / 1000);
		num_thousand();
		num_tens((initial_num % 1000) / 10);
		num_ones(initial_num % 10);
	} else {
		num_ones_capital(initial_num / 1000);
		num_thousand();
		num_ones((initial_num % 1000) / 100);
		num_hundred();
		num_tens((initial_num % 100) / 10);
		if (check_ones < 20){		
			num_ones(initial_num % 100);
		} else {
			num_ones(initial_num % 10);	
		}		
	}
}

int main (){
	unsigned int input;
	unsigned int num;
	
	system("color 6");
	start:
	system("cls");	
	cout << "Welcome to the Numbers to Words Converter!" << endl;

	cout << "Please enter a positive integer: ";
	cin >> input;

	if (input < 20){
		
		convert_ones(input);
		
	} else if (input >= 20 && input < 100){
		
		convert_tens(input);
		
	} else if (input >= 100 && input < 1000){
		
		convert_hundreds(input);
		
	} else if (input >= 1000 && input < 10000){
		
		convert_thousands(input);
		
	} else {
				
		cout << "Invalid Range.\n";
		system("pause");
		goto start;
		
	}
}	

