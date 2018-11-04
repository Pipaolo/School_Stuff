#ifndef _USERACCOUNTS_
#define _USERACCOUNTS_
#include "admin.h"
#include "main.h"

struct User
{
	string fullName, username, password, passwordCheck;
	void storeUserData(string &fullName, string username, string password)
	{
		string fileName = "users/" + username;
		ofstream userData;
		userData.open(convertString(fileName), ios::out);
		userData << fullName << endl << password;
		userData.close();
		//Store username password to masterlist
		//Check if file empty
		fstream adminData;
		adminData.open("admin/userList");
		if (!adminData.is_open())
		{
			adminData.open("admin/userList", ios::out);
			adminData << fullName;
			adminData.close();		
		}
		else
		{
			adminData.close();
			adminData.open("admin/userList", ios::out | ios::app);
			adminData << endl << fullName;
			adminData.close();		
		}
	}
	
	string checkUserData(string &userInput, string &passwordInput)
	{
		string fileName = "users/" + userInput;
		ifstream userData;
		userData.open(convertString(fileName));
		// Check if file is existing
		if (!userData.is_open())
		{
			system("cls");
			moveDown = 0;
			centerText(solidTop, 0, 0, true, false);
			centerText(body, 0, 0, true, false);
			centerText(body, 0, 0, true, false);
			centerText(body, 0, 0, true, false);
			centerText("INCORRECT USERNAME/PASSWORD!", 105, 35, false, false);
			centerText(solidBottom, 0, 0, true, false);			
			Sleep(1000);
			return "";		
		}
		else
		{
			while (!userData.eof())
			{
				getline(userData, fullName);
				getline(userData, passwordCheck);
				if (passwordInput == passwordCheck)
				{
					currentUser = userInput;
					system("cls");
					moveDown = 0;
					centerText(solidTop, 0, 0, true, false);
					centerText(body, 0, 0, true, false);
					centerText(body, 0, 0, true, false);
					centerText(body, 0, 0, true, false);
					centerText("WELCOME " + fullName, 109, 35, false, false);
					centerText(solidBottom, 0, 0, true, false);			
					Sleep(1000);
					return fullName;
				}
			}
			system("cls");
			moveDown = 0;
			centerText(solidTop, 0, 0, true, false);
			centerText(body, 0, 0, true, false);
			centerText(body, 0, 0, true, false);
			centerText(body, 0, 0, true, false);
			centerText("INCORRECT USERNAME/PASSWORD!", 105, 35, false, false);
			centerText(solidBottom, 0, 0, true, false);			
			Sleep(1000);
			return "";
		}	
	}
	
	//To check if the username is unique
	bool usernameDuplicate(string &usernameInput)
	{
		string fileName = "users/" + usernameInput;
		string usernameCheck;
		// Open userData file
		fstream userData;
		userData.open(convertString(fileName), ios::in);
		if (!userData.is_open())
		{
			usernameCheck = usernameInput;
			return false;
		}
		else
		{
			system("cls");
			moveDown = 0;
			centerText(solidTop, 0, 0, true, false);
			centerText(body, 0, 0, true, false);
			centerText(body, 0, 0, true, false);
			centerText(body, 0, 0, true, false);
			centerText("USERNAME TAKEN", 114, 35, false, false);
			centerText(solidBottom, 0, 0, true, false);			
			Sleep(1000);
			return true;		
		}
	}
};

string hideInput()
{
	char input;
	string convertedInput;
	while(input != 13)
	{
		input = getch();
		if (input == 13)
		break;
		if (input != 8)
		{
			cout << "*";
			convertedInput.push_back(input);
		}
		else
		{
			if(convertedInput.size() != 0)
			{
				cout << "\b \b";
				convertedInput.pop_back();
			}
		}
	}
	return convertedInput;		
}

