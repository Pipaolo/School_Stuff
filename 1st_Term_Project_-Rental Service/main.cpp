#include "inventory.h"
#include "sales.h"
#include "credentials.h"
#include "admin.h"

void salesMenu(string&);
void adminMenu();
void loadingScreen();

int main() {
	system("cls");
	loadingScreen();
	createDirectory();
	char input;
	string temp;
	repeat:
	system("cls");
	gotoxy(40,10);
	cout << "---------------------------------------" << endl;
	gotoxy(40,11);
	cout << "     CTRL-ALT-ELITE-RENTAL-SERVICE" << endl;
	gotoxy(40,12);
	cout << "---------------------------------------" << endl;
	gotoxy(40,13);
	cout << "1. Login" << endl;
	gotoxy(40,14);
	cout << "2. Register" << endl;
	gotoxy(40,15);
	cout << "3. Exit" << endl;
	gotoxy(40,16);
	cout << "Enter Desired Choice: ";
	cin >> input;
	switch(input)
	{
		case '1':
			temp = loginUser();
			if (temp.size() != 0)
			{
				salesMenu(temp);				
			}
			else
			{
				goto repeat;
			}
			break;
		case '2':
			registerUser();
			goto repeat;
			break;
		case '3':
			return 0;
			break;
		case 'x':
			case 'X':
				adminMenu();
				break;
		default:
			system("cls");
			gotoxy(40,10);
			cout << "--------------------------------------------------" << endl;
			gotoxy(40,11);
			cout << "\t\tInvalid Input" << endl;
			gotoxy(40,12);
			cout << "--------------------------------------------------" << endl;
			gotoxy(40,13);
			system("pause");
			goto repeat;
	}
	
}

void salesMenu(string &name) 
{
	char input;
	repeat:
	int y = 0;
	system("cls");
	gotoxy(40,y);
	y += 1;
	cout << "--------------------------------------\n";
	gotoxy(40,y);
	y += 1;
	cout << "-              MAIN MENU             -\n";
	gotoxy(40,y);
	y += 1;
	cout << "--------------------------------------\n";
	gotoxy(40,y);
	y += 1;
	cout << "Hi " << name << "!" << endl;
	gotoxy(40,y);
	y += 1;
	cout << "You currenly have " << cartGameTitle.size() << " item/s in your cart" << endl;
	gotoxy(40,y);
	y += 1;
	cout << "1. Rent a Game" << endl;
	gotoxy(40,y);
	y += 1;
	cout << "2. Show Transactions" << endl;
	gotoxy(40,y);
	y += 1;
	cout << "3. Account Management" << endl;
	gotoxy(40,y);
	y += 1;
	cout << "4. Continue to payment" << endl;
	y += 1;
	gotoxy(40,y);
	cout << "5. Logout" << endl;
	gotoxy(40,y);
	y += 1;
	cout << "What would you like to do? ";
	cin >> input;
	switch (input)
	{
		case '1':
			rentGame();
			goto repeat;
			break;
		case '2':
			userTransactions(name);
			goto repeat;
			break;
		case '3':
			accountManage();
			break;
		case '4':
			payment(name);
			updateStock();
			goto repeat;
			break;
		case '5':
			break;
		default:
			system("cls");
			gotoxy(40,10);
			cout << "--------------------------------------------------" << endl;
			gotoxy(40,11);
			cout << "\t\tInvalid Input" << endl;
			gotoxy(40,12);
			cout << "--------------------------------------------------" << endl;
			gotoxy(40,13);
			system("pause");
			goto repeat;
	}
	
}

void adminMenu() 
{
	char input;
	repeat:
	system("cls");
	gotoxy(40,10);
	cout << "--------------------------------------\n";
	gotoxy(40,11);
	cout << "-              ADMIN MENU            -\n";
	gotoxy(40,12);
	cout << "--------------------------------------\n";
	gotoxy(40,13);	
	cout << "Welcome Admin!" << endl;
	gotoxy(40,14);	
	cout << "1. Add Games\n";
	gotoxy(40,15);	
	cout << "2. Show Registered Users\n";
	gotoxy(40,16);	
	cout << "3. Show Overall Transactions\n";
	gotoxy(40,17);	
	cout << "4. Return to Login Menu\n";
	gotoxy(40,18);	
	cout << "5. Exit\n";
	gotoxy(40,19);
	cin >> input;
	switch (input)
	{
		case '1':
			addGame();
			goto repeat;
			break;
		case '2':
			showRegisteredUsers ();
			goto repeat;
			break;
		case '3':
			adminTransactions();
			goto repeat;
			break;
		case '4':
			main();
			break;
		case '5':
			break;	
	}
	
}

void loadingScreen()
{
	int y = 10;
	string menu[3] = {"----------------------------------------\n", "-     CTRL-ALT-ELITE-RENTAL-SERVICE    -\n",
	"----------------------------------------\n"};
	for (int i = 0; i < 3; i++)
	{
		gotoxy(40,y);
		cout << menu[i];
		y++;
	}
	y += 1;
	gotoxy(40,y);
	cout << "Loading: <";
	for (int i = 0; i < 10; i++) {
		cout << "===";
		Sleep(300);
	}
	cout << ">\n" ;	
	y+=1;
	gotoxy(40,y);
	system("pause");
}
