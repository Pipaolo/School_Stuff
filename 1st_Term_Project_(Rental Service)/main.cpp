#include "Credentials.h"
#include "Inventory.h"
#include "Sales.h"

void adminMenu();
void salesMenu(string);

int main()
{
	string name;
	start:
	int counter = 0;
	userCount(counter);
	system("cls");
	char input;
	cout << "<-- Welcome to Ctrl-Alt-Elite's Rental Service! -->" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "                      MAIN MENU" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "We are currently serving: " << userCount(counter) << endl;
	cout << "1. Create Account" << endl;
	cout << "2. Login" << endl;
	cout << "3. Exit" << endl;
	cout << "Enter Choice: ";
	cin >> input;
	switch (input)
	{
		case '1':
			registerUser();
			counter += 1;
			userCount(counter);
			goto start;
			break;
		case '2':
			name = loginUser();
			salesMenu(name);
			break;
		case '3':
			return 0;
			break;
		case 'X':
			case 'x':
				adminMenu();
				break;
	}
}

void salesMenu(string name)
{
	char adminInput;
	repeat:
	system("cls");
	cout << "----------------------------------------------------" << endl;
	cout << "                      SALES MENU" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Welcome " << name << "!" << endl;
	cout << "1. Rent Game" << endl;
	cout << "2. Show Transactions" << endl;
	if (gCart.size() != 0)
	{
	cout << "3. Continue to Payment" << endl;
	}
	cout << "E. Exit" << endl;
	cin >> adminInput;
	switch (adminInput)
	{
		case '1':
			rentGame(name);
			goto repeat;
			break;
		case '2':
			showTransactionLog(name);
			break;
		case '3':
			payment();
			updateStock();
			recordTransaction(name);
			goto repeat;
			break;
		case 'E':
			case 'e':
				break;
	}
}

void adminMenu()
{
	char adminInput;
	system("cls");
	cout << "----------------------------------------------------" << endl;
	cout << "                      ADMIN MENU" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Welcome Admin!" << endl;
	cout << "1. Add Games" << endl;
	cout << "2. Transactions" << endl;
	cout << "3. Check Users" << endl;
	cout << "E. Exit" << endl;
	cin >> adminInput;
	switch (adminInput)
	{
		case '1':
			addGames();
			break;
		case '2':
//			showTransaction();
			break;
		case '3':
			showUsers();
			break;
		case 'E':
			case 'e':
				break;
	}
}

