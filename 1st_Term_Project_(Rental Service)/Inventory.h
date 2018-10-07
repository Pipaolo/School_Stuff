#ifndef _Inventory_
#define _Inventory_

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
using std::cin;
using std::string;
using std::cout;
using std::endl;

void addGames(){
	string name, quantity, price;
	system("cls");
	cout << "----------------------------------------------------" << endl;
	cout << "                      ADMIN MENU" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Enter Game Title: ";
	cin >> name;
	cout << "Number of copies: ";
	cin >> quantity;
	cout << "Price: ";
	cin >> price;
	std::fstream stockList;
	stockList.open("stock.txt", std::ios::out | std::ios::app);
	stockList << name << " " << quantity << " " << price << endl;
	stockList.close();
}

void transactionLog(){
	
}

int userCount(int counter){
	int prevCount = 0;
	std::fstream count("userCounter");

	if (counter != 0)
	{
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
