#ifndef _CREDENTIALS_
#define _CREDENTIALS_
#include "main.h"
	
string duplicateCheck();
void storeUserData(string&, string&, string&);
string userNameTemp;

static const string hideInput()
{
char x;
string out;
	while (x != 13)
	{
		x = getch();
		if (x == 13)
		break;
		if (x != 8)
		{	
			cout << "*";
			out.push_back(x);
		}
		else
		{
			if (out.size() != 0)
			{
				cout << "\b \b";
				out.pop_back();
			}
		}
	}
	return out;
}

void registerUser() 
{
	string fullName, userInput, passInput, passCheck;
	repeat:
	system("cls");
	gotoxy(40,10);
	cout << "-----------------------------------------------" << endl;
	gotoxy(40,11);
	cout << "\t\tCREATE AN ACCOUNT" << endl;
	gotoxy(40,12);
	cout << "-----------------------------------------------" << endl;
	gotoxy(40,13);
	cout << "Enter Full Name: ";
	if (cin.peek())
	{
		cin.ignore();
	}
	getline(cin, fullName);
	gotoxy(40,14);
	cout << "Enter Username: ";
	userInput = duplicateCheck();
	gotoxy(40,15);
	cout << "Enter Password: ";
	passInput = hideInput();
	gotoxy(40,16);
	cout << "Re-enter Password: ";
    cin.ignore(100,'\n');
	passCheck = hideInput();	
	if (passInput == passCheck) 
	{
		system("cls");
		gotoxy(40,10);
		cout << "--------------------------------------------------" << endl;
		gotoxy(40,11);
		cout << "\t\tREGISTERED SUCCESSFULLY!" << endl;
		gotoxy(40,12);
		cout << "--------------------------------------------------" << endl;
		storeUserData(fullName, userInput, passInput);
		system("pause");
	}
	else
	{
		system("cls");
		gotoxy(40,10);
		cout << "----------------------------------------------------" << endl;
		gotoxy(40,11);
		cout << "\t\tPASSWORD IS NOT THE SAME!" << endl;
		gotoxy(40,12);
		cout << "----------------------------------------------------" << endl;	
		system("pause");
		goto repeat;
	}
}

string loginUser() 
{
	repeat:
	string userInput;
	string passInput, passCheck, fullName;
	string fileName = "users/";
	system("cls");
	gotoxy(40,10);
	cout << "-----------------------------------------" << endl;
	gotoxy(40,11);
	cout << "\t\tLOGIN" << endl;
	gotoxy(40,12);
	cout << "-----------------------------------------" << endl;	
	gotoxy(40,13);
	cout << "Enter Username: ";
	cin >> userInput;
	userNameTemp = userInput;
	gotoxy(40,14);
	cout << "Enter Password: ";
	passInput = hideInput();
	//Read user file
	fileName += userInput;
	fstream userFile;
	userFile.open(convertString(fileName));
	if (!userFile.is_open())
	{
		system("cls");
		gotoxy(40,10);
		cout << "---------------------------------------------" << endl;
		gotoxy(40,11);
		cout << "\t\tINVALID USERNAME/PASSWORD"<< endl;
		gotoxy(40,12);
		cout << "---------------------------------------------" << endl;
		system("pause");
	}
	else
	{
		while (!userFile.eof())
		{
			getline(userFile, fullName);
			getline(userFile, passCheck);
			if (passInput == passCheck)
			{
				system("cls");
				gotoxy(40,10);
				cout << "-----------------------------------------------------" << endl;
				gotoxy(40,11);
				cout << "\t\tWELCOME " << fullName << "!"<< endl;
				gotoxy(40,12);
				cout << "-----------------------------------------------------" << endl;
				Sleep(1000);
				return fullName;
			}		
		}
		system("cls");
		gotoxy(40,10);
		cout << "-----------------------------------------------------" << endl;
		gotoxy(40,11);
		cout << "             INVALID USERNAME/PASSWORD\n";
		gotoxy(40,12);
		cout << "-----------------------------------------------------" << endl;
		gotoxy(40,13);
		system("pause");
		goto repeat;				
	}
}

int accountManage()
{
	repeat:
	int x = 40, y = 0; //Coorinates for the screen
	string fileName = "users/" + userNameTemp;
	string UserFullName;
	string oldPassword;
	string oldPasswordCheck;
	string newPassword;
	string newPasswordCheck;
	// These Variables are used for checking the user inputs
	vector<string> prevFullName;
	vector<string> prevPassword;
	//Vectors to store the previous data	
	system("cls");
	gotoxy(x,y);
	cout << fileName;
	cout << "----------------------------------------------------" << endl;
	y += 1;
	gotoxy(x,y);
	cout << "\t\tCHANGE PASSWORD" << endl;
	y += 1;
	gotoxy(x,y);
	cout << "----------------------------------------------------" << endl;
	y += 1;
	gotoxy(x,y);
	cout << "Enter Old Password: ";
	oldPassword = hideInput();	
	//Initialize password checking in file
	fstream userData;
	userData.open(convertString(fileName));
	while (!userData.eof())
	{
		getline(userData, UserFullName);
		getline(userData, oldPasswordCheck);
		if (oldPassword != oldPasswordCheck)
		{
			y += 1;
			gotoxy(x,y);
			cout << "Invalid Password\n";
			y += 1;
			gotoxy(x,y);
			system("pause");
			goto repeat;
		}
		else
		{
			prevFullName.push_back(UserFullName);
			prevPassword.push_back(oldPassword);
		}
	}	
	userData.close();
	y += 1;
	gotoxy(x,y);
	cout << "Enter New Password: ";
	newPassword = hideInput();
	y += 1;
	gotoxy(x,y);
	cout << "Re-Enter Password: ";
    cin.ignore(100,'\n');
	newPasswordCheck = hideInput();
	if (newPassword == newPasswordCheck)
	{	
		
		userData.open(convertString(fileName), ios::out);
		for (unsigned int i = 0; i < prevFullName.size(); i++)
		{
			prevPassword[i] = newPassword;
			userData << prevFullName[i] << endl << prevPassword[i];
		}
		userData.close();
		y += 1;
		gotoxy(x,y);
		cout << "Your password has been changed!\n";
		y += 1;
		gotoxy(x,y);
		system("pause");
		return 0;
	}
	else
	{
		y += 1;
		gotoxy(x,y);
		cout << "Password is not the same\n";
		y += 1;
		gotoxy(x,y);
		system("pause");
		goto repeat;
	}
}

/*
	This function here is to check if there is
	an existing username or not.
*/
string duplicateCheck() 
{
	string fileName = "users/";
	string username;
	cin >> username;
	fileName += username;
	fstream userFile;
	userFile.open(convertString(fileName));
	if (!userFile.is_open())
	{
		return username;	
	}
	else
	{
		system("cls");
		gotoxy(40,10);
		cout << "---------------------------------------------" << endl;
		gotoxy(40,11);
		cout << "\t\tUsername Taken!" << endl;
		gotoxy(40,12);
		cout << "---------------------------------------------" << endl;
		system("pause");
		registerUser();
	}
}

void storeUserData (string &fullName, string &username, string &password) 
{
	string fileName = "users/" + username;
	fstream userFile;
	userFile.open(convertString(fileName), ios::out);
	userFile << fullName << endl << password;
}

#endif
