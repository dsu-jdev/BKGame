#include <iostream>

#include "map_info.h"

using namespace std;

List<Map> data = *readData();

void showMapInfo() {
	cout << "Map hien tai: " << _currMap.id << endl;
	cout << "Vi tri: " << _currMap.currPos << endl;
	cout << "Cac doi tuong co trong map:" << endl;
	List<Object> *listObj = _currMap.data;
	int i = 1;
	while (listObj != 0x0) {
		Object *obj = listObj->data;
		obj->_no = i++;
		cout << obj->_no << "\t" << obj->id << "\t" << obj->name << "\t" << obj->directory << "\t"
				<< obj->position << "\t" << obj->scale << "\t" << obj->swivelAngle << endl;
		listObj = listObj->next;
	}
}

void init() {
	_currMap = *getList(&data, "MAP05");
	_currMap.currPos = "0,0,0";
}
