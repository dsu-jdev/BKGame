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
			if (id != 0x0) {
				addList(listMap, id, map);
			}

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

		if (str.find("GOTO") == 0) {
			SpecialObject *obj = new SpecialObject;
			obj->objID = objID;
			obj->id = str;
			ifs >> obj->gotoMap;
			ifs >> obj->positionMap;
			ifs >> obj->positionObj;
			ifs >> obj->distance;

			addList(listObj, str, obj);

			string mapID = "MAP" + obj->gotoMap;
			Map *m = getList(listMap, mapID);
			putMap(map, "MAP" + obj->gotoMap, m->data);
		}
	}

	return listMap;
}

