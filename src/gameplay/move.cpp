#include <iostream>
#include <stdio_ext.h>

#include "move.h"
#include "../menu/menu.h"

using namespace std;

/*
 * di chuyen den vi tri bat ky trong map
 * sau moi lan di chuyen in ra toan bo thong tin cac doi tuong trong map hien tai
 * in ra cac map co the di chuyen den tu map hien tai
 */
void move() {
	cout << "Chuc nang dang duoc xay dung, quay lai sau...";
	__fpurge(stdin);
	cin.get();
	gameMenu();
}

// chuyen den map ma nguoi choi co the di chuyen den tu map hien tai
void gotoMap() {
	cout << "Chuc nang dang duoc xay dung, quay lai sau...";
	__fpurge(stdin);
	cin.get();
	gameMenu();
}
