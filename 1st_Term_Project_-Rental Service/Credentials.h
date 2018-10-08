#ifndef _credentials_
#define _credentials_
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
using std::cin;
using std::string;
using std::cout;
using std::endl;

void registerUser()
{
	repeat:
	string fullName;
	string userInput, userCheck, passInput, passCheck;
	system("cls");
	cout << "------------------------------------------" << endl;
	cout << "               Create Account" << endl;
	cout << "------------------------------------------" << endl;
	cout << "Enter Full Name: ";
	if(cin.peek())
	{
		cin.ignore();
	}
	getline(cin, fullName);
	cout << "Enter Username: ";
	cin >> userInput;
	cout << "Enter Password: ";
	cin >> passInput;
	cout << "Re-Enter Password: ";
	cin >> passCheck;
	// Initialize File stream
	std::fstream credentials;
	credentials.open("users/credentials.dat");
	/*
	Commence Username Duplicate Checker
	*/
	if(credentials.is_open())
	{
		while (!credentials.eof())
		{
			credentials >> userCheck;
			if (userInput == userCheck)
			{
				cout << "Username Taken!" << endl;
				system("pause");
				credentials.close();
				goto repeat;
				break;
			} 
			else if (passInput != passCheck)
			{
				cout << "Password is not the same!" << endl;
				system("pause");
				credentials.close();
				goto repeat;
				break;
			}
		}
		credentials.close();
		// If there is no duplicate then create the file containing the info
		credentials.open("users/credentials.dat", std::ios::out | std::ios::app);
		credentials << fullName << endl << userInput << " " << passInput << endl;
		credentials.close();
		cout << "Registered Successfully!" << endl;
		system("pause");		
	}
	else
	{
		// If there is no duplicate then create the file containing the info
		credentials.open("users/credentials.dat", std::ios::out | std::ios::app);
		credentials << fullName << endl << userInput << " " << passInput << endl;
		credentials.close();
		cout << "Registered Successfully!" << endl;
		system("pause");
	}
}

string loginUser()
{
	repeat:
	system("cls");
	string fullName, username, password, userCombined, checkUser;
	std::ifstream credentials("users/credentials.dat");
	cout << "----------------------------------------------------" << endl;
	cout << "                   LOGIN MENU" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;
	userCombined = username + " " + password;
	if(credentials.is_open())
	{
		while(!credentials.eof())
		{
			getline(credentials,fullName);
			getline(credentials,checkUser);
			if (userCombined == checkUser)
			{
				cout << "Login Successfully!" << endl;
				system("pause");
				return fullName;
				break;
			}
		}			
		cout << "Incorrect username or password!" << endl;
		system("pause");
		goto repeat;
	}
	else
	{
		std::cerr << "There is no existing users!" << endl;
		system("pause");
		goto repeat;
	}
}

void showUsers()
{
	std::vector<string> nameList;
	string name;
	system("cls");
	cout << "----------------------------------------------------" << endl;
	cout << "                     USERS LIST" << endl;
	cout << "----------------------------------------------------" << endl;	
	std::fstream users;
	users.open("users/credentials.dat");
	while (!users.eof())
	{
		getline(users,name);
		nameList.push_back(name);
	}
	for (unsigned int i = 0; i < nameList.size() - 1; i += 2)
	{
		cout << nameList.at(i) << endl;
	}
	cout << "----------------------------------------------------" << endl;		
	nameList.clear();
	system("pause");
}

#endif
