#include <cstdlib>
#include <ctype.h>
#include <sstream>
#include <stdio_ext.h>

#include "menu.h"
#include "../data/data.h"
#include "../gameplay/check.h"
#include "../gameplay/map_info.h"
#include "../gameplay/modify.h"
#include "../gameplay/move.h"
#include "../gameplay/search.h"
#include "../info/info.h"

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
	cout << "[1] - Choi game		[2] - Thong tin		[0] - Thoat" << endl;
	selectMainMenu();
}

void selectMainMenu() {
	cout << "Menu chinh:$ ";
	string s;
	cin >> s;
	if (isalpha(s[0])) {
		cout << ERROR[0] << endl;
		selectMainMenu();
	}

	char ch_exit;
	int ch;
	istringstream(s) >> ch;

	switch (ch) {
	case 1:
		gameMenu();
		break;

	case 2:
		showInfo();
		break;

	case 0:
		cout << "Ban co chac chan muon thoat? [Y/N] ";
		__fpurge(stdin);
		ch_exit = cin.get();
		if (ch_exit == 'Y' || ch_exit == 'y' || ch_exit == '\n') {
			exit(0);
		} else {
			mainMenu();
		}
		break;

	default:
		cout << ERROR[0] << endl;
		selectMainMenu();
	}
}

void gameMenu() {
	cout << endl;
	cout << "[1] - Di chuyen		[2] - Tim duong		[3] - Them map" << endl;
	cout << "[4] - Sua map		[5] - Kiem tra file	[0] - Quay lai" << endl;
	selectGameMenu();
}

void selectGameMenu() {
	cout << "Game menu:$ ";
	string s;
	cin >> s;
	if (isalpha(s[0])) {
		cout << ERROR[0] << endl;
		selectMainMenu();
	}

	char ch_exit;
	int ch;
	istringstream(s) >> ch;

	switch (ch) {
	case 1:
		showMapInfo();
		move();
		break;

	case 2:
		findPath();
		break;

	case 3:
		addMap();
		break;

	case 4:
		editMap();
		break;

	case 5:
		checkValid();
		break;

	case 0:
		mainMenu();
		break;

	default:
		cout << ERROR[0] << endl;
		selectGameMenu();
	}
}

void editMapMenu() {
	cout << endl;
	cout << "[1] - Chinh sua cac doi tuong hien co trong map" << endl;
	cout << "[2] - Tao moi cac doi tuong" << endl;
	cout << "[0] - Quay lai" << endl;
	selectEditMapMenu();
}

void selectEditMapMenu() {
	cout << "Menu chinh sua: $ ";
	string s;
	cin >> s;
	if (isalpha(s[0])) {
		cout << ERROR[0] << endl;
		selectMainMenu();
	}

	char ch_exit;
	int ch;
	istringstream(s) >> ch;

	switch (ch) {
	case 1:
		editObject();
		break;

	case 2:
		addObject();
		break;

	case 0:
		editMap();
		break;

	default:
		cout << ERROR[0] << endl;
		selectEditMapMenu();
	}
}
