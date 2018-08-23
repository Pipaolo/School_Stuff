#include <iostream>
using namespace std;

/*Problem 2 : Write a program that mimics a calculator. The program should take as input two integers and the operation to be performed.
It should then output the number, the operator and the result. ( For division, if the denominator is zero, output an appropriate message)
*/
int main() {
	int num1;
	int num2;
	int add;
	int subtract;
	int divide;
	int multiply;
	string op;

	cout << "Calculator Simulator" << endl;
	cout << "Please enter first number: " << endl;
	cin >> num1;
	cout << "Please enter second number: " << endl;
	cin >> num2;
	cout << "Please enter operator symbol(e.g +, -, /, *): " << endl;
	cin >> op;
	
	if ( op == "+") {
		add = num1 + num2;
		cout << num1 << " + " << num2 << " is equals to " << add << endl;
		
	} else if ( op == "-" ){
		subtract = num1 - num2;
		cout << num1 << " - " << num2 << " is equals to " << subtract << endl;
		
	} else if ( op == "*" ){
		multiply = num1 * num2;
		cout << num1 << " * " << num2 << " is equals to " << multiply << endl;
		
	} else if ( op == "/") {
			if ( num2 == 0) {
				cout << "Invalid divisor";
			} else {
				divide = num1 / num2;
		        cout << num1 << " / " << num2 << " is equals to " << divide << endl;	
			}					
	} else {
		return 0;
	}		
}
