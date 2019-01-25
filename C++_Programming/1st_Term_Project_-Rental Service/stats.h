#ifndef _STATS_
#define _STATS_
#include "main.h"

vector< pair <string,int> > statsList;

bool sortValue(const pair<string, int> &a, const pair<string, int> &b) {
	return (a.second > b.second);
}

void countDuplicates (vector<string> &gameList) {
	vector<int> duplicateCount;
	vector<string> duplicateName;
	int n;
	set<string> gameTitles(gameList.begin(), gameList.end());
	
	for(auto element : gameTitles) {
		duplicateCount.push_back(count(gameList.begin(), gameList.end(), element) );
		duplicateName.push_back(element);
	}

	for (int i = 0; i < duplicateName.size(); i++) {
		statsList.push_back( make_pair(duplicateName[i], duplicateCount[i]) );
	}
}

void statistics()
{
	vector<string> nameList;
	vector<string> gameList;
	string userFullName;
	string gameTitle;
	string convert;
	string rentDate, dueDate;
	int rentDays, price;
	repeat:
	system("cls");
	solidTop.clear();
	solidBottom.clear();
	body.clear();
	moveDown = 0;
	createRectangle(100);
	centerText(solidTop, 120 - (solidTop.size() / 2) , 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(" _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ", 84, 1, false, true);
	centerText("|   __|_   _|  _  |_   _|     |   __|_   _|     |     |   __|", 84, 2, false, true);
	centerText("|__   | | | |     | | | |-   -|__   | | | |-   -|   --|__   |", 84, 3, false, true);
	centerText("|_____| |_| |__|__| |_| |_____|_____| |_| |_____|_____|_____|", 84, 4, false, true);
	centerText(solidBottom, 120 - (solidBottom.size() / 2), 0, true, false);
	fstream stats;
	stats.open("admin/TransactionLog", ios::in);
	if (!stats.is_open()) {
		cout << "There are no transactions\n";
		system("pause");
	} else {
		while (!stats.eof()) {
			stats >> userFullName >> gameTitle >> rentDate >> rentDays >> dueDate >> price;
			nameList.push_back(userFullName);
			gameList.push_back(gameTitle);
		}
		gameList.pop_back();
		countDuplicates(gameList);
	}
	
	sort(statsList.begin(), statsList.end(), sortValue);
	convert = to_string(statsList[0].second);
	centerText("Highest Game Rents: " + statsList[0].first + " with a total of " + convert, 1, 0, true, true);
	convert = to_string(statsList[statsList.size() - 1].second);
	centerText("Lowest Game Rents: " + statsList[statsList.size() - 1].first + " with a total of " + convert, 1, 0, true, true);
	centerText("\n", 0,0,true,true);
	system ("pause");
}


#endif
