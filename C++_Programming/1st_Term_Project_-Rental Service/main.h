#ifndef _MAIN_
#define _MAIN_
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <map>
#include <iomanip>
#include <algorithm>
#include <set>
#include <functional>
using namespace std;
//Cart vectors need to be global
vector<string> cartGenre;
vector<string> cartGameTitle;
vector<int> cartGameDays;
vector<int> cartPrice;
string currentUser;
int isFullscreen = 0;

string solidTop, solidBottom, body;
int moveDown = 0;

void fullscreen()
{
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

void centerText(string inputText, int positionX, int positionY, bool move_Down, bool autoCenter)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Text;
	Text = GetLargestConsoleWindowSize(hConsole);
	// X = 120
	// Y = 30
	if (positionX == 0 && positionY == 0 && autoCenter == 0)
	{
		//AutoCenters Text
		Text.X /= 2;
		Text.X -= (inputText.size()/2);
		Text.Y /= 2;
		Text.Y += moveDown;
		moveDown++;
	}
	else if ( autoCenter == 1)
	{
		Text.X /= 2;
		Text.X -= (inputText.size()/2);
		Text.Y = positionY;
		if (positionY == 0)
			Text.Y += moveDown;
		if (move_Down == 1)
		moveDown++;	
	}
	else
	{
		if (move_Down == true)
		{
	
			Text.X = positionX;
			Text.Y = positionY;
			if (positionY == 0)
				Text.Y += moveDown;
			moveDown++;			
		}
		else
		{
			Text.X = positionX;
			Text.Y = positionY;			
		}
	}
	SetConsoleCursorPosition(hConsole, Text);
	cout << inputText;
}

void createRectangle(int size)
{
	for(int top = 0; top < size; top++)
	{
		if (top == 0)
		{
			solidTop.push_back(char(201));
		} 
		else if (top == size - 1)
		{
			solidTop.push_back(char(187));
		} 
		else 
		{
			solidTop.push_back(char(205));
		}
	}	
	for(int bottom = 0; bottom < size; bottom++)
	{
		if (bottom == 0)
		{
			solidBottom.push_back(char(200));
		} 
		else if (bottom == size - 1)
		{
			solidBottom.push_back(char(188));
		} 
		else 
		{
			solidBottom.push_back(char(205));
		}
	}
	for (int j = 0; j < size; j++)
	{
		if(j == 0 || j == size - 1)
		{
			body.push_back(char(186));			
		} else {
			body.push_back(' ');
		}
	}
}

void createDirectory() 
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

inline const char* convertString(string &name)
{
	const char * converted = name.c_str();
	return converted;
}

#endif
