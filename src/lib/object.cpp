#include <iomanip>

#include "object.h"

void showObject(List<Object> *listObj) {
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

//Object *getObject(List<Object> *listObj, int no) {
//
//}
