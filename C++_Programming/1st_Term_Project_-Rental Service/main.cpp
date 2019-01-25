#include "userAccounts.h"
#include "sales.h"
#include "stats.h"

void Welcome_Screen()
{
	createRectangle(100);
	centerText(solidTop, 0, 0, true, false);
	centerText(body,0,0,true, false);
	centerText(body,0,0,true, false);
	centerText("CTRL ALT ELITE'S RENTAL SERVICE!", 106, 35, false, false);
	centerText(body,0,0,true, false);
	centerText(solidBottom, 0,0,true, false);
	centerText("LOADING...", 0, 0,true, false);
	stringstream convert;
	stringstream convert2;
	string temp1, temp2;
	char loading1 = char(177), loading2 = char(219);
	convert << loading1;
	convert >> temp1;
	convert2 << loading2;
	convert2 >> temp2;
	for (int i = 0; i < 100; i++)
	{
		centerText(temp1, 70 + i, 39, false, false);	
	}
	for (int i = 0; i < 100; i++)
	{
		if (i == 99)
		centerText(temp2, 70 + i, 39, true, false);
		else
		centerText(temp2, 70 + i, 39, false, false);
//		Sleep(50);
	}
	centerText("Press Any Key to Continue...", 0, 0, true, false);
	cin.get();
	solidTop.clear();
	solidBottom.clear();
	body.clear();
}

int main() {
	//Create Directories
	system("color 0a");
	createDirectory();
	system("cls");
	string userFullName;
	if (isFullscreen == 0)
	{
		fullscreen();
		isFullscreen += 1;
	}
	Welcome_Screen();
	// End Introduction
	string input;
	createRectangle(80);
	// Draw Menu
	repeat:
	system("cls");
	moveDown = 0;
	centerText(solidTop, 120 - (solidTop.size() / 2) , 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText("INTRO MENU", 116, 2, false, false);
	centerText(solidBottom, 120 - (solidBottom.size() / 2), 0, true, false);
	centerText("[1] Login", 80, 0, true, false);
	centerText("[2] Create an Account", 80, 0, true, false);
	centerText("[3] Exit", 80, 0, true, false);
	centerText("Enter Desired Choice: ", 80, 0, true, false);
	// Draw Menu End
	// Initialize Checking
	cin >> input;
	if (input == "1")
	{
		userFullName = loginUser();
		salesMenu(userFullName);
		goto repeat;	
	} else if(input == "2")	{
		registerUser();
		goto repeat;
	} else if(input == "3") {
		exit(0);	
	} else {
		system("cls");
		moveDown = 0;
		centerText(solidTop, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText("INVALID INPUT!!", 114, 35, false, false);
		centerText(solidBottom, 0, 0, true, false);			
		Sleep(1000);
		goto repeat;		
	}
}
