#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
Initialized this vectors to be global
so that I can manipulate it anywhere,
and before ending a function, I always clear
the vector buffer to avoid errors, and performance
loss.
*/
std::vector<string> itemCart;
std::vector<int> itemCartQuantity;
std::vector<int> itemCartPrice;	

class User
{
	public:
	
	std::vector<string>itemList;
	std::vector<int> itemIndex;
	std::vector<int> priceList;
	std::vector<int> quantityList;
	
	private:	
	
	void itemAdd()
	{
		string itemName;
		int quantity, price;
		cout << "Name of Item: ";
		cin >> itemName;
		cout << "Price: ";
		cin >> price;
		cout << "Quantity: ";
		cin >> quantity;
		std::fstream items;
		items.open("items.txt", std::ios::out | std::ios::app);
		items << itemName << "      " << price << "      " << quantity << endl;
		items.close();
	}
	
	void itemUpdate()
	{
		string item;
		std::ofstream items;
		items.open("items.txt", std::ios::out);
		int index = 0;
		while(index < itemCart.size())
		{
			item = itemCart[index];
			for(unsigned int i = 0; i < itemList.size() - 1; i++)
			/*
			itemList.size - 1 because the spaces caused by the endl function adds 1 to the
			overall size of the file
			*/
			{
				if (item == itemList[i])
				{
					int temp = i;
					quantityList[i] -= itemCartQuantity[temp - i];
				}
			}		
			index++;
		}
		for(unsigned int i = 0; i < itemList.size() - 1; i++)
		/*
			itemList.size - 1 because the spaces caused by the endl function adds 1 to the
			overall size of the file
		*/
		{
			items << itemList[i] << "      " << priceList[i] << "      " << quantityList[i] << endl;
		}	
					items.close();	
	}
	
		
	public:
		
	void adminMenu()
	{
		char input;
		start:
		cout << "--------------------------------------------" << endl;
		cout << "                 ADMIN MENU" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "1. Add Items" << endl;
		cout << "2. Logout" << endl;
		cin >> input;
		switch (input)
		{
			case '1':
				itemAdd();
				goto start;
				break;
			case '2':
				cout << "Logging Out..." << endl;
				break;
		}
	}
		
	void refreshMenu()
	{
		string item;
		int quantity, price;
		std::fstream menu;
		menu.open("items.txt");
		if (!menu.is_open())
		
		{
			menu.open("items.txt", std::ios::out);
		}
		
		while (!menu.eof())
		{
			menu >> item >> price >> quantity;
			itemList.push_back(item);
			quantityList.push_back(quantity);
			priceList.push_back(price);	
		}
		
		for (unsigned int i = 0; i < itemList.size(); i++)
		{
			itemIndex.push_back(i + 1);
		}
	}
	
	void payment()
	{
		string item;
		int totalPrice = 0, cash;
		cout << "-------------------------------------------" << endl;
		cout << "                  PAYMENT" << endl;
		cout << "-------------------------------------------" << endl;
		for (unsigned int i = 0; i < itemCart.size(); i++)	
		{
			cout << itemCart[i] << "     " << itemCartQuantity[i] << "     " << itemCartPrice[i] << endl;
			totalPrice += itemCartPrice[i];
		}
		
		cout << "That would be a total of: " << totalPrice << endl;
		cout << "Enter amount of payment: ";
		cin >> cash;
		if (cash < totalPrice)
		{
			cout << "Insufficient Funds" << endl;
			goto start;
		}
		else
		{
			cout << "Your change is " << cash - totalPrice << endl;
			cout << "Thank you!";
		}
		itemUpdate();
		/*
		After updating the stocks, I clear the vector to 
		set up for another transaction
		*/
		itemCart.clear();
		itemCartQuantity.clear();
		itemCartPrice.clear();

	}

	void cart()
	{
		cout << "----------------------------------------------" << endl;
		cout << "                  CART" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Item         Quantity        Price" << endl;
		
			
		for (unsigned int i = 0; i < itemCart.size(); i++)
		
		{
			cout << itemCart[i] << "   " << itemCartQuantity[i] << "   " << itemCartPrice[i] << endl;
		}
		
	}

	void itemBuy()
	{
		int input, quantityInput, totalPrice = 0;
		std::ifstream items;
		items.open("items.txt");
		cout << "----------------------------------------------" << endl;
		cout << "                  ITEM MENU" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Item Name    Price    InStock" << endl;
		for (unsigned int i = 0; i < itemList.size() - 1; i++)
		{
			cout << itemIndex[i] << "." << itemList[i] << "      " << priceList[i] << "      " << quantityList[i] << endl;
		}
		cout << "Enter what item to buy (e.g 1, 1 = itemNumber)";
		cin >> input;
	
		//initialize item checking
		for (unsigned int index = 0; index < itemList.size(); index++)
		{
			if (input == itemIndex[index])
			{
				cout << itemList[index] << endl;
				cout << "How many? " << endl;
				cin >> quantityInput;
				for (int i = 0; i < quantityInput; i++)
				{
					totalPrice += priceList[index];
				}
				/*
				This parts adds the item to the cart using vectors
				if the item is available.
				*/
				itemCart.push_back(itemList[index]);
				itemCartQuantity.push_back(quantityInput);
				itemCartPrice.push_back(totalPrice);	
			}
		};		
	}		
};

int main() {
	start:
	char input;
	User user;
	if (user.itemList.empty())
	{
		user.refreshMenu();
	}
	
	cout << "<--Welcome to Ctrl-Alt-Elite's Store!-->" << endl;
	cout << "----------------------------------------" << endl;
	cout << "                MAIN MENU" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Total items in cart: " << itemCart.size() << endl;
	cout << "1. Show Cart" << endl;
	cout << "2. Buy Items" << endl;
	if (itemCart.size() != 0)
	{
		cout << "3. Continue to payment" << endl;
	}
	cout << "E. Exit" << endl;
	cout << "Enter desired choice: " << endl;
	cin >> input;
	switch (input)
	{
		case '1':
			user.cart();
			goto start;
			break;
		case '2':
			user.itemBuy();
			goto start;
			break;
		case '3':
			user.payment();
			goto start;
			break;
		case 'E':
			return 0;
			break;
		case 'X':
			case 'x':
				user.adminMenu();
				goto start;
				break;
		default:
			std::cerr << "Invalid option. Please Try Again." << endl;
			goto start;
			break;
	}
}
