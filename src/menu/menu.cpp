#include <cstdlib>
#include <iostream>
#include <stdio_ext.h>

#include "menu.h"
#include "../data/data.h"
#include "../gameplay/map_info.h"
#include "../gameplay/modify.h"
#include "../gameplay/move.h"
#include "../gameplay/search.h"
#include "../info/info.h"

using namespace std;

const string ERROR = "Loi: chuc nang khong ton tai";

void logo() {
	cout << "__________ ____  __.   ________                       " << endl;
	cout << "\\______   \\    |/ _|  /  _____/_____    _____   ____  " << endl;
	cout << " |    |  _/      <   /   \\  ___\\__  \\  /     \\_/ __ \\ " << endl;
	cout << " |    |   \\    |  \\  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ " << endl;
	cout << " |______  /____|__ \\  \\______  (____  /__|_|  /\\___  >" << endl;
	cout << "        \\/        \\/         \\/     \\/      \\/     \\/ " << endl;
	init();
}

void mainMenu() {
	cout << endl;
	cout << "Lua chon chuc nang bang cac so tuong ung" << endl;
	cout << "1 - Choi game		2 - Thong tin		3 - Thoat" << endl;
	chooseMainMenu();
}

void chooseMainMenu() {
	cout << "Menu chinh:$ ";
	__fpurge(stdin);
	char ch = cin.get();

	switch (ch) {
	case '1':
		cout << endl;
		showMapInfo();
		cout << endl;
		gameMenu();
		break;

	case '2':
		showInfo();
		break;

	case '3':
		cout << "Ban co chac chan muon thoat? [Y/N] ";
		__fpurge(stdin);
		ch = cin.get();
		if (ch == 'Y' || ch == 'y') {
			exit(0);
		} else {
			mainMenu();
		}
		break;

	default:
		cout << ERROR << endl;
		chooseMainMenu();
	}
}

void gameMenu() {
	cout << "1 - Di chuyen		2 - Tim duong" << endl;
	cout << "3 - Them map		4 - Sua map" << endl;
	cout << "5 - Quay lai" << endl;
	chooseGameMenu();
}

void chooseGameMenu() {
	cout << "Game menu:$ ";
	__fpurge(stdin);
	char ch = cin.get();

	switch (ch) {
	case '1':
		move();
		break;

	case '2':
		findPath();
		break;

	case '3':
		addMap();
		break;

	case '4':
		editMap();
		break;

	case '5':
		mainMenu();
		break;

	default:
		cout << ERROR << endl;
		chooseGameMenu();
	}
}
