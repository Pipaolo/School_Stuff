#ifndef _ADMIN_
#define _ADMIN_
#include "main.h"
#include "stats.h"

struct Admin
{
	fstream Log; // For reading and writing the transaction logs
	string Name;
	int RentDays;
	int TotalPrice;
	vector<string> NameList;
	vector<string> TitleList;
	vector<int> RentList;
	vector<int> PriceList;
	string Genre,Title,Price,Stock;
	
	void storeGame(string &genre, string &title, string &stock, string &price) 
	{
		string fileName = "resources/" + genre;
		fstream gameStock;
		//Check if file empty
		gameStock.open(convertString(fileName));
		if (!gameStock.is_open())
		{
			gameStock.open(convertString(fileName), ios::out);
			gameStock << title << " " << stock << " " << price;
			gameStock.close();
			genreSort(genre);			
		}
		else
		{
			gameStock.close();
			gameStock.open(convertString(fileName), ios::out | ios::app);
			gameStock << endl << title << " " << stock << " " << price;
			gameStock.close();		
			genreSort(genre);
		}
	}
	
	int genreSort(string &genre)
	{
		string genreDuplicate;
		fstream sortGenre;
		sortGenre.open("resources/genreList");
		if (!sortGenre.is_open())
		{
			sortGenre.open("resources/genreList", ios::out);
			sortGenre << genre;
			sortGenre.close();
		}
		else
		{
			while(!sortGenre.eof())
			{
				getline(sortGenre,genreDuplicate);
				if (genre == genreDuplicate)
				{
					sortGenre.close();
					return 0;
				}
			}
			sortGenre.open("resources/genreList", ios::out | ios::app);
			sortGenre << endl << genre;
			sortGenre.close();
		}
	}	
};

int main();

void addGame() 
{
	Admin game;
	system("cls");
	moveDown = 0;
	centerText(solidTop, 120 - (solidTop.size() / 2) , 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText("ADD GAMES", 115, 2, false, false);
	centerText(solidBottom, 120 - (solidBottom.size() / 2), 0, true, false);
	centerText("Enter Game Genre: ", 80, 0, true, false);
	cin >> game.Genre;
	centerText("Enter Game Title: ", 80, 0, true, false);
	cin >> game.Title;
	centerText("Quantity: ", 80, 0, true, false);
	cin >> game.Stock;
	centerText("Enter Game Price: ", 80, 0, true, false);
	cin >> game.Price;
	game.storeGame(game.Genre, game.Title, game.Stock, game.Price);
}

void showUsers() 
{
	string FullName;
	repeat:
	system("cls");
	solidTop.clear();
	solidBottom.clear();
	body.clear();
	moveDown = 0;
	createRectangle(80);
	centerText(solidTop, 120 - (solidTop.size() / 2) , 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(" _____ _____ _____ _____ _____ ", 105, 1, false, true);
	centerText("|  |  |   __|   __| __  |   __|", 105, 2, false, true);
	centerText("|  |  |__   |   __|    -|__   |", 105, 3, false, true);
	centerText("|_____|_____|_____|__|__|_____|", 105, 4, false, true);
	centerText(solidBottom, 120 - (solidBottom.size() / 2), 0, true, false);	// wag muna to di naman masyadong need
	fstream userData;
	userData.open("admin/userList");
	if(!userData.is_open())
	{
		system("cls");
		moveDown = 0;
		centerText(solidTop, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText("THERE NO REGISTERED USERS!", 114, 35, false, true);
		centerText(solidBottom, 0, 0, true, false);			
		Sleep(1000);		
	}
	else
	{
		while(!userData.eof())
		{
			getline(userData, FullName);
			centerText(FullName, 0 , 0, true,true); 	
		}
			}
	centerText("Press Any Key to Continue...", 0, 0, true, false);
	cin.ignore();
	cin.get();
}

void showAllTransactions() 
{
	string gameTitle;
	string gameRentDays;
	string gameRentedOn;
	string gameDueDate;
	string gameTotalPrice;
	string accName;
	string fileName = "admin/TransactionLog";
	repeat:
	system("cls");
	solidTop.clear();
	solidBottom.clear();
	body.clear();
	moveDown = 0;
	createRectangle(200);
	centerText(solidTop, 120 - (solidTop.size() / 2) , 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(" _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ", 84, 1, false, false);
	centerText("|_   _| __  |  _  |   | |   __|  _  |     |_   _|     |     |   | |   __|", 84, 2, false, false);
	centerText("  | | |    -|     | | | |__   |     |   --| | | |-   -|  |  | | | |__   |", 84, 3, false, false);
	centerText("  |_| |__|__|__|__|_|___|_____|__|__|_____| |_| |_____|_____|_|___|_____|", 84, 4, false, false);
	centerText(solidBottom, 120 - (solidBottom.size() / 2), 0, true, false);
	centerText("Full Name",45 , 7, false,false);
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
			
			userLog >> accName >> gameTitle >> gameRentedOn >> gameRentDays >> gameDueDate >> gameTotalPrice;
			centerText (accName, 45, i, true,false);
			centerText (gameTitle, 70, i, false,false);
			centerText (gameRentedOn, 92, i, false,false);
			centerText (gameRentDays, 100, i, false,true);
			centerText (gameDueDate, 139, i, false,false);
			centerText (gameTotalPrice, 163, i, false,false);
			i++;
		}
	}
	centerText("Press Any Key to Continue...", 0, 0, true, false);
	cin.ignore();
	cin.get();
}

void adminMenu () 
{
	string input;
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
	centerText("ADMIN MENU", 116, 2, false, false);
	centerText(solidBottom, 120 - (solidBottom.size() / 2), 0, true, false);
	centerText("[1] ADD GAME", 80, 0, true, false);
	centerText("[2] SHOW REGISTERED USERS", 80, 0, true, false);
	centerText("[3] SHOW OVERALL TRANSACTIONS", 80, 0, true, false);
	centerText("[4] STATISTICS", 80, 0, true, false);
	centerText("[5] RETURN TO LOGIN MENU", 80, 0, true, false);
	centerText("[6] EXIT", 80, 0, true, false);
	centerText(">> ", 80, 0, true, false);
	cin >> input;
	if (input == "1")
	{
		addGame();
		goto repeat;
	} else if (input == "2") {
		showUsers();
		goto repeat;
	} else if (input == "3") {
		showAllTransactions();
		goto repeat;
	} else if (input == "4") {
		statistics();
		goto repeat;
	} else if (input == "5") {
		main();
	} else if (input == "6") {
		exit(0);
	} else {
		system("cls");
		moveDown = 0;
		centerText(solidTop, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText(body, 0, 0, true, false);
		centerText("INVALID INPUT!!", 114, 35, false, true);
		centerText(solidBottom, 0, 0, true, false);			
		Sleep(1000);
		goto repeat;
	}
	
}
#endif
