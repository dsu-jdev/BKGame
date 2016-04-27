#include <fstream>

#include "data.h"

List<Map> *readData() {
	ifstream ifs("test.txt");

	List<Map> *listMap = new List<Map>;
	List<Object> *listObj;
	Map *map;

	string id;
	string str;

	while (ifs >> str) {
		if (str.find("MAP") == 0) {
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

			addList(listObj, obj);
		}

//		if (str.find("GOTO") == 0) {
//			SpecialObject *obj = new SpecialObject;
//			obj->objID = objID;
//			obj->id = str.substr(4);
//			ifs >> obj->gotoMap;
//			ifs >> obj->positionMap;
//			ifs >> obj->positionObj;
//			ifs >> obj->distance;
//
//			putMap(map->next, obj->gotoMap, map->next->listObj);
//		}
	}
	putMap(map, id, listObj);
	addList(listMap, map);

	return listMap;
}

