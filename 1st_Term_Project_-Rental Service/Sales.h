#ifndef _SALES_
#define _SALES_
#include "main.h"
#include "inventory.h"

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
	
	//This variables are for logging
		string title;
		int day, price;
		vector<string> titleList;
		vector<int> rentDayList;
		vector<int> totalPriceList;
		
	//Used to updating the stock
		int iterate = 0; 
		vector<string> NameList;
		vector<int>	StockList;
		vector<int> PriceList;	
};

void recordTransaction(string &accHolder, string &gameTitle, int &gameDays, int &gamePrice)
{
	//Remove Spaces in AccHolder
	accHolder.erase(remove(accHolder.begin(), accHolder.end(), ' '), accHolder.end());
	//Initialize Windows systemTime
	SYSTEMTIME localTime;
	GetLocalTime(&localTime);
	//Convert numbers to string in order to save and concatenate
	string i_Month = to_string(localTime.wMonth);
	string i_Day = to_string(localTime.wDay);
	string i_Year = to_string(localTime.wYear);
	//This here is for getting the due date of the rented game
	int d_Month = localTime.wMonth;
	int d_Day = localTime.wDay;
	if (d_Month == 1 || d_Month == 3 || d_Month == 5 || d_Month == 7 || d_Month == 8 || d_Month == 10 || d_Month == 12 && d_Day + gameDays > 31)
	{
		d_Month += 1;
		d_Day -= 31;	
	}else if (d_Month == 4 || d_Month == 6 || d_Month == 9 || d_Month == 11 && d_Day + gameDays > 30)
	{
		d_Month += 1;
		d_Day -= 30;
	}else if (d_Month == 2 && d_Day + gameDays > 28)
	{
		d_Month += 1;
		d_Day -= 28;
	}else {
		d_Day += gameDays;
	}
	string f_Month = to_string(d_Month);
	string f_Day = to_string(d_Day);
	// End of getting local time
	string fileName = "log/" + accHolder;
	fstream userTransaction;
	userTransaction.open(convertString(fileName));
	if (!userTransaction.is_open())
	{
		userTransaction.open(convertString(fileName), ios::out);
		userTransaction << gameTitle << " " << i_Month + "/" << i_Day + "/" << i_Year << " " << gameDays << " " 
		<< f_Month + "/" << f_Day + "/" << i_Year << " " << gamePrice;
		userTransaction.close();
	}
	else
	{
		userTransaction.close();
		userTransaction.open(convertString(fileName), ios::out | ios::app);
		userTransaction << endl << gameTitle << " " << i_Month + "/" << i_Day + "/" << i_Year << " " << gameDays << " " 
		<< f_Month + "/" << f_Day + "/" << i_Year << " " << gamePrice;
		userTransaction.close();
	}
	// End of user transaction
	// Initialize Admin Records	
	fstream adminTransactions;
	adminTransactions.open("admin/TransactionLog");
	if(!adminTransactions.is_open())
	{
		adminTransactions.open("admin/TransactionLog", ios::out);
		adminTransactions << accHolder << endl << gameTitle << " " << i_Month + "/" << i_Day + "/" << i_Year << " " << gameDays << " " 
		<< f_Month + "/" << f_Day + "/" << i_Year << " " << gamePrice;
		adminTransactions.close();	
	}
	else
	{
		adminTransactions.close();
		adminTransactions.open("admin/TransactionLog", ios::out | ios::app);
		adminTransactions << endl << accHolder << " " << gameTitle << " " << i_Month + "/" << i_Day + "/" << i_Year << " " << gameDays << " " 
		<< f_Month + "/" << f_Day + "/" << i_Year << " " << gamePrice;		
		adminTransactions.close();
	}
}

void updateStock()
{
	Sales Log;
	string fileName;
	string gameName;
	int Stock = 0;
	int Price = 0;
	
	//Read The Existing File Before Writing
	fstream stockData;
	while(!cartGenre.empty())
	{
		fileName = "resources/" + cartGenre[Log.iterate];
		stockData.open(convertString(fileName));
		while(!stockData.eof())
		{
			//Initialize File Reading
			stockData >> gameName >> Stock >> Price;
			Log.NameList.push_back(gameName);
			Log.StockList.push_back(Stock);
			Log.PriceList.push_back(Price);
		}
		stockData.close();
		for(unsigned int i = 0; i < cartGameTitle.size(); i++)
		{
			gameName = cartGameTitle[i];
			for (unsigned int i = 0; i < Log.NameList.size(); i++)
			{
				if (gameName == Log.NameList[i])
				{
					Log.StockList[i] -= 1;
					break;
				}
			}
		}
		stockData.open(convertString(fileName), ios::out);
		for(unsigned int i = 0; i < Log.NameList.size(); i++)
		{
			if (i == 0)
			{
				stockData << Log.NameList[i] << " " << Log.StockList[i] << " " << Log.PriceList[i];
			}
			else
			{
				stockData << endl << Log.NameList[i] << " " << Log.StockList[i] << " " << Log.PriceList[i];				
			}
		}
		stockData.close();
		Log.NameList.clear();
		Log.StockList.clear();
		Log.PriceList.clear();
		cartGenre.erase(cartGenre.begin());		
	}
	cartGenre.clear();
	cartGameTitle.clear();
	cartGameDays.clear();
	cartPrice.clear();		
}