int changePassword()
{
	User user;
	string tempFullName;
	string fileName = "users/" + currentUser;
	string oldPassword;
	string oldPasswordCheck;
	string newPassword;
	string newPasswordCheck;
	solidTop.clear();
	solidBottom.clear();
	body.clear();
	createRectangle(120);
	repeat:
	system("cls");
	moveDown = 0;
	centerText(solidTop, 120 - (solidTop.size() / 2) , 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(" _____ _____ _____ _____ _____ _____    _____ _____ _____ _____ _ _ _ _____ _____ ____  ", 94, 1, false, true);
	centerText("|     |  |  |  _  |   | |   __|   __|  |  _  |  _  |   __|   __| | | |     | __  |    | ", 94, 2, false, true);
	centerText("|   --|     |     | | | |  |  |   __|  |   __|     |__   |__   | | | |  |  |    -|  |  |", 94, 3, false, true);
	centerText("|_____|__|__|__|__|_|___|_____|_____|  |__|  |__|__|_____|_____|_____|_____|__|__|____/ ", 94, 4, false, true);
	centerText(solidBottom, 120 - (solidBottom.size() / 2), 0, true, false);
	centerText("Enter Old Password: ", 80, 0, true, false );
	oldPassword = hideInput();
	fstream userData(convertString(fileName));
	while (!userData.eof())
	{
		getline(userData, tempFullName);
		getline(userData, oldPasswordCheck);
		if (oldPassword == oldPasswordCheck)
		{
			centerText("Enter New Password: ", 80, 0, true, false );
			newPassword = hideInput();
			centerText("Enter New Password: ", 80, 0, true, false );
			newPasswordCheck = hideInput();
			if (newPassword == newPasswordCheck)
			{
				userData.close();
				userData.open(convertString(fileName), ios::out);
				userData << tempFullName << endl << newPassword;
				
				system("cls");
				centerText(solidTop, 0, 0, true, false);
				centerText(body, 0, 0, true, false);
				centerText(body, 0, 0, true, false);
				centerText(body, 0, 0, true, false);
				centerText("PASSWORD HAS BEEN CHANGED!", 105, 35, false, false);
				centerText(solidBottom, 0, 0, true, false);			
				Sleep(1000);
				userData.close();
				return 0;
				break;
			}
			else
			{
				system("cls");
				centerText(solidTop, 0, 0, true, false);
				centerText(body, 0, 0, true, false);
				centerText(body, 0, 0, true, false);
				centerText(body, 0, 0, true, false);
				centerText("PASSWORD IS NOT THE SAME", 105, 35, false, false);
				centerText(solidBottom, 0, 0, true, false);			
				Sleep(1000);
				return 0;
				break;			
			}
		}
	}
	system("cls");
	centerText(solidTop, 0, 0, true, false);
	centerText(body, 0, 0, true, false);
	centerText(body, 0, 0, true, false);
	centerText(body, 0, 0, true, false);
	centerText("INCORRECT PASSWORD!", 105, 35, false, false);
	centerText(solidBottom, 0, 0, true, false);			
	Sleep(1000);
	return 0;	
}

string loginUser() 
{
	User loginUser;
	solidTop.clear();
	solidBottom.clear();
	body.clear();
	createRectangle(80);
	repeat:
	system("cls");
	moveDown = 0;
	centerText(solidTop, 120 - (solidTop.size() / 2) , 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText("LOGIN MENU", 116, 2, false, false);
	centerText(solidBottom, 120 - (solidBottom.size() / 2), 0, true, false);
	centerText("Enter Username: ", 80, 0, true, false);
	cin >> loginUser.username;
	centerText("Enter Password: ", 80, 0, true, false);
	loginUser.password = hideInput();
	// this is here to check if admin account is used
	if (loginUser.username == "admin" && loginUser.password == "admin")
	{
		adminMenu();		
	}
	else
	{
		if (loginUser.checkUserData(loginUser.username, loginUser.password).empty())
			goto repeat;
		return loginUser.checkUserData(loginUser.username, loginUser.password);		
	}
}

void registerUser()
{
	User user;
	solidTop.clear();
	solidBottom.clear();
	body.clear();
	createRectangle(80);
	repeat:
	system("cls");
	moveDown = 0;
	centerText(solidTop, 120 - (solidTop.size() / 2) , 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText("CREATE ACCOUNT", 114, 2, false, false);
	centerText(solidBottom, 120 - (solidBottom.size() / 2), 0, true, false);
	centerText("Enter FullName: ", 80, 0, true, false);
	if (cin.peek())
	{
		cin.ignore();
	}
	getline(cin, user.fullName);
	centerText("Enter Username: ", 80, 0, true, false);
	cin >> user.username;
	// Initialize Username Checker
	if (user.usernameDuplicate(user.username) == 1)
		goto repeat;
	// End of Username Checker
	centerText("Enter Password: ", 80, 0, true, false);
	user.password = hideInput();
	centerText("Re-enter Password: ", 80, 0, true, false);
	user.passwordCheck = hideInput();
	// Initialize Password Check
	if (user.password != user.passwordCheck)
	{
		system("cls");
		moveDown = 0;
		centerText(solidTop, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText("PASSWORD IS NOT THE SAME", 109, 35, false, false);
		centerText(solidBottom, 0, 0, true, false);			
		Sleep(1000);
		goto repeat;		
	}
	else
	{
		//Store User Data
		user.storeUserData(user.fullName, user.username, user.password);
		// End of store User Data
		system("cls");
		moveDown = 0;
		centerText(solidTop, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText("REGISTERED SUCCESSFULLY", 109, 35, false, false);
		centerText(solidBottom, 0, 0, true, false);			
		Sleep(1000);		
	}
}

#endif
