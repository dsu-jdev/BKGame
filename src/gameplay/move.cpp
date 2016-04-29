#include <iostream>

#include "map_info.h"
#include "move.h"
#include "../lib/list.h"
#include "../lib/object.h"
#include "../menu/menu.h"

using namespace std;

void move() {
	int ch;
	cout << "Nhap STT tuong ung cac doi tuong de di chuyen ([0] - Quay lai): ";
	cin >> ch;
	if (ch == 0) {
		gameMenu();
	}

	List<Object> *listObj = currMap.data;
	while (listObj->data->_no != ch) {
		if (listObj->next == 0x0) {
			cout << "Loi: Doi tuong khong ton tai." << endl;
			move();
		}
		listObj = listObj->next;
	}

	Object *go = listObj->data;
	if (go->spclObj == 0x0) {
		currMap.currPos = go->position;
		cout << "Ban vua di chuyen den vi tri: " << currMap.currPos << endl;
		move();
	}

	string mapID = "MAP" + go->spclObj->gotoMap;
	string pos = go->spclObj->positionMap;

	currMap = *getList(&data, mapID);
	currMap.currPos = pos;

	showMapInfo();
	move();
}
