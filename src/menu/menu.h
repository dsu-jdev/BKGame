
#ifndef MENU_MENU_H_
#define MENU_MENU_H_

#include <iostream>

using namespace std;

const string ERROR[] = {
		"ERR-01: Chuc nang khong ton tai",
		"ERR-02: Ma ban do khong ton tai",
		"ERR-03: Ma ban do da ton tai",
		"ERR-04: Doi tuong khong ton tai",
		"ERR-05: Khong the chuyen den chinh no"
};

void logo();
void mainMenu();
void selectMainMenu();

void gameMenu();
void selectGameMenu();

void editMapMenu();
void selectEditMapMenu();

#endif /* MENU_MENU_H_ */
