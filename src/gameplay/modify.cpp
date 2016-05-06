#include <iostream>
#include <stdio_ext.h>

#include "modify.h"
#include "map_info.h"
#include "../lib/map.h"
#include "../menu/menu.h"

using namespace std;

Map<List<Object> > *map;
List<Object> *listObj;
string mapID;

/*
 * Them cac doi tuong vao map da duoc xac dinh
 *
 * Neu doi tuong moi them vao la doi tuong dac biet
 * thi phai them mot doi tuong moi (cung phai la doi tuong dac biet) vao map duoc chuyen den
 * de dam bao 2 map co the di lai duoc voi nhau
 *
 * Qua trinh them cac doi tuong ket thuc khi nguoi choi nhan phim [0] se quay lai menu
 */
void addObject() {
	cout << endl;
	cout << "Nhap thong tin cac doi tuong them vao ban do ([0] - Quay lai)" << endl;

	cout << "Ma doi tuong: OBJ";
	string objID;
	cin >> objID;
	if (objID == "0") {
		return;
	}

	// tao ra doi tuong moi de luu vao map
	Object *obj= new Object;
	obj->id = "OBJ" + objID;

	cout << "Ten doi tuong: ";
	cin >> obj->name;

	cout << "Ten mo hinh: ";
	cin >> obj->directory;
	obj->directory = "models/" + obj->directory + ".obj";

	cout << "Vi tri x,y,z: ";
	cin >> obj->position;

	cout << "Ti le x,y,z: ";
	cin >> obj->scale;

	cout << "Goc xoay x,y,z: ";
	cin >> obj->swivelAngle;

	obj->spclObj = 0x0;

	cout << "Co la doi tuong dac biet khong? [Y/N] ";
	__fpurge(stdin);
	char isSpecial = cin.get();

	if (isSpecial == 'Y' || isSpecial == 'y') {
		SpecialObject *spclObj = new SpecialObject;
		spclObj->objID = obj->id;

		cout << "Ma doi tuong: GOTO";
		cin >> spclObj->id;
		spclObj->id = "GOTO" + spclObj->id;

		cout << "Cac map co the chuyen den: ";
		List<Map<List<Object> > > *i = data;
		while (i != 0x0) {
			if (i->id != mapID) {
				cout << i->id << "  ";
			}
			i = i->next;
		}
		cout << endl;

		string gotoMapID;
		Map<List<Object> > *gotoMap;

		do {
			cout << "Nhap ma ban do phai chuyen den: MAP";
			__fpurge(stdin);
			cin >> spclObj->gotoMap;
			gotoMapID = "MAP" + spclObj->gotoMap;

			if (gotoMapID == mapID) {
				cout << ERROR[4] << endl;
				continue;
			}

			// Lay du lieu cua map duoc chuyen den
			gotoMap = getList(data, gotoMapID);
			if (gotoMap == 0x0) {
				cout << ERROR[1] << endl;
			}

		} while (gotoMapID == mapID || gotoMap == 0x0);

		cout << "Vi tri x,y,z cua ban do moi: ";
		cin >> spclObj->positionMap;

		spclObj->positionObj = obj->position;
		obj->spclObj = spclObj;


		cout << "****************" << endl;
		cout << "Nhap thong tin doi tuong moi cua ban do duoc chuyen den" << endl;

		// tao ra doi tuong moi tren map duoc chuyen den
		// va cung la doi tuong dac biet
		// de quay lai map hien tai
		Object *gotoObj = new Object;
		cout << "Ma doi tuong: OBJ";
		string gotoID;
		cin >> gotoID;
		gotoObj->id = "OBJ" + gotoID;

		cout << "Ten doi tuong: ";
		cin >> gotoObj->name;

		gotoObj->directory = obj->directory;

		cout << "Vi tri x,y,z: ";
		cin >> gotoObj->position;

		cout << "Ti le x,y,z: ";
		cin >> gotoObj->scale;

		cout << "Goc xoay x,y,z: ";
		cin >> gotoObj->swivelAngle;


		SpecialObject *gotoSpclObj = new SpecialObject;
		gotoSpclObj->objID = gotoObj->id;

		cout << "Ma doi tuong dac biet: GOTO";
		cin >> gotoSpclObj->id;
		gotoSpclObj->id = "GOTO" + gotoSpclObj->id;

		gotoSpclObj->gotoMap = mapID.substr(3);

		cout << "Vi tri x,y,z cua ban do moi: ";
		cin >> gotoSpclObj->positionMap;

		gotoSpclObj->positionObj = gotoObj->position;
		gotoObj->spclObj = gotoSpclObj;


		List<Object> *t = gotoMap->data;
		if (t == 0x0) {
			t = new List<Object>;
		}
		addList(t, mapID, gotoObj);
		putMap(gotoMap, mapID, t);
	}

	if (listObj == 0x0) {
		listObj = new List<Object>;
	}
	addList(listObj, objID, obj);
	putMap(map, mapID, listObj);

	addObject();
}

