#ifndef _MAIN_
#define _MAIN_
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

vector<string> cartGenre;
vector<string> cartGameTitle;
vector<int> cartGameDays;
vector<int> cartTotalPrice;

void createDirectory () 
{
/*
	Here is the createDirectory Function is called
	so basically it's using the commands of the
	windows console to create a folder. Note: This
	only works on windows and not on other Operating
	Sytems.
*/
	system("mkdir resources");
	system("mkdir users");
	system("mkdir log");
	system("mkdir admin");
}

void gotoxy(const int x, const int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	COORD CenterText;
	CenterText.X = x;
	CenterText.Y = y;
	
	SetConsoleCursorPosition(hConsole, CenterText);
}

inline const char* convertString(string &name)
{
	const char * converted = name.c_str();
	return converted;
}

#endif
