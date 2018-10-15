#ifndef _ADMIN_
#define _ADMIN_
#include "main.h"

class Game
{
	public:
		fstream Log;
		string Name;
		int RentDays;
		int TotalPrice;
		vector<string> NameList;
		vector<string> TitleList;
		vector<int> RentList;
		vector<int> PriceList;
	public:
	string Genre, Title, Price, Stock;	
	void storeGame(string&,string&, string&, string&);
	
	public:
	int sortGame(string &genre)
	{
		string genreDuplicate;
		string fileName = "resources/genreList";
		fstream sortGame;
		sortGame.open(convertString(fileName));
		if (!sortGame.is_open())
		{
			sortGame.open(convertString(fileName), ios::out);
			sortGame << genre << endl;	
		}
		else
		{
			while(!sortGame.eof())
			{
				getline(sortGame, genreDuplicate);
				if (genre == genreDuplicate)
				{
					sortGame.close();
					return 0;
				}
			}
			sortGame.close();
			sortGame.open(convertString(fileName), ios::out | ios::app);
			sortGame << genre << endl;		
		}
	}
};

void Game::storeGame(string &genre, string &title, string &stock, string &price)
{
	string fileName = "resources/";
	fileName += genre;
	fstream gameStock;
	gameStock.open(convertString(fileName), ios::out | ios::app);
	gameStock << title << " " << stock << " " << price << endl;
	gameStock.close();
	sortGame(genre);
}

void adminTransactions ()
{
	system("cls");
	int x = 40, y = 0;
	Game admin;
	admin.Log.open("admin/TransactionLog.txt");
	gotoxy(x, y);
	cout << "------------------------------------------------------\n";
	y += 1;
	gotoxy(x, y);
	cout << "-                    TRANSACTIONS                    -\n";
	y += 1;
	gotoxy(x, y);
	cout << "------------------------------------------------------\n";
	if (!admin.Log.is_open())
	{
		y += 1;
		gotoxy(x, y);
		cout << "There are no exisiting transactions.\n";
		y += 1;
		gotoxy(x, y);
		system("pause");
	}
	else
	{
		y += 1;
		gotoxy(x, y);
		cout << "(Format: FullName, Game Title, Rent in Days, TotalPrice)\n";
		while (!admin.Log.eof())
		{
			getline(admin.Log, admin.Name);
			admin.Log >> admin.Title >> admin.RentDays >> admin.TotalPrice;
			admin.NameList.push_back(admin.Name);
			admin.TitleList.push_back(admin.Title);
			admin.RentList.push_back(admin.RentDays);
			admin.PriceList.push_back(admin.TotalPrice);
		}
		y += 1;
		for (unsigned int i = 0; i < admin.NameList.size() - 1; i++)
		{
			gotoxy(x, y);
			cout << admin.NameList[i] << "    " << admin.TitleList[i] << "    " << admin.RentList[i] << "    " << admin.PriceList[i] << endl;
			y++;
		}
		y += 1;
		gotoxy(x, y);
		system("pause");
	}
		
}

void showRegisteredUsers ()
{
	
}

void addGame ()
{
	Game game;
	system("cls");
	gotoxy(40,10);
	cout << "----------------------------------------" << endl;
	gotoxy(40,11);
	cout << "\t\tADD GAMES" << endl;
	gotoxy(40,12);
	cout << "-----------------------------------------" << endl;	
	gotoxy(40,13);
	cout << "Enter Game Genre: ";	
	cin >> game.Genre;
	gotoxy(40,14);	
	cout << "Enter Game Title: ";	
	cin >> game.Title;
	gotoxy(40,15);
	cout << "How Many" << game.Title << "Would you like to add? ";	
	cin >> game.Stock;
	gotoxy(40,16);
	cout << "Enter Price: ";
	cin >> game.Price;
	game.storeGame(game.Genre, game.Title, game.Stock, game.Price);
}

#endif