/*
 * Chinh sua mot doi tuong trong map da duoc xac dinh
 * bang cach nhap STT cua doi tuong muon chinh sua
 *
 * Neu trong map khong co doi tuong nao thi nguoi choi duoc yeu cau them cac doi tuong moi vao map
 *
 * Qua trinh chinh sua ket thuc khi nguoi choi nhan phim [0] de quay lai menu
 */
void editObject() {
	cout << endl;
	if (listObj == 0x0) {
		cout << mapID << " hien khong co doi tuong, nhan [Enter] de them moi cac doi tuong...";
		__fpurge(stdin);
		cin.get();
		addObject();
	} else {
		cout << "Cac doi tuong co trong " << mapID << endl;
		showObject(listObj);
		cout << endl;
		while (true) {
			cout << "Nhap STT tuong ung cac doi tuong de sua ([0] - Quay lai): ";
			int ch;
			cin >> ch;
			if (ch == 0) {
				editMapMenu();
			}

			while (listObj != 0x0 && listObj->data->_no != ch) {
				listObj = listObj->next;
			}

			if (listObj == 0x0) {
				cout << ERROR[3] << endl;
				continue;
			}

			Object *editObj = listObj->data;
			Object *temp = new Object;
			cout << "Ban dang sua doi tuong " << ch << endl;
			cout << "Ma doi tuong (" << editObj->id << "): OBJ";
			cin >> temp->id;
			temp->id = "OBJ" + temp->id;

			cout << "Ten doi tuong (" << editObj->name << "): ";
			cin >> temp->name;

			cout << "Vi tri x,y,z (" << editObj->position << "): ";
			cin >> temp->position;

			cout << "Ti le x,y,z (" << editObj->scale << "): ";
			cin >> temp->scale;

			cout << "Goc xoay x,y,z (" << editObj->swivelAngle << "): ";
			cin >> temp->swivelAngle;

			temp->spclObj = editObj->spclObj;

			cout << "Luu cac thay doi? [Y/N] ";
			__fpurge(stdin);
			char save = cin.get();
			if (save == 'Y' || save == 'y') {
				*editObj = *temp;
			}
		}
	}
}

/*
 * Them mot map moi vao danh sach cac map,
 * dong thoi nguoi choi se duoc yeu cau them cac doi tuong
 * vao map moi duoc tao ra
 */
void addMap() {
	cout << endl;
	cout << "Nhap ma ban do muon them ([0] - Quay lai): MAP";
	cin >> mapID;
	if (mapID == "0") {
		gameMenu();
	}

	mapID = "MAP" + mapID;
	List<Map<List<Object> > > *i = data;
	while (i != 0x0) {
		if (i->id == mapID) {
			cout << ERROR[2] << endl;
			addMap();
		}
		i = i->next;
	}

	map = new Map<List<Object> >;
	map->data = 0x0;
	listObj = new List<Object>;

	addObject();

	addList(data, mapID, map);
	addMap();
}

/*
 * Chon mot map bat ky de chinh sua bang cach nhap vao ma ban do
 *
 * Sau do co cac tuy chon de nguoi choi sua doi tuong dang co trong map,
 * hoac them doi tuong moi vao map
 */
void editMap() {
	cout << endl;
	cout << "Cac map co the sua: ";
	List<Map<List<Object> > > *i = data;
	while (i != 0x0) {
		cout << i->id << "  ";
		i = i->next;
	}

	while (true) {
		cout << endl;
		cout << "Nhap ma ban do muon chinh sua ([0] - Quay lai): MAP";
		cin >> mapID;
		if (mapID == "0") {
			gameMenu();
		}

		mapID = "MAP" + mapID;
		map = getList(data, mapID);
		if (map == 0x0) {
			cout << ERROR[1] << endl;
			editMap();
		}

		listObj = map->data;
		editMapMenu();
	}
}
