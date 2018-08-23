#include <iostream>
#include <iomanip>
using namespace std;

/*Problem 4 : Redo Problem No.2 to handle floating numbers. (Format your output to two decimal places.)
*/

int main() {
	double num1;
	double num2;
	double add;
	double subtract;
	double divide;
	double multiply;
	string op;

	cout << "Calculator Simulator with decimal places" << endl;
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
			cout << fixed;
			cout << setprecision(2);
		    cout << num1 << " / " << num2 << " is equals to " << divide << endl;	
		}					
	} else {
		return 0;
	}	
}
