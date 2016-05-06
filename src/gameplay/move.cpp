#include <iostream>
#include <stdio_ext.h>

#include "map_info.h"
#include "move.h"
#include "../lib/list.h"
#include "../lib/object.h"
#include "../menu/menu.h"

using namespace std;

/*
 * Chuc nang di chuyen:
 * nguoi choi se di chuyen bang cach nhap vao STT cua doi tuong muon chuyen den
 * sau khi di chuyen se hien thi vi tri hien tai cua nguoi choi
 *
 * neu la doi tuong dac biet thi nguoi choi se duoc chuyen den map moi
 * va in ra tat ca cac doi tuong co trong map moi
 */
void move() {
	cout << endl;
	cout << "Nhap STT tuong ung cac doi tuong de di chuyen ([0] - Quay lai): ";
	int ch;
	cin >> ch;
	if (ch == 0) {
		gameMenu();
	}

	List<Object> *listObj = curMap.data;
	while (listObj->data->_no != ch) {
		if (listObj->next == 0x0) {
			cout << ERROR[3] << endl;
			move();
		}
		listObj = listObj->next;
	}

	Object *go = listObj->data;
	if (go->spclObj == 0x0) {
		curMap.currPos = go->position;
		cout << "Ban vua di chuyen den vi tri: " << curMap.currPos << " (" << go->name << ")" << endl;
		move();
	}

	string mapID = "MAP" + go->spclObj->gotoMap;
	string pos = go->spclObj->positionMap;

	// thay doi du lieu cua map hien tai la map duoc chuyen den
	if (getList(data, mapID) == 0x0) {
		cout << ERROR[1] << endl;
		move();
	}
	curMap = *getList(data, mapID);
	curMap.currPos = pos;

	// hien thi chi tiet cac doi tuong co trong map moi
	showMapInfo();
	move();
}
