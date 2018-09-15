#include <iostream>
using namespace std;

void Problem1(){
/*
PROBLEM 1: Write a program that will compute the product of two positive integers (first no and second no) by adding them repeatedly.
This means adding first no. to itself second no. of times.
*/	

	int num;
	int num2;
	int final;

	system("cls");
	cout << "Enter Two Positive Integers(e.g 1 5): ";
	cin >> num;
	cin >> num2;
	
	for (int i = 0; i < num2; i++){
		final += num;
		cout << num << endl;
	}
	
	cout << "The Product of " << num << " and " << num2 << " is " << final;
	
}

void Problem2(){
/*
PROBLEM 2: Write a program that gets the Fibonacci of a number read from the user. The Fibonacci number sequence begins with 1, 1 then each succeeding number in the sequence
in the sequence is the sum of the previous ones. For example, an input of 5 will produce 1,1 ,2 ,3 ,5 and an input of 8 will produce 1, 1, 2, 3, 5, 8, 13, 21 and an input of 2
will produce 1, 1.
*/	
int num;
int numStore;
int numEmpty = 0;
int numFibo = 1;

	system("cls");
	cout << "Fibonacci Sequence Generator\n";
	cout << "Enter a Positive Integer: ";

	cin >> num;
	for ( int i = 2; i < num ; i++){
		cout << numFibo; //This prints out 1
		cout << ", "; //To add commas and spaces to numbers
		numStore = numFibo + numEmpty; // Numstore is where the first number is being stored
		numEmpty = numFibo;
		numFibo = numStore; 		
	}
		numStore = numFibo + numEmpty;
		numEmpty = numFibo;
		numFibo = numStore; 
		cout << numEmpty << ", "<< numFibo;
}

void Problem3(){
/*
PROBLEM 3: Write a program that will derive the sum of series of number. For example, an input of 5 will produce. (1 + 2 + 3 + 4 + 5 = 15)
*/

	int input;
	int sumFirst;
	int sumEnd;
	system("cls");
	cout << "Enter a Positive Integer: ";
	cin >> input;
	
	for ( int i = 1; i < input; i++){
		sumFirst += i;
		cout << i << " + ";
	}	
		sumEnd = input + sumFirst;
		cout << input << " = " << sumEnd;
}

int main(){
	char input;
	
	start:
		system("cls");
		cout << "Start Menu\n";
		cout << "[1] Multiplication by Adding\n";
		cout << "[2] Fibonacci Sequence\n";
		cout << "[3] The sum of a number series going down\n";
		cout << "[e] Exit\n";
		cout << "Enter Desired Choice: ";
		cin >> input;
		switch (input){
			case '1':
				Problem1();
				break;
			case '2':
				Problem2();
				break;
			case '3':
				Problem3();
				break;
			case 'e':
				return 0;
				break;	
			default:
				cout << "Error!!" << endl;
				system("pause");
				goto start;
				break;
	}
}
