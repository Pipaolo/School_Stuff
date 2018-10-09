#ifndef _CREDENTIALS_
#define _CREDENTIALS_
#include "main.h"

using std::cin;
using std::string;
using std::cout;
using std::endl;


void registerUser()
{
	repeat:
	string fullName;
	string userInput, userCheck, passInput, passCheck;
	cout << "------------------------------------------" << endl;
	cout << "               Create Account" << endl;
	cout << "------------------------------------------" << endl;
	cout << "Enter Full Name: ";
	if(cin.peek()) //This function is used to check if you pressed enter or not
	{			   //If yes, then the program will ignore it.
		cin.ignore();
	}
	getline(cin, fullName); //Get line is a function of string, that can accept spaces as an input
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
				credentials.close();
				goto repeat;
				break;
			} 
			else if (passInput != passCheck)
			{
				cout << "Password is not the same!" << endl;
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
	}
	else
	{
		// If there is no duplicate then create the file containing the info
		credentials.open("users/credentials.dat", std::ios::out | std::ios::app);
		credentials << fullName << endl << userInput << " " << passInput << endl;
		credentials.close();
		cout << "Registered Successfully!" << endl;
	}
}

string loginUser()
{
	repeat:
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
				return fullName;
				break;
			}
		}			
		cout << "Incorrect username or password!" << endl;
		goto repeat;
	}
	else
	{
		std::cerr << "There is no existing users!" << endl;
		goto repeat;
	}
}

void showUsers()
{
	std::vector<string> nameList;
	string name;
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
}

#endif
