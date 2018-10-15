#ifndef _INVENTORY_
#define _INVENTORY_
#include "main.h"

class Log
{
	public:
		string title;
		int day, price;
		vector<string> titleList;
		vector<int> rentDayList;
		vector<int> totalPriceList;
	public:
		//Used to updating the stock
		int index = 0; 
		vector<string> NameList;
		vector<int>	StockList;
		vector<int> PriceList;
		fstream stock;
};


void updateStock()
{
	string fileName; 
	string gameName;
	int Stock;
	int Price;
	Log game;
	//Read The Existing File Before Writing
	while (!cartGenre.empty())
	{
		fileName = "resources/" + cartGenre[game.index];
		game.stock.open(convertString(fileName));
		while (!game.stock.eof())
		{
			//Start Reading
			game.stock >> gameName >> Stock >> Price;
			game.NameList.push_back(gameName);
			game.StockList.push_back(Stock);
			game.PriceList.push_back(Price);
		}
		game.stock.close();
		for (unsigned int i = 0; i < cartGameTitle.size(); i++)
		{
			gameName = cartGameTitle[i];
			for (unsigned int i = 0; i < game.NameList.size() - 1; i++)
			{
				if ( gameName == game.NameList[i])
				{
					game.StockList[i] -= 1;
					break;
				}				
			}
		}
		game.stock.open(convertString(fileName), ios::out);
		for (unsigned int i = 0; i < game.NameList.size() - 1; i++)
		{
			game.stock << game.NameList[i] << "    " << game.StockList[i] << "    " << game.PriceList[i] << endl;
		}
		game.stock.close();
		game.NameList.clear();
		game.StockList.clear();
		game.PriceList.clear();
		cartGenre.erase(cartGenre.begin());
	}
	cartGenre.clear();
	cartGameTitle.clear();
	cartGameDays.clear();
	cartTotalPrice;
}

void RecordTransaction(string &name, string &gameTitle, int &rentalDays, int &totalPrice)
{
	string fileName = "log/" + name;
	fstream userLog;
	fstream	adminLog;
	userLog.open(convertString(fileName), ios::out | ios::app);
	userLog << gameTitle << "  " << rentalDays << "   " << totalPrice << endl;
	userLog.close();
	//Record the logs in the admin folder
	adminLog.open("admin/TransactionLog.txt", ios::out | ios::app);
	adminLog << name << endl << gameTitle << "  " << rentalDays << "   " << totalPrice << endl;
	adminLog.close();
}

void userTransactions (string& name)
{
	system("cls");
	int x = 40, y = 0;		
	Log game;
	string fileName = "log/" + name;
	fstream userLog;
	userLog.open(convertString(fileName));
	gotoxy(x, y);
	cout << "------------------------------------------------------\n";
	y += 1;
	gotoxy(x, y);
	cout << "-                    TRANSACTIONS                    -\n";
	y += 1;
	gotoxy(x, y);
	cout << "------------------------------------------------------\n";
	if(!userLog.is_open())
	{
		y += 1;
		gotoxy(x, y);
		cout << "You have no past transactions!\n";
		y += 1;
		gotoxy(x, y);
		system("pause");
	}
	else
	{
		while (!userLog.eof())
		{
			userLog >> game.title >> game.day >> game.price;
			game.titleList.push_back(game.title);
			game.rentDayList.push_back(game.day);
			game.totalPriceList.push_back(game.price);
		}
		y += 1;
		gotoxy(x, y);
		cout << "(Format: GameTitle, Rent in Days, Total Price)\n";
		//print Transactions
		y += 1;
		for (unsigned int i = 0; i < game.titleList.size() - 1; i++)
		{
			gotoxy(x, y);
			cout << game.titleList[i] << "   " << game.rentDayList[i] << "   " << game.totalPriceList[i] << endl;
			y++;
		}
		y += 1;
		gotoxy(x, y);
		system("pause");
	}

}	

#endif
