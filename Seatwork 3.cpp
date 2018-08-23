#include <iostream>
using namespace std;

/*Problem 1 : Write a program that will input a single character and print out the 
corresponding digit on the telephone digits and letters on a telephone are associated as follows:
*/
int main() {
	char input;
	cin >> input;
	
	if ( input == 'A' or input == 'B' or input == 'C' or input == 'a' or input == 'b' or input == 'c'){
		cout << '2' << endl;
	} else if ( input == 'D' or input == 'E' or input == 'F' or input == 'd' or input == 'e' or input == 'f') {
		cout << '3' << endl;
	} else if ( input == 'G' or input == 'H' or input == 'I' or input == 'g' or input == 'h' or input == 'i') {
		cout << '4' << endl;
	} else if ( input == 'J' or input == 'K' or input == 'L' or input == 'j' or input == 'k' or input == 'l') {
		cout << '5' << endl;
	} else if ( input == 'M' or input == 'N' or input == 'O' or input == 'm' or input == 'n' or input == 'o') {
		cout << '6' << endl;
	} else if ( input == 'P' or input == 'Q' or input == 'R' or input == 'S' or input == 'p' or input == 'q' or input == 'r' or input == 's') {
		cout << '7' << endl;
	} else if ( input == 'T' or input == 'U' or input == 'V' or input == 't' or input == 'u' or input == 'v') {
		cout << '8' << endl;
	} else {
		cout << '9' << endl;
	}	
}


