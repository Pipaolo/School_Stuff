#ifndef _SALES_
#define _SALES_
#include "main.h"


// These here is what initializing a vector looks like
// Again, vectors are lists, or containers
// That automagically adjusts to the user input
std::vector<string> gCart;
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
	string gName;
	int gStock;
	int gPrice;
	/*
	Initialized another set of vectors
	this is only used to show the available
	data inside the stock file located in the
	resources folder
	*/
	std::vector<string> gameList;
	std::vector<int> gamePlist;
	std::vector<int> gameSlist;
	std::fstream stock;
	//Again initializing a fstream function
	stock.open("resources/stock.txt");
	while(!stock.eof()) //This says that if the file is not reached its end then continue running
	{
		stock >> gName >> gStock >> gPrice;
		//push back means you add the value of the said variable to the container
		gameList.push_back(gName);
		gameSlist.push_back(gStock);
		gamePlist.push_back(gPrice);		
	}
	for (unsigned int i = 0; i < gCart.size(); i++)
	{
		// These here is just to print out the available items
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
	stock.open("resources/stock.txt", std::ios::out);
	for (unsigned int i = 0; i < gameList.size() - 1; i++)
	{
		stock << gameList[i] << " " << gameSlist[i] << " " << gamePlist[i] << endl;
	}
}

void payment()
{
	repeat:
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
		goto repeat;
	}
	else
	{
		cout << "Your change is: " << totalPrice - payment << endl;
		cout << "Thank you!" << endl;
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
	cout << "----------------------------------------------------" << endl;
	cout << "                      RENT A GAME!" << endl;
	cout << "----------------------------------------------------" << endl;	
	cout << "Game Title      In-Stock      Price" << endl;
	std::ifstream stockList;
	stockList.open("resources/stock.txt");
	if(!stockList.is_open())
	{
		cout << "There are currently no games to rent." << endl;
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
	string temp = "log/" + name;
	cout << "----------------------------------------------------" << endl;
	cout << "                      TRANSACTIONS" << endl;
	cout << "----------------------------------------------------" << endl;	
	cout << "GAME TITLE     RENT(IN DAYS)      TOTAL PRICE" << endl;
	std::ifstream log;
	
	log.open(convertChar(temp));
	if(!log.is_open())
	{
		cout << "You have no previous transactions." << endl;
	}
	else
	{
		while(!log.eof())
		{
			getline(log,list);
			cout << list << endl;
		}
		cout << "----------------------------------------------------" << endl;	
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
}


#endif
