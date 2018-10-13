#ifndef _SALES_
#define _SALES_
#include "main.h"


// These here is what initializing a vector looks like
// Again, vectors are lists, or containers
// That automagically adjusts to the user input
std::vector<string> gCart;
std::vector<string> gCartGenre;
std::vector<int> gRent;
std::vector<int> gTotalPrice;	

/*
This function here is just to convert the
string to a const char*, because that is the
only data type that the fstream can use.
But this only the case in C++11, in modern
versions you can just using strings as a filename
*/
const char* convertChar(string &name)
{
	const char * convert = name.c_str();
	return convert;
}

void updateStock()
{
	string gGenre, gGenreCheck;
	string gName;
	int gPrice;
	int gStock;

	std::vector<string> nameList;
	std::vector<int> priceList;
	std::vector<int> stockList;

	std::fstream stock;

while (!gCart.empty())
	{
	for (unsigned int i = 0; i < gCartGenre.size(); i++)
		{
			gGenreCheck = gCartGenre[i];
			gGenre = "resources/" + gCartGenre[i];
			stock.open(convertChar(gGenre));
			while(!stock.eof())
			{
				stock >> gName >> gStock >> gPrice;
				nameList.push_back(gName);
				stockList.push_back(gStock);
				priceList.push_back(gPrice);
			}
			stock.clear();
			stock.close();
			for (unsigned int x = 0; x < nameList.size(); x++)
			{
				if (gCart[x] == nameList[x])
				{
					int temp = x;
					cout << temp - x;
					stockList[x - temp] -= 1;
				}
			}
			stock.open(convertChar(gGenre), std::ios::out);
			for (unsigned int i = 0; i < nameList.size() - 1; i++)
			{
				stock << nameList[i] << " " << stockList[i] << " " << priceList[i] << endl;
			}
			/*
				Clear all vectors, so that we can assign new
				values to it in the next loop
			*/
			nameList.clear();
			priceList.clear();
			stockList.clear();
			stock.clear();
			stock.close();
			if (gGenreCheck == gCartGenre[i + 1])
			{
				continue;
			}
			break;
		}
			gCart.erase(gCart.begin());
			gCartGenre.erase(gCartGenre.begin());
			gRent.erase(gRent.begin());
			gTotalPrice.erase(gTotalPrice.begin());
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
		cout << "Your change is: " << payment - totalPrice << endl;
		cout << "Thank you!" << endl;
		system("pause");
	}
}

void rentGame()
{
	string gGenre;
	string gName;
	int gPrice;
	int gStock;
	int inputItem;
	int inputDay;
	int inputGenre;
	std::vector<string> gameList;
	std::vector<string> gameGList;
	std::vector<int> gamePlist;
	std::vector<int> gameSlist;
	std::vector<int> number;
	system("cls");
	cout << "----------------------------------------------------" << endl;
	cout << "                      RENT A GAME!" << endl;
	cout << "----------------------------------------------------" << endl;	
	cout << "Game Genre" << endl;
	std::ifstream stock;
	stock.open("resources/sorter");
	//This function is here to check whether there is a game available or not
	if (!stock.is_open())
	{
		cout << "There are currently no games to rent." << endl;
		system("pause");		
	}
	else
	{
		while(!stock.eof())
		{
			getline(stock,gGenre);
			gameGList.push_back(gGenre);
		}
		stock.close();
	}
	// end of function
	//Print Menu
	for (unsigned int i = 0; i < gameGList.size() - 1; i++)
	{
		number.push_back(i + 1);
		cout << number[i] << ". "<< gameGList[i] << endl;
	}
	//end of print
	//Initialize Checking
	cout << "Enter Game Genre: ";
	cin >> inputGenre;
	for (unsigned int i = 0; i < gameGList.size() - 1; i++)
	{
		if(inputGenre == number[i])
		{
			string fileName = "resources/" + gameGList[i];
			gCartGenre.push_back(gameGList[i]);
			repeat:
			number.clear();
			system("cls");
			cout << "----------------------------------------------------" << endl;
			cout << "                      RENT A GAME!" << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "Game Title        In-Stock        Price" << endl;
			std::fstream stockList;
			stockList.open(convertChar(fileName));
			while(!stockList.eof())
			{
				stockList >> gName >> gStock >> gPrice;
				gameList.push_back(gName);
				gameSlist.push_back(gStock);
				gamePlist.push_back(gPrice);
			}
			stockList.close();
			for (unsigned int i = 0; i < gameList.size() - 1; i++)
			{
				number.push_back(i + 1);
				cout << number[i] << ". " << gameList[i] << "   " << gameSlist[i] << "   " << gamePlist[i] << endl;
			}
			cout << "Enter Desired Game: ";
			cin >> inputItem;
			for (unsigned int i = 0; i < gameList.size(); i++)
			{
				if(inputItem == number[i])
				{
					cout << "You have chosen " << gameList[i] << endl;
					cout << "How many days would you like to Rent it? ";
					cin >> inputDay;
					if (inputDay > 10)
					{
						cout << "You cannot rent a game more than 10 days!" << endl;
						gameList.clear();
						gamePlist.clear();
						gameSlist.clear();
						goto repeat;
					}
					else
					{
						cout << "Item has been added to your Cart!" << endl;
						gCart.push_back(gameList[i]);
						gRent.push_back(inputDay);
						gTotalPrice.push_back(gamePlist[i]);
						system("pause");
					}
				}
			}
		}
	}
}

void showTransactionLog(string &name)
{
	string list;
	string temp = "log/" + name;
	system("cls");
	cout << "----------------------------------------------------" << endl;
	cout << "                      TRANSACTIONS" << endl;
	cout << "----------------------------------------------------" << endl;	
	cout << "GAME TITLE     RENT(IN DAYS)      TOTAL PRICE" << endl;
	std::ifstream log;
	
	log.open(convertChar(temp));
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
	string temp = "log/" + name;
	std::ofstream accHolder;
	std::ofstream adminTransactionLog;
	accHolder.open(convertChar(temp), std::ios::app);
	for (unsigned int i = 0; i < gCart.size(); i++)
	{
		accHolder << gCart[i] << "          " << gRent[i] << "          " << "P" << gTotalPrice[i] << endl;
	}
	accHolder.close();
	adminTransactionLog.open("logs/Transactionlog.txt", std::ios::app);
	for (unsigned int i = 0; i < gCart.size(); i++)
	{
		adminTransactionLog << name << "           " << gCart[i] << "           " << gRent[i] << "           " << "P" << gTotalPrice[i] << endl;
	}		
	gCart.clear();
	gRent.clear();
	gTotalPrice.clear();
	gCartGenre.clear();
}

void showMainTransaction()
{
	system("cls");
	cout << "----------------------------------------------------" << endl;
	cout << "                      ALL TRANSACTIONS" << endl;
	cout << "----------------------------------------------------" << endl;	
	cout << "    Account Name      GAME TITLE     RENT(IN DAYS)      TOTAL PRICE" << endl;
	string list;
	std::ifstream adminTransactionLog("logs/Transactionlog.txt");
	while(!adminTransactionLog.eof())
	{
		getline(adminTransactionLog, list);
		cout << "    " <<  list << endl;
	}
	cout << "----------------------------------------------------" << endl;	
	system("pause");
}


#endif
