#include <cstdlib>
#include <iostream>
#include <stdio_ext.h>

#include "menu.h"
#include "../data/data.h"
#include "../gameplay/check.h"
#include "../gameplay/map_info.h"
#include "../gameplay/modify.h"
#include "../gameplay/move.h"
#include "../gameplay/search.h"
#include "../info/info.h"

using namespace std;

const string ERROR = "Loi: Chuc nang khong ton tai";

void logo() {
//	cout << "__________ ____  __.   ________                       " << endl;
//	cout << "\\______   \\    |/ _|  /  _____/_____    _____   ____  " << endl;
//	cout << " |    |  _/      <   /   \\  ___\\__  \\  /     \\_/ __ \\ " << endl;
//	cout << " |    |   \\    |  \\  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ " << endl;
//	cout << " |______  /____|__ \\  \\______  (____  /__|_|  /\\___  >" << endl;
//	cout << "        \\/        \\/         \\/     \\/      \\/     \\/ " << endl;
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
	__fpurge(stdin);
	char ch = cin.get();

	switch (ch) {
	case '1':
		gameMenu();
		break;

	case '2':
		showInfo();
		break;

	case '0':
		cout << "Ban co chac chan muon thoat? [Y/N] ";
		__fpurge(stdin);
		ch = cin.get();
		if (ch == 'Y' || ch == 'y' || ch == '\n') {
			exit(0);
		} else {
			mainMenu();
		}
		break;

	default:
		cout << ERROR << endl;
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
	__fpurge(stdin);
	char ch = cin.get();

	switch (ch) {
	case '1':
		showMapInfo();
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
		checkValid();
		break;

	case '0':
		mainMenu();
		break;

	default:
		cout << ERROR << endl;
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

	__fpurge(stdin);
	char ch = cin.get();

	switch (ch) {
	case '1':
		editObject();
		break;

	case '2':
		addObject();
		break;

	case '0':
		editMap();
		break;

	default:
		cout << "Loi: Chuc nang khong ton tai." << endl;
		selectEditMapMenu();
	}
}
