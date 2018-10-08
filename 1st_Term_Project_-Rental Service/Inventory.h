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

void createDirectory()
{
	system("mkdir resources");
	system("mkdir users");
	system("mkdir log");
}

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
	stockList.open("resources/stock.txt", std::ios::out | std::ios::app);
	stockList << name << " " << quantity << " " << price << endl;
	stockList.close();
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
