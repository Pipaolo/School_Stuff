#ifndef _INVENTORY_
#define _INVENTORY_
#include "main.h"

void addGames(){
	string name, quantity, price;
	cout << "----------------------------------------------------" << endl;
	cout << "                      ADMIN MENU" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Enter Game Title: ";
	cin >> name;
	cout << "Number of copies: ";
	cin >> quantity;
	cout << "Price: ";
	cin >> price;
	//Here I initialize the file of the stock list
	//fstream has a default property that makes you
	// read and write the file at the same time
	// The syntax for fstream is. "fstream (nameofvariable)";
	std::fstream stockList;
	//I open the file that is found in the resources directory
	//that is named stock.txt, ios::out and ios::app are functions
	//of fstream, that tells the program to create a file containing
	// the data that the user had entered. The app means that it will add
	// the user input to the end of the file.
	stockList.open("stock.txt", std::ios::out | std::ios::app);
	stockList << name << " " << quantity << " " << price << endl;
	stockList.close();
	//Here I closed the file in order for it to be saved
}

int userCount(int counter){
/*
	This function here is to count how many
	games are being rented at the moment using
	vectors
*/
	int prevCount = 0;
	std::fstream count("userCounter");
	/*
		First I initialized the file, already mentioned
		above. Then I checked if the value of counter is not equal
		to 0, this is just to check whether a game has been
		rented or not
	*/
	if (counter != 0)
	{
		/*
			If someone rents a game
			then the program will check if there is a previous value
			if there is then it will get the value then add to the
			counter after that it will write it to the file.
		*/
		count >> prevCount;
		count.clear();
		count.seekp(0);
		count.tellp();
		int temp = counter + prevCount;
		count << temp;
		count.close();
	} 
	else
	{
		/*
			This is here if the file is not available
			then it will create the file so that it can be
			read and be edited.
		*/
		if (!count.is_open())
		{
			count.open("userCounter", std::ios::out);
			count << counter;
		}
		count >> prevCount;
		count.close();
	}
	return prevCount;
}

#endif
