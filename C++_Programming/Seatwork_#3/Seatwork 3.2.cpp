#include <iostream>
#include <iomanip>
using namespace std;

/*Problem 3 : Write a program that prompts the user to input the x-y coordinate of a point in a Cartesian plane. The program should then output a message indicating
whether the point is the origin point, is located on the x ( or y ) axis, or appears in a particular quadrant.
*/

int main() {
	int x;
	int y;
	
	cout << "Enter x-axis: ";
	cin >> x;
	cout << "Enter y-axis: ";
	cin >> y;
		
	if ( x > 0 && y > 0 ) {
		cout << "The given coordinate is in Quadrant I." << endl;
	} else if ( x < 0 && y > 0 ) {
		cout << "The given coordinate is in Quadrant II." << endl;
	} else if ( x < 0 && y < 0 ) {
		cout << "The given coordinate is in Quadrant III." << endl;
	} else if ( x > 0 && y < 0 ) {
		cout << "The given coordinate is in Quadrant IV." << endl;
	} else if ( x == 0 && y < 0 or y > 0 ){
		cout << "The given coordinate is in x-axis." << endl;
	} else if ( y == 0 && x < 0 or x > 0 ){
		cout << "The given coordinate is in y-axis." << endl;
	} else {
		cout << "The given coordinate is at the origin." << endl;
	}	
}
