#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

void registerUser();
void loginUser();

int main() {
	char input;
	cout << "<--Welcome to Ctrl-Alt-Elite Banking Services-->" << endl;
	Sleep(1000);
	start:
	system("cls");
	cout << "------------------------------------------------" << endl;
	cout << "                   MAIN MENU" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "1. Login" << endl;
	cout << "2. Register" << endl;	
	cout << "3. Exit" << endl;
	cout << "Enter choice: ";
	cin >> input;
	switch (input)
	{
		case '1':
			loginUser();
			break;
		case '2':
			registerUser();
			break;
		case '3':
			return 0;
		default:
			cerr << "Invalid Input. Please Try Again." << endl;
			system("pause");
			goto start;
			break;
			
	}
}

void deposit(string accHolder)
{
	string accHolderLog = accHolder + ".log";
	system("cls");
	int deposit, prevBalance, finalBalance;
	cout << "----------------------------" << endl;
	cout << "            DEPOSIT" << endl;
	cout << "----------------------------" << endl;
	cout << "Input desired amount to be deposited: ";
	cin >> deposit;
	int temp = deposit;
	
	char accHolderChar[accHolder.size() + 1];
	accHolder.copy(accHolderChar, accHolder.size() + 1);
	accHolderChar[accHolder.size()] = '\0';
	char accHolderLogChar[accHolderLog.size() + 1];
	accHolderLog.copy(accHolderLogChar, accHolderLog.size() + 1);
	accHolderLogChar[accHolderLog.size()] = '\0';
	
	fstream bankAccount;
	fstream logTransaction;
	
	bankAccount.open(accHolderChar, ios::in | ios::out);
	logTransaction.open(accHolderLogChar, ios::out | ios::app);
	bankAccount >> prevBalance;
	finalBalance = prevBalance + deposit;
	bankAccount.clear();
	bankAccount.seekp(0);
	bankAccount.tellp();
	bankAccount << finalBalance;
	bankAccount.close();
	logTransaction << "Deposit    " << deposit << "   " << prevBalance << "   " << finalBalance << endl;
}

void withdraw(string accHolder)
{
	system("cls");
	string accHolderLog = accHolder + ".log";
	int withdraw, finalBalance,	prevBalance;
	cout << "----------------------------" << endl;
	cout << "            WITHDRAW" << endl;
	cout << "----------------------------" << endl;
	cout << "Input desired amount to be withdrawn: ";
	cin >> withdraw;
	
	char accHolderChar[accHolder.size() + 1];
	accHolder.copy(accHolderChar, accHolder.size() + 1);
	accHolderChar[accHolder.size()] = '\0';
	char accHolderLogChar[accHolderLog.size() + 1];
	accHolderLog.copy(accHolderLogChar, accHolderLog.size() + 1);
	accHolderLogChar[accHolderLog.size()] = '\0';
	
	fstream bankAccount;
	fstream logTransaction;
	bankAccount.open(accHolderChar, ios::in | ios::out);
	logTransaction.open(accHolderLogChar, ios::out | ios::app);
	bankAccount >> prevBalance;
	finalBalance = prevBalance - withdraw;
	bankAccount.close();
	bankAccount.open(accHolderChar, ios::out);
	bankAccount << finalBalance;
	bankAccount.close();
	logTransaction << "Withdraw   " << withdraw << "   " << prevBalance << "   " << finalBalance << endl;
}

void balance(string accHolder)
{
	system("cls");
	int balance;
	cout << "--------------------------------------" << endl;
	cout << "             CHECK BALANCE" << endl;
	cout << "--------------------------------------" << endl;
	char accHolderChar[accHolder.size() + 1];
	accHolder.copy(accHolderChar, accHolder.size() + 1);
	accHolderChar[accHolder.size()] = '\0';
	ifstream checkBalance;
	checkBalance.open(accHolderChar);
	checkBalance >> balance;
	cout << "You currently have: " << balance << endl;
	system("pause");
}

