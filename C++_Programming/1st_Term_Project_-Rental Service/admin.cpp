void adminMenu () 
{
	string input;
	solidTop.clear();
	solidBottom.clear();
	body.clear();
	createRectangle(80);
	repeat:
	system("cls");
	moveDown = 0;
	centerText(solidTop, 120 - (solidTop.size() / 2) , 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText(body, 120 - (body.size() / 2), 0, true, false);
	centerText("ADMIN MENU", 116, 2, false, false);
	centerText(solidBottom, 120 - (solidBottom.size() / 2), 0, true, false);	
}