void checkOut(string &name)
{
	Sales log;
	repeat:
	int totalPrice = 0, cashPayment, change;
	string convertDays;
	string convertPrice;
	string convertTotalPrice;
	system("cls");
	solidTop.clear();
	solidBottom.clear();
	body.clear();
	moveDown = 0;
	createRectangle(80);
	centerText(solidTop, 0, 0, true, true);
	centerText(body,0,0,true, true);
	centerText(body,0,0,true, true);
	centerText(body,0,0,true, true);
	centerText(body,0,0,true, true);
	centerText(body,0,0,true, true);
	centerText(" _____ _____ _____ _____ _____    _____ _____ _____ ", 94, 1, false, false);
	centerText("|     |  |  |   __|     |  |  |  |     |  |  |_   _|", 94, 2, false, false);
	centerText("|   --|     |   __|   --|    -|  |  |  |  |  | | |  ", 94, 3, false, false);
	centerText("|_____|__|__|_____|_____|__|__|  |_____|_____| |_|  ", 94, 4, false, false);
	centerText(solidBottom, 0,0,true, true);
	centerText("Game Title", 80, 7, false,false);
	centerText("Days to be Rented", 0 , 0, true,true);
	centerText("Price", 155, 7, false,false);
	//print cart
	for (unsigned int i = 0; i < cartGameTitle.size(); i++)
	{
		totalPrice += cartPrice[i];
		convertDays = to_string(cartGameDays[i]);
		convertPrice = to_string(cartPrice[i]);
		// This is for logging transactions
		log.NameList.push_back(cartGameTitle[i]);
		log.rentDayList.push_back(cartGameDays[i]);
		log.PriceList.push_back(cartPrice[i]);
		// end of logging
		centerText(cartGameTitle[i], 80, 8 + i, false, false);
		centerText(convertDays, 0,0, true,true);
		centerText("P" + convertPrice, 155, 8 + i, false,false);
	}
	centerText("\n",0,0,true, true);
	convertTotalPrice = to_string(totalPrice);
	centerText("Your Bill is: P" + convertTotalPrice, 80, 0, true, false);
	centerText("Enter Payment(Cash Only): P", 80,0,true,false);
	cin >> cashPayment;
	if (cashPayment < totalPrice)
	{
		centerText("Insufficient Funds", 80,0,true,false);
		goto repeat;
	}
	else
	{
		change = cashPayment - totalPrice;
		convertTotalPrice = to_string(change);
		centerText("Your Change is P" + convertTotalPrice, 80, 0, true,false);
	}
	// Initialize Logging
	for (unsigned int i = 0; i < log.NameList.size(); i++)
	{
		recordTransaction(name, log.NameList[i], log.rentDayList[i], log.PriceList[i]);
	}
	// end of logging
}

