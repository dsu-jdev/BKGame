#include <fstream>

#include "data.h"

/*
 * Doc du lieu tu file
 * Tra ve List cac map cung voi cac doi tuong ben trong map
 */
List<Map<List<Object> > > *readData() {
	ifstream ifs("data.map");

	List<Map<List<Object> > > *listMap = new List<Map<List<Object> > >;
	Map<List<Object> > *map;
	List<Object> *listObj;
	Object *obj;

	string id;
	string objID;
	string str;

	while (ifs >> str) {
		if (str.find("MAP") == 0) {
			if (id != "") {
				addList(listMap, id, map);
			}

			map = new Map<List<Object> >;
			listObj = new List<Object>;
			id = str;
		}

		if (str.find("OBJ") == 0) {
			objID = str;
			obj = new Object;
			obj->id = objID;
			ifs >> obj->name;
			ifs >> obj->directory;
			ifs >> obj->position;
			ifs >> obj->scale;
			ifs >> obj->swivelAngle;

			addList(listObj, objID, obj);
		}

		if (str.find("GOTO") == 0) {
			SpecialObject *spclObj = new SpecialObject;
			spclObj->objID = objID;
			spclObj->id = str;
			ifs >> spclObj->gotoMap;
			ifs >> spclObj->positionMap;
			ifs >> spclObj->positionObj;
			ifs >> spclObj->distance;
			obj->spclObj = spclObj;

			string mapID = "MAP" + spclObj->gotoMap;

			putMap(map, mapID, new List<Object>);
		}
		putMap(map, id, listObj);
	}

	addList(listMap, id, map);
	return listMap;
}

void show(List<Map<List<Object> > > *listMap) {
	List<Map<List<Object> > > *list = listMap;
	while (list != 0x0) {
		cout << list->id << ":";
		Map<List<Object> > *map = list->data->next;
		while (map != 0x0) {
			cout << " " << map->id;
			map = map->next;
		}
		cout << endl;
		List<Object> *listObj = list->data->data;
		while (listObj != 0x0) {
			cout << "\t" << listObj->data->id << endl;
			cout << "\t" << listObj->data->name << endl;
			cout << "\t" << listObj->data->directory << endl;
			cout << "\t" << listObj->data->position << endl;
			cout << "\t" << listObj->data->scale << endl;
			cout << "\t" << listObj->data->swivelAngle << endl;
			cout << endl;

			listObj = listObj->next;
		}

		list = list->next;
	}
}
