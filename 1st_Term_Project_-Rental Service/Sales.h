#ifndef _SALES_
#define _SALES_
#include "main.h"

struct Sales
{
	vector<string> tempList;
	vector<string> TList;
	vector<string> GList;
	vector<int> SList;
	vector<int> Plist;
	vector<int> index;
	string Title, Genre;
	string fileName = "resources/";
	int Price, Stock;
};

void payment(string &name)
{
	repeat:
	int cashPayment, totalPrice;
	int x = 40, y = 0;
	string menu[4] = {"------------------------------------------\n", "-                PAYMENT                 -\n", "------------------------------------------\n", 
	"Game Title     Days to be Rented     Price\n"};
	system("cls");
	for (int i = 0; i < 4; i++)
	{
		gotoxy(x, y);
		cout << menu[i];
		y++;
	}
	for (unsigned int i = 0; i < cartGameTitle.size(); i++)
	{
		gotoxy(x, y);
		cout << cartGameTitle[i] << "      " << cartGameDays[i] << "      " << cartTotalPrice[i] << endl;
		totalPrice += cartTotalPrice[i];
		y++;
	}
	y += 1;
	gotoxy(x, y);
	cout << "Your bill is: P" << totalPrice << endl;
	y += 1;
	gotoxy(x, y);
	cout << "Enter Payment(Cash Only): ";
	y += 1;
	gotoxy(x, y);
	cin >> cashPayment;
	if (cashPayment < totalPrice)
	{
		system("cls");
		y = 0;
		gotoxy(x, 10);
		cout << "Insufficient Funds";
		goto repeat;
	}
	else
	{
		y += 1;
		gotoxy(x, y);
		cout << "Your Change is P" << cashPayment - totalPrice << endl;
		y += 1;
		gotoxy(x, y);
		system("pause");
		//Records the transactions of the user
		for (unsigned int i = 0; i < cartGameTitle.size(); i++)
		{
			RecordTransaction(name, cartGameTitle[i], cartGameDays[i], cartTotalPrice[i]);			
		}
	}
}

void rentGame ()
{
	Sales game;
	int inputGenre, inputGame, inputDays;
	int y;
	system("cls");
	gotoxy(40,0);
	cout << "----------------------------------------\n";
	gotoxy(40,1);
	cout << "-              RENT A GAME             -\n";
	gotoxy(40,2);
	cout << "----------------------------------------\n";
	fstream stock;
	stock.open("resources/genreList");
	while(!stock.eof())
	{
		stock >> game.Genre;
		game.GList.push_back(game.Genre);	
	} 
	stock.close();
	//Print Menu
	y = 3;
	for (unsigned int i = 0; i < game.GList.size() - 1; i++)
	{
		gotoxy (40, y);
		game.index.push_back(i + 1);
		cout << game.index[i] << ". " << game.GList[i] << endl;
		y++;
	}
	gotoxy(40,y + 1);
	cout << "Enter Desired Choice: ";
	cin >> inputGenre;
	for (unsigned int i = 0; i < game.GList.size() - 1; i++)
	{
		if (inputGenre == game.index[i])
		{
			if (cartGenre.empty())
			{
				cartGenre.push_back(game.GList[i]);					
			}
			else
			{	game.tempList.push_back(game.GList[i]);
				for (unsigned int i = 0; i < cartGenre.size(); i++)
				{
					if (game.tempList[i] == cartGenre[i])
					{
						break;
					}
					else
					{
						cartGenre.push_back(game.tempList[i]);
						break;
					}
				}					
			}
			// end check
			system("cls");
			game.index.clear();
			gotoxy(40,0);
			cout << "----------------------------------------\n";
			gotoxy(40,1);
			cout << "-              RENT A GAME             -\n";
			gotoxy(40,2);
			cout << "----------------------------------------\n";
			game.fileName += game.GList[i];
			fstream stock;
			stock.open(convertString(game.fileName));
			if (!stock.is_open())
			{
				gotoxy(40,3);
				cout << "FILE NOT FOUND" << endl;
				system("pause");
			}
			else
			{
				while (!stock.eof())
				{
					stock >> game.Title >> game.Stock >> game.Price;
					game.TList.push_back(game.Title);
					game.SList.push_back(game.Stock);
					game.Plist.push_back(game.Price);
				}				
			}
			stock.close();
			y = 3;
			for (unsigned int i = 0; i < game.TList.size() - 1; i++)
			{	
				gotoxy(40,y);
				game.index.push_back(i + 1);
				cout << game.index[i] << ". " << game.TList[i] << " " << game.SList[i] << " " << game.Plist[i] << endl;	
				y++;
			}
			gotoxy(40, y + 1);
			cout << "Enter Desired Choice: ";
			cin >> inputGame;
			for (unsigned int i = 0; i < game.TList.size() - 1; i++)
			{
				if(inputGame == game.index[i])
				{
					y += 1;
					gotoxy(40, y);
					cout << "How many days would you like to rent " <<  game.TList[i] << "? " << endl;
					y += 1;
					gotoxy(40, y);
					cin >> inputDays;
					y += 1;
					gotoxy(40, y);
					cout << "Item has been added to your cart!" << endl;
					y += 1;
					gotoxy(40, y);
					system("pause");
					cartGameTitle.push_back(game.TList[i]);
					cartTotalPrice.push_back(game.Plist[i]);
					cartGameDays.push_back(inputDays);
				}
			}
		}
	}	
}

#endif
