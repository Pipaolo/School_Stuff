#ifndef _SALES_
#define _SALES_
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
using std::cin;
using std::string;
using std::cout;
using std::endl;

std::vector<string> gCart;
std::vector<int> gRent;
std::vector<int> gTotalPrice;

const char* convertChar(string &name)
{
	const char * convert = name.c_str();
	return convert;
}

void updateStock()
{
	string gName;
	int gStock;
	int gPrice;
	std::vector<string> gameList;
	std::vector<int> gamePlist;
	std::vector<int> gameSlist;
	std::fstream stock;
	stock.open("stock.txt");
	while(!stock.eof())
	{
		stock >> gName >> gStock >> gPrice;
		gameList.push_back(gName);
		gameSlist.push_back(gStock);
		gamePlist.push_back(gPrice);		
	}
	for (unsigned int i = 0; i < gCart.size(); i++)
	{
		gName = gCart[i];
		for (unsigned int index = 0; index < gameList.size() - 1; index++)
		{
			if (gName == gameList[index])
			{
				gameSlist[i] -= 1;
			}
		}
	}
	stock.close();
	stock.open("stock.txt", std::ios::out);
	for (unsigned int i = 0; i < gameList.size() - 1; i++)
	{
		stock << gameList[i] << " " << gameSlist[i] << " " << gamePlist[i] << endl;
	}
}

void payment()
{
	repeat:
	system("cls");
	int payment, totalPrice = 0;
	cout << "----------------------------------------------------" << endl;
	cout << "                      PAYMENT" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Game Title      Days Rent      Price" << endl;
	for (unsigned int i = 0; i < gCart.size(); i++)
	{
		cout << i + 1 << ". " << gCart[i] << "    " << gRent[i] << "    " << gTotalPrice[i] << endl;
		totalPrice += gTotalPrice[i];
	}
	cout << "Your bill is: P" << totalPrice << endl;
	cout << "Enter payment(Cash Only): ";
	cin >> payment;
	if (payment < totalPrice)
	{
		cout << "Insufficient Funds." << endl;
		system("pause");
		goto repeat;
	}
	else
	{
		cout << "Your change is: " << totalPrice - payment << endl;
		cout << "Thank you!" << endl;
		system("pause");
	}
}

void rentGame(string &name)
{
	string gName;
	int gPrice;
	int gStock;
	int inputItem;
	int inputDay;
	std::vector<string> gameList;
	std::vector<int> gamePlist;
	std::vector<int> gameSlist;
	std::vector<int> number;
	system("cls");
	cout << "----------------------------------------------------" << endl;
	cout << "                      RENT A GAME!" << endl;
	cout << "----------------------------------------------------" << endl;	
	cout << "Game Title      In-Stock      Price" << endl;
	std::ifstream stockList;
	stockList.open("stock.txt");
	if(!stockList.is_open())
	{
		cout << "There are currently no games to rent." << endl;
		system("pause");
	}
	else
	{
		while(!stockList.eof())
		{
			stockList >> gName >> gStock >> gPrice;
			gameList.push_back(gName);
			gameSlist.push_back(gStock);
			gamePlist.push_back(gPrice);
		}
		// Add index numbers to list
		for (unsigned int i = 0; i < gameList.size() - 1; i++)
		{
			number.push_back(i+1);
		}
		//Print item menu
		for(unsigned int i = 0; i < gameList.size() - 1; i++)
		{
			cout << number[i] << ". " << gameList[i] << "   " << gameSlist[i] << "   " << gamePlist[i] << endl;
		}
		cout << "----------------------------------------------------" << endl;	
		cout << "Enter Desired Choice: ";
		cin >> inputItem;
		//initialize input checking
		for (unsigned int i = 0; i < gameList.size(); i++)
		{
			if (inputItem == number[i])
			{
				cout << gameList[i] << endl;
				cout << "How many days? ";
				cin >> inputDay;
				gCart.push_back(gameList[i]);
				gRent.push_back(inputDay);
				gTotalPrice.push_back(gamePlist[i]);
				stockList.close();
			}
		}
	}	
}

void showTransactionLog(string &name)
{
	string list;
	system("cls");
	cout << "----------------------------------------------------" << endl;
	cout << "                      TRANSACTIONS" << endl;
	cout << "----------------------------------------------------" << endl;	
	cout << "GAME TITLE     RENT(IN DAYS)      TOTAL PRICE" << endl;
	std::ifstream log;
	
	log.open(convertChar(name));
	if(!log.is_open())
	{
		cout << "You have no previous transactions." << endl;
		system("pause");
	}
	else
	{
		while(!log.eof())
		{
			getline(log,list);
			cout << list << endl;
		}
		cout << "----------------------------------------------------" << endl;	
		system("pause");
	}

}

void recordTransaction(string &name)
{
	std::ofstream accHolder;
	std::ofstream adminTransactionLog;
	accHolder.open(convertChar(name), std::ios::app);
	for (unsigned int i = 0; i < gCart.size(); i++)
	{
		accHolder << gCart[i] << "          " << gRent[i] << "          " << "P" << gTotalPrice[i] << endl;
	}
	accHolder.close();
	adminTransactionLog.open("Transactionlog.txt", std::ios::app);
	for (unsigned int i = 0; i < gCart.size(); i++)
	{
		adminTransactionLog << name << "           " << gCart[i] << "           " << gRent[i] << "           " << "P" << gTotalPrice[i] << endl;
	}		
	gCart.clear();
	gRent.clear();
	gTotalPrice.clear();
}

void showMainTransaction()
{
	system("cls");
	cout << "----------------------------------------------------" << endl;
	cout << "                      ALL TRANSACTIONS" << endl;
	cout << "----------------------------------------------------" << endl;	
	cout << "    Account Name      GAME TITLE     RENT(IN DAYS)      TOTAL PRICE" << endl;
	string list;
	std::ifstream adminTransactionLog("Transactionlog.txt");
	while(!adminTransactionLog.eof())
	{
		getline(adminTransactionLog, list);
		cout << "    " <<  list << endl;
	}
	cout << "----------------------------------------------------" << endl;	
	system("pause");
}


#endif