void rentGame()
{
	Sales game;
	int inputGenre, inputGameTitle, inputDays;
	string convertIndex;
	string convertStock;
	string convertPrice;
	repeat:
	system("cls");
	solidTop.clear();
	solidBottom.clear();
	body.clear();
	moveDown = 0;
	createRectangle(80);
	centerText(solidTop, 0, 0, true, true);
	centerText(body,0,0,true, true);
	centerText(body,0,0,true, true);
	centerText(body,0,0,true, true);
	centerText(body,0,0,true, true);
	centerText(body,0,0,true, true);
	centerText(body,0,0,true, true);
	centerText("                                                                __ ", 86, 1, false, true);
	centerText(" _____ _____ _____ _____    _____    _____ _____ _____ _____   |  |", 86, 2, false, true);
	centerText("| __  |   __|   | |_   _|  |  _  |  |   __|  _  |     |   __|  |  |", 86, 3, false, true);
	centerText("|    -|   __| | | | | |    |     |  |  |  |     | | | |   __|  |__|", 86, 4, false, true);
	centerText("|__|__|_____|_|___| |_|    |__|__|  |_____|__|__|_|_|_|_____|  |__|", 86, 5, false, true);
	centerText(solidBottom, 0,0,true, true);
	centerText("Game Genre/s Available: ", 0, 0, true, true);
	//initialize read genreList;
	fstream stockData;
	stockData.open("resources/genreList");
	if(!stockData.is_open())
	{
		centerText("There are no available items at the moment.", 0,0 ,true ,false);
	}
	else
	{
		while(!stockData.eof())
		{
			stockData >> game.Genre;
			game.GList.push_back(game.Genre);
		}
		stockData.close();
	}
	//end of read
	//start printing the menu
	centerText("\n", 0, 0, true, true); // This is just a space lol
	for (unsigned int i = 0; i < game.GList.size(); i++)
	{
		game.index.push_back(i + 1);
		convertIndex = to_string(game.index[i]);
		centerText("[" + convertIndex + "] " + game.GList[i], 104, 0, true, false);
	}
	centerText("Enter Desired Genre: ", 104, 0, true, false);
	cin >> inputGenre;
	// check if index is available
	for (unsigned int i = 0; i < game.GList.size(); i++)
	{
		if(inputGenre == game.index[i])
		{
			if(cartGenre.empty())
			{
				cartGenre.push_back(game.GList[i]);
			}
			else
			{
				game.tempList.push_back(game.GList[i]);
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
			// end of checking
			system("cls");
			game.index.clear();
			moveDown = 0;
			centerText(solidTop, 0, 0, true, true);
			centerText(body,0,0,true, true);
			centerText(body,0,0,true, true);
			centerText(body,0,0,true, true);
			centerText(body,0,0,true, true);
			centerText(body,0,0,true, true);
			centerText(body,0,0,true, true);
			centerText("                                                                __ ", 86, 1, false, false);
			centerText(" _____ _____ _____ _____    _____    _____ _____ _____ _____   |  |", 86, 2, false, false);
			centerText("| __  |   __|   | |_   _|  |  _  |  |   __|  _  |     |   __|  |  |", 86, 3, false, false);
			centerText("|    -|   __| | | | | |    |     |  |  |  |     | | | |   __|  |__|", 86, 4, false, false);
			centerText("|__|__|_____|_|___| |_|    |__|__|  |_____|__|__|_|_|_|_____|  |__|", 86, 5, false, false);
			centerText(solidBottom, 0,0,true, true);
			centerText("Games Available: ", 0, 0, true, true);	
			centerText("Title", 80, 9, false, false);
			centerText("In Stock", 0 ,0, true, true);
			centerText("Price", 155 , 9, false, false);
			game.fileName += game.GList[i];
			fstream stockData;
			stockData.open(convertString(game.fileName));
			while(!stockData.eof())
			{
				stockData >> game.Title >> game.Stock >> game.Price;
				game.TList.push_back(game.Title);
				game.SList.push_back(game.Stock);
				game.Plist.push_back(game.Price);
			}
			stockData.close();
			//print menu
			for(unsigned int i = 0; i < game.TList.size(); i++)
			{
				game.index.push_back(i + 1);
				convertIndex = to_string(game.index[i]);
				convertStock = to_string(game.SList[i]);
				convertPrice = to_string(game.Plist[i]);
				centerText("[" + convertIndex + "]" + game.TList[i],80, 10 + i, false, false);
				centerText(convertStock, 0, 10 + i, true, true);
				centerText("P" + convertPrice, 154,10 + i, false,false);		
			}
			centerText("\n", 0, 0, true, false);
			centerText("Enter Game of Choice: ", 80, 0, true, false);
			cin >> inputGameTitle;
			//initialize checking
			for(unsigned int i = 0; i < game.TList.size(); i++)
			{
				if(inputGameTitle == game.index[i])
				{
					centerText("How many days would you like to rent " + game.TList[i] + "? ", 80,0,true,false);
					cin >> inputDays;
					if (inputDays > 10)
					{
						system("cls");
						moveDown = 0;
						centerText(solidTop, 0, 0, true, false);
						centerText(body, 0, 0, true, false);
						centerText(body, 0, 0, true, false);
						centerText(body, 0, 0, true, false);
						centerText("You cannot rent a game longer than 10 days!", 100, 35, false, false);
						centerText(solidBottom, 0, 0, true, false);			
						Sleep(1000);
						goto repeat;						
					}
					moveDown = 0;
					centerText("Item has been added to your cart!", 0 ,0,true,false);
					cartGameTitle.push_back(game.TList[i]);
					cartPrice.push_back(game.Plist[i]);
					cartGameDays.push_back(inputDays);
					centerText("Press Any Key To Continue...", 0,0,true,false);
					if (cin.peek())
					{
						cin.ignore();
					}
					cin.get();
					break;
				}
			}
		}
	}	
}



void salesMenu (string &accHolder) 
{
	static int cartCounter = 0;
	string input;
	string convertCounter;
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
	centerText("MAIN MENU", 116, 2, false, false);
	centerText(solidBottom, 120 - (solidBottom.size() / 2), 0, true, false);
	centerText("Hi " + accHolder + "!", 0, 5, true, true);
	convertCounter = to_string(cartCounter);
	centerText("Cart: " + convertCounter, 152, 5, true, false);
	centerText("[1] Rent a Game", 107, 0, true, false);
	centerText("[2] Show Transactions", 107, 0, true, false);
	centerText("[3] Change Password", 107, 0, true, false);
	if(cartCounter != 0)
	centerText("[4] Checkout", 107, 0, true, false);
	centerText("[5] Logout", 107, 0, true, false);
	centerText("What would you like to do? ", 107, 0, true, false);
	cin >> input;
	if (input == "1") {
		rentGame();
		cartCounter += 1;
		goto repeat;
	} else if (input == "2") {
		showUserTransaction(accHolder);
		goto repeat;
	} else if (input == "3") {
		changePassword();
		goto repeat;
	} else if (input == "4") {
		checkOut(accHolder);
		updateStock();
		cartCounter = 0;
		goto repeat;
	} else if (input == "5") {
		
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

#endif
