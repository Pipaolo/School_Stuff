#include "main.h"
#include "Credentials.h"
#include "Sales.h"
#include "Inventory.h"

void adminMenu();
void salesMenu(string);

int counter;


int main()
{
	/*
		This function is to create a folder for the Logs, Users,
		and StockLists. Using the system("mkdir "Name of Folder" ");
	*/
	createDirectory();
	// End of create Directory function
	string name;
	start:
	counter = 0;
	userCount(counter);
	system("cls");
	char input;
	cout << "<-- Welcome to Ctrl-Alt-Elite's Rental Service! -->" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "                      MAIN MENU" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Number of Games rented: " << userCount(counter) << endl;
	cout << "1. Create Account" << endl;
	cout << "2. Login" << endl;
	cout << "3. Exit" << endl;
	cout << "Enter Choice: ";
	cin >> input;
	switch (input)
	{
		case '1':
			registerUser();
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
				goto start;
				break;
	}
}

void salesMenu(string name)
{
	char adminInput;
	repeat:
	counter = 0;
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
			rentGame();
			goto repeat;
			break;
		case '2':
			showTransactionLog(name);
			break;
		case '3':
			payment();
			updateStock();
			recordTransaction(name);
			counter += 1;
			userCount(counter);
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
			showMainTransaction();
			break;
		case '3':
			showUsers();
			break;
		case 'E':
			case 'e':
				break;
	}
}

