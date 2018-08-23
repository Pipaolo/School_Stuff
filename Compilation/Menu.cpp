#include <iostream>
#include <iomanip>
#include <string>
#include "Activity2.h"
#include "Activity3.h"
#include "Activity4.h"


int main() {
	int input;

start:
	system("TITLE Compilations");
	system("cls");
	cout << "!~--Welcome!! My Good Sir to My Program--~!" << endl;
	cout << "\n";
	cout << "[1] Activity 2" << endl;
	cout << "[2] Activity 3" << endl;
	cout << "[3] Activity 4" << endl;
	cout << "[4] Change Color" << endl;
	cout << "[5] Exit" << endl;
	cout << "\n";
	cout << "Please Enter Desired Number: ";
	cin >> input;

	switch (input) {
		case 1:
			goto Act2;
			break;
		case 2:
			goto Act3;
			break;
		case 3:
			goto Act4;
			break;
		case 4:
			goto color;
			break;
		case 5:
			return 0;
		default:
			cout << "Invalid Input\n";
			goto start;
	}
		
Act2:
	system("cls");
	cout << "==Activity 2 Menu==" << endl;
	cout << "\n";
	cout << "[1] Miles to KM Converter\n";
	cout << "[2] CM to Ft and Inches Converter\n";
	cout << "[3] Pound to Grams Converter\n";
	cout << "[4] Hours to Weeks, Days, and Hours Converter\n";
	cout << "[5] Seconds to Hours, Minutes, and Seconds Converter\n";
	cout << "[6] Return to Main Menu\n";
	cout << "\n";
	cout << "Please Enter Desired Number: ";
	cin >> input;
		switch (input) {
		case 1:
			system("cls");
			M_to_KM();
			system("pause");
			goto Act2;
			break;
		case 2:
			system("cls");
			CM_convert();
			system("pause");
			goto Act2;
			break;
		case 3:
			system("cls");
			Lbs_to_G();
			system("pause");
			goto Act2;
			break;
		case 4:
			system("cls");
			Int_hrs();
			system("pause");
			goto Act2;
			break;
		case 5:
			system("cls");
			Int_secs();
			system("pause");
			goto Act2;
			break;
		case 6:
			goto start;
		default:
			cout << "Invalid Input\n";
			goto start;
		}

Act3:
	system("cls");
	cout << "==Activity 3 Menu==" << endl;
	cout << "\n";
	cout << "[1] Letter to Number (Telephone Format)\n";
	cout << "[2] Calculator Simulator\n";
	cout << "[3] Cartesian Plane\n";
	cout << "[4] Calculator Simulator with Decimals!\n";
	cout << "[5] Return to Main Menu\n";
	cout << "\n";
	cout << "Please Enter Desired Number: ";
	cin >> input;
	switch (input) {
	case 1:
		system("cls");
		Letter_to_num();
		system("pause");
		goto Act3;
		break;
	case 2:
		system("cls");
		Calc();
		system("pause");
		goto Act3;
		break;
	case 3:
		system("cls");
		Cart_plane();
		system("pause");
		goto Act3;
		break;
	case 4:
		system("cls");
		Calc_dec();
		system("pause");
		goto Act3;
		break;
	case 5:
		goto start;
	default:
		cout << "Invalid Input\n";
		goto start;
	}
Act4:
	system("cls");
	cout << "==Activity 3 Menu==" << endl;
	cout << "\n";
	cout << "[1] Words to Numbers Converter (Up to 9999!)\n";
	cout << "[2] Numbers to Roman Numerals (Up to 3999!)\n";
	cout << "[3] Divisible by 2, 3, and/or 5 checker.\n";
	cout << "[4] Return to Main Menu\n";
	cout << "\n";
	cout << "Please Enter Desired Number: ";
	cin >> input;
	switch (input) {
	case 1:
		system("cls");
		Int_to_words();
		system("pause");
		goto Act4;
		break;
	case 2:
		system("cls");
		Int_to_RN();
		system("pause");
		goto Act4;
		break;
	case 3:
		system("cls");
		Divisible();
		system("pause");
		goto Act4;
		break;
	case 4:
		goto start;
	default:
		cout << "Invalid Input\n";
		goto start;
	}

color:
	system("cls");
	cout << "==Color Change==" << endl;
	cout << "\n";
	system("cls");
	cout << ("Choose a Color:") << endl;
	cout << ("0 = Black 8 = Gray") << endl;
	cout << ("1 = Blue 9 = Light Blue") << endl;
	cout << ("2 = Green 10 = Reset Color") << endl;
	cout << ("3 = Aqua ") << endl;
	cout << ("4 = Red ") << endl;
	cout << ("5 = Purple ") << endl;
	cout << ("6 = Yellow" ) << endl;
	cout << ("7 = White ") << "\n";
	cout << "\n";
	cout << "Please Enter Desired Number: ";
	cin >> input;
	switch (input) {
	case 0:
		system("color 0");
		goto start;
		break;
	case 1:
		system("color 1");
		goto start;
		break;
	case 2:
		system("color 2");
		goto start;
		break;
	case 3:
		system("color 3");
		goto start;
		break;
	case 4:
		system("color 4");
		goto start;
		break;
	case 5:
		system("color 5");
		goto start;
		break;
	case 6:
		system("color 6");
		goto start;
		break;
	case 7:
		system("color 7");
		goto start;
		break;
	case 8:
		system("color 8");
		goto start;
		break;
	case 9:
		system("color 9");
		goto start;
		break;
	case 10:
		system("color 07");
		goto start;
		break;
	default:
		cout << "Invalid Input\n";
		goto start;
	}	
}
