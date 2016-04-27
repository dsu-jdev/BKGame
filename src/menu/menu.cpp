#include <iostream>
#include <cstdlib>
#include <stdio_ext.h>

#include "menu.h"
#include "../gameplay/move.h"
#include "../gameplay/search.h"
#include "../info/info.h"

using namespace std;

const string ERROR = "Loi: chuc nang khong ton tai";

void title() {
	cout << "__________ ____  __.   ________                       " << endl;
	cout << "\\______   \\    |/ _|  /  _____/_____    _____   ____  " << endl;
	cout << " |    |  _/      <   /   \\  ___\\__  \\  /     \\_/ __ \\ " << endl;
	cout << " |    |   \\    |  \\  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ " << endl;
	cout << " |______  /____|__ \\  \\______  (____  /__|_|  /\\___  >" << endl;
	cout << "        \\/        \\/         \\/     \\/      \\/     \\/ " << endl;

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
	cout << endl;
	// co mot dong hien thi thong tin vi tri hien tai o day... cout << "Vi tri hien tai: ...";
	cout << "1 - Di chuyen		2 - Chuyen den map...		3 - Tim duong		4 - Quay lai" << endl;
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
		gotoMap();
		break;

	case '3':
		findPath();
		break;

	case '4':
		mainMenu();
		break;

	default:
		cout << ERROR << endl;
		chooseGameMenu();
	}
}
