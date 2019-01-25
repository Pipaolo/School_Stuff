#ifndef _INVENTORY_
#define _INVENTORY_
#include "main.h"

void showUserTransaction(string &accHolder)
{
	
// _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ 
//|_   _| __  |  _  |   | |   __|  _  |     |_   _|     |     |   | |   __|
//  | | |    -|     | | | |__   |     |   --| | | |-   -|  |  | | | |__   |
//  |_| |__|__|__|__|_|___|_____|__|__|_____| |_| |_____|_____|_|___|_____|

	string gameTitle;
	string gameRentDays;
	string gameRentedOn;
	string gameDueDate;
	string gameTotalPrice;
	string fileName = "log/" + accHolder;
	repeat:
	system("cls");
	solidTop.clear();
	solidBottom.clear();
	body.clear();
	moveDown = 0;
	createRectangle(100);
	centerText(solidTop, 120 - (solidTop.size() / 2) , 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(" _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ", 84, 1, false, true);
	centerText("|_   _| __  |  _  |   | |   __|  _  |     |_   _|     |     |   | |   __|", 84, 2, false, true);
	centerText("  | | |    -|     | | | |__   |     |   --| | | |-   -|  |  | | | |__   |", 84, 3, false, true);
	centerText("  |_| |__|__|__|__|_|___|_____|__|__|_____| |_| |_____|_____|_|___|_____|", 84, 4, false, true);
	centerText(solidBottom, 120 - (solidBottom.size() / 2), 0, true, false);
	centerText("Game Title", 70, 7, false, false);
	centerText("Rented on", 92, 7, false, false);
	centerText("Days Rented", 100, 7 ,false,true);
	centerText("Due Date", 139, 7,false,false);
	centerText("Total Price", 159, 7, true,false);
	fstream userLog;
	userLog.open(convertString(fileName));
	if(!userLog.is_open())
	{
		system("cls");
		moveDown = 0;
		centerText(solidTop, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText("YOU HAVE NO EXISTING TRANSACTIONS!", 114, 35, false, true);
		centerText(solidBottom, 0, 0, true, false);			
		Sleep(1000);
	}
	else
	{
		int i = 8;
		while(!userLog.eof())
		{
			userLog >> gameTitle >> gameRentedOn >> gameRentDays >> gameDueDate >> gameTotalPrice;
			centerText (gameTitle, 70, i, true,false);
			centerText (gameRentedOn, 92, i, false,false);
			centerText (gameRentDays, 100, i, false,true);
			centerText (gameDueDate, 139, i, false,false);
			centerText (gameTotalPrice, 163, i, false,false);
			i++;
			
		}
	centerText("Press Any Key to Continue...", 0, 0, true, false);
	cin.ignore();
	cin.get();
	}
}



#endif
