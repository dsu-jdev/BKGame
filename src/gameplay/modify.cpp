#include <iostream>
#include <stdio_ext.h>

#include "modify.h"
#include "../lib/map.h"
#include "../menu/menu.h"

using namespace std;

void addObject(List<Object> *listObj) {
	Object *obj= new Object;
	cout << "Nhap thong tin cac doi tuong them vao ban do ([B] - Quay lai)" << endl;

	cout << "Ma doi tuong: ";
	string objID;
	cin >> objID;
	if (objID == "B" || objID == "b") {
		gameMenu();
	}

	cout << "Ten doi tuong: ";
	cin >> obj->name;

	cout << "Vi tri: ";
	cin >> obj->position;

	cout << "Ti le: ";
	cin >> obj->scale;

	cout << "Goc xoay: ";
	cin >> obj->swivelAngle;

	cout << "Co la doi tuong dac biet khong [Y/N] ";
	char check;
	__fpurge(stdin);
	check = cin.get();
	if (check == 'Y' || check == 'y') {

	}

	addObject(listObj);
}

void addMap() {
	cout << "Nhap ma ban do muon them ([B] - Quay lai): ";
	string mapID;
	cin >> mapID;
	if (mapID == "B" || mapID == "b") {
		gameMenu();
	}
	List<Map> *i = &data;
	while (i != 0x0) {
		if (i->id == mapID) {
			cout << "Loi: Ma ban do da ton tai." << endl;
			addMap();
		}
		i = i->next;
	}



//	List
}

void editMap() {
	cout << "Chuc nang dang duoc xay dung, quay lai sau...";
	__fpurge(stdin);
	cin.get();
	gameMenu();
}
