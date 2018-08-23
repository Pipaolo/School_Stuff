#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
Problem 2:
Write a program that accepts an ordinary numbered and outputs its equivalent Roman Numerals.
The ordinary number and their equivalent Roman numerals are given below:

Ordinary Numbers	Roman Numerals
1	I
5	V
10	X
50	L
100	C
500	D
1000	M

*/

void roman_nums_ones(int initial_input){
	switch(initial_input){
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

void roman_nums_tens(int initial_input){
	switch(initial_input){
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
void roman_nums_hundreds(int initial_input){
	
	switch(initial_input){
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

void roman_nums_thousands(int initial_input){
	
	switch(initial_input){
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

void convert_ones(int initial_input){
	roman_nums_ones(initial_input);
}

void convert_tens(int initial_input){
	int check_ones = initial_input % 10;
	if (check_ones == 0){
		roman_nums_hundreds(initial_input / 100);	
	} else {
		roman_nums_tens(initial_input / 10);
		roman_nums_ones(initial_input % 10);	
	}
}

void convert_hundreds(int initial_input){
	int check_ones = initial_input % 10;
	int check_tens = initial_input % 100;
	
	if (check_ones == 0 && check_tens == 0){
		
		roman_nums_hundreds(initial_input / 100);
				
	} else if (check_ones < 10 && check_tens < 10) {
		roman_nums_hundreds(initial_input / 100);
		roman_nums_ones(initial_input % 10);	
		
	} else {
		
		roman_nums_hundreds(initial_input / 100);
		roman_nums_tens((initial_input % 100) / 10);
		roman_nums_ones(initial_input % 10);	
	}
}

void convert_thousands(int initial_input){
	int check_ones = initial_input % 10;
	int check_tens = initial_input % 100;
	int check_hundreds = initial_input % 1000;
	
	if (check_ones == 0){
		if (check_ones == 0 && check_tens == 0){
			roman_nums_thousands(initial_input / 1000);

		} else if (check_tens < 100 && check_hundreds < 100){
			
			roman_nums_thousands(initial_input / 1000);
			roman_nums_tens((initial_input % 100) / 10);
			
		} else {
			roman_nums_thousands(initial_input / 1000);
			roman_nums_hundreds((initial_input % 1000) / 100);
			roman_nums_tens((initial_input % 100) / 10);
		}
							
	} else {
		roman_nums_thousands(initial_input / 1000);
		roman_nums_hundreds((initial_input % 1000) / 100);
		roman_nums_tens((initial_input % 100) / 10);
		roman_nums_ones(initial_input % 10);			
	} 
}

int main(){
	int input;
	system("color 6");
	start:
	system("cls");	
	cout << "Welcome to the Numbers to Roman Numerals Converter!" << endl;
	cout << "Please enter a positive integer: ";
	cin >> input;
	if (input < 10){
		cout << "Here is the results: ";
		convert_ones(input);
	} else if ( input >= 10 && input < 100 ){
		cout << "Here is the results: ";
		convert_tens(input);
	} else if ( input >= 100 && input < 1000){
		cout << "Here is the results: ";
		convert_hundreds(input);
	} else {
		cout << "Here is the results: ";
		convert_thousands(input);
	}
}
