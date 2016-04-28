#include <fstream>

#include "data.h"

List<Map> *readData() {
	ifstream ifs("src//data//data.map");

	List<Map> *listMap = new List<Map>;
	List<Object> *listObj;
	Map *map = new Map;

	string id;
	string str;

	while (ifs >> str) {
		if (str.find("MAP") == 0) {
			if (id != "") {
				addList(listMap, id, map);
			}

//			Map *m = new Map;
			map = new Map;
			listObj = new List<Object>;
			id = str;
		}

		string objID;

		if (str.find("OBJ") == 0) {
			Object *obj = new Object;
			objID = str;

			obj->id = objID;
			ifs >> obj->name;
			ifs >> obj->directory;
			ifs >> obj->position;
			ifs >> obj->scale;
			ifs >> obj->swivelAngle;

			addList(listObj, objID, obj);
			putMap(map, id, listObj);
		}

//		if (str.find("GOTO") == 0) {
//			SpecialObject *obj = new SpecialObject;
//			obj->objID = objID;
//			obj->id = str;
//			ifs >> obj->gotoMap;
//			ifs >> obj->positionMap;
//			ifs >> obj->positionObj;
//			ifs >> obj->distance;
//
////			addList(listObj, str, obj);
//
//			string mapID = "MAP" + obj->gotoMap;
//			Map *m = getList(listMap, mapID);
//			putMap(map, "MAP" + obj->gotoMap, m->data);
//		}
	}

	addList(listMap, id, map);
	return listMap;
}

void show(List<Map> *listMap) {
	List<Map> *list = listMap;
	while (list != 0x0) {
		cout << list->id << endl;
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
