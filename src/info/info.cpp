#include <iostream>
#include <stdio_ext.h>

#include "info.h"
#include "../menu/menu.h"

using namespace std;

// hien thi thong tin ve tro choi
void showInfo() {
	cout << endl;
	cout << "Thong tin ve tro choi: " << endl;
	cout << "BKGame -- version 1.0" << endl;
	cout << "Cac thanh vien trong nhom: " << endl;
	cout << "	..." << endl;
	cout << "	..." << endl;
	cout << "	..." << endl;
	cout << "	..." << endl;
	cout << "	..." << endl;
	cout << "	..." << endl;
	cout << "	..." << endl;
	cout << "	..." << endl;
	cout << "Copyright (C) 2016 BKTeam. All rights reserved." << endl << endl;

	cout << "Nhan phim [Enter] de quay lai...";
	__fpurge(stdin);
	cin.get();
	mainMenu();
}