void transactions(string accHolder)
{
	accHolder += ".log";
	string transaction;
	cout << "------------------------------------" << endl;
	cout << "               TRANSACTIONS" << endl;
	cout << "------------------------------------" << endl;
	cout << "Type     " << "Amount  " << "P.Balance  " << "T.Balance" << endl;
	char accHolderChar[accHolder.size() + 1];
	accHolder.copy(accHolderChar, accHolder.size() + 1);
	accHolderChar[accHolder.size()] = '\0';
	ifstream logTransaction;
	logTransaction.open(accHolderChar);
	while(!logTransaction.eof())
	{
		getline(logTransaction, transaction);
		cout << transaction << endl;
	}
	system("pause");
}

void bankMenu(string fullName)
{
	start:
	system("cls");
	char input;
	cout << "---------------------------------" << endl;
	cout << "             BANK MENU" << endl;
	cout << "---------------------------------" << endl;
	cout << "Welcome " << fullName << "!"<< endl;
	cout << "1. Deposit" << endl;
	cout << "2. Withdraw" << endl;
	cout << "3. Balance" << endl;
	cout << "4. Check Transactions" << endl;
	cout << "5. Return to Main_Menu" << endl;
	cout << "6. Exit" << endl;
	cout << "What would you like to do? ";
	cin >> input;
	switch (input)
	{
		case '1':
			deposit(fullName);
			goto start;
			break;
		case '2':
			withdraw(fullName);
			goto start;
			break;
		case '3':
			balance(fullName);
			goto start;
			break;
		case '4':
			transactions(fullName);
			goto start;
			break;
		case '5':
			main();
			break;
		case '6':
			system("pause");
			break;
		default:
			cerr << "Invalid choice. Please try again!" << endl;
			system("pause");
			break;
	}
}

void duplicateCheck(string username)
{
	string checkUsername;
	ifstream data;
	data.open("credentials.dat");
	while(!data.eof())
	{
		data >> checkUsername;
		if (checkUsername == username)
		{
			cout << "User already exists!" << endl;
			system("pause");
			main();
		}
	}
}

void registerUser()
{
	string fullName, nameInput,passInput,passInputCheck;
	int count;
	start:
	system("cls");
	cout << "--------------------------------------" << endl;
    cout << "            Create Account" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Enter Full Name: ";
	if (cin.peek())
	{
		cin.ignore();
	}
	getline(cin, fullName);
	cout << "Enter Username: ";
	cin >> nameInput;
	cout << "Enter Password: ";
	cin >> passInput;
	cout << "Re-enter Password: ";
	cin >> passInputCheck;
	cout << endl;
	char fullNameChar[fullName.size() + 1];
	fullName.copy(fullNameChar, fullName.size() + 1);
	fullNameChar[fullName.size()] = '\0';
	fstream data;
	fstream accHolder;
	data.open("credentials.dat", ios::out | ios::app);
	duplicateCheck(nameInput);
	// Initialize Password Check
	if (passInput != passInputCheck)
	{
		cout << "Password is not the same!" << endl;
		system("pause");
		goto start;
	}
	else
	{
		accHolder.open(fullNameChar, ios::out);
	}
	if (data.is_open())
	{
		data << fullName << endl << nameInput << " " << passInput << endl;
		accHolder << "0";
		data.close();
		accHolder.close();
		cout << "You have been registered!!" << endl;
		system("pause");
		main();
	}	
}

void loginUser()
{
	string fullName, nameInput, passInput, userPass, userPassCheck;
	cout << "----------------------------------" << endl;
	cout << "              LOGIN" << endl;
	cout << "----------------------------------" << endl;
	cout << "Enter username: ";
	cin >> nameInput;
	cout << "Enter password: ";
	cin >> passInput;
	userPass = nameInput + " " + passInput;
	fstream data;
	data.open("credentials.dat");
	if (!data.is_open())
	{
		cerr << "No existing users. Please create an account first." << endl;
		system("pause");
		main();
	}
	else
	{
		while(!data.eof())
		{
			getline(data, fullName);
			getline(data, userPassCheck);
			if (userPassCheck == userPass)
			{
				cout << "Login Success!!" << endl;
				Sleep(1000);
				bankMenu(fullName);
				break;
			}
		}
	}
}
