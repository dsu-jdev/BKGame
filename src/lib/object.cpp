#include <iomanip>
#include <stdio_ext.h>

#include "object.h"
#include "../gameplay/map_info.h"
#include "../menu/menu.h"

void showObject(List<Object> *listObj) {
	if (listObj->data == 0) {
		cout << curMap.id << " khong co doi tuong nao. Nhan [Enter] de quay lai menu...";
		__fpurge(stdin);
		cin.get();
		gameMenu();
	}

	cout << "Cac doi tuong co trong map:" << endl;
	cout << "STT Ma DT   Ten doi tuong       Vi tri      Ti le   Goc xoay" << endl;
	List<Object> *i = listObj;
	int no = 1;
	while (i != 0x0) {
		Object *obj = i->data;
		obj->_no = no++;
		cout << setw(4) << left << obj->_no
			 << setw(8) << left << obj->id
			 << setw(20) << left << obj->name
//			 << setw(24) << left << obj->directory
			 << setw(12) << left << obj->position
			 << setw(8) << left << obj->scale
			 << setw(8) << left << obj->swivelAngle;

		if (obj->spclObj != 0x0) {
			cout << "-> Chuyen den MAP" << obj->spclObj->gotoMap;
		}
		cout << endl;
		i = i->next;
	}
}
