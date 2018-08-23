#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
Problem: 3

There are some techniques that Mathematician use to know if a number is divisible by another number. Some rules are stated below.

2	The last digit of the number must be divisible by 2.
3	The sum of the digits when added must be divisible by 3 (works for at least 2 digit numbers).
5	The last digit must end with 0 or 5.

With the rules above, write a program that allow a user to enter a numeric value higher than 9 and less than 10,000 (maximum of 4 digits only) and will identify if that number is divisible by 2, 3 and/or 5.

*/
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

int main(){
	int input;
	start:
	system("cls");
	cout << "Divisible Checker" << endl;
	cout << "Please Enter a Positive Number: ";
	cin >> input;
	if (input == 0 || input < 9){
		cout << "Invalid Value" << endl;
		system("pause");
		
		goto start;
	} else if (input >= 10000){
		cout << "Value cannot be higher than 9999" << endl;
		system("pause");
		goto start;
		
	} else {
		Div_Two(input);	
		Div_Three(input);
		Div_Five(input);
		system("pause");
		goto start;
	}
}

