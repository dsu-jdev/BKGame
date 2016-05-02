
#ifndef LIB_OBJECT_H_
#define LIB_OBJECT_H_

#include <iostream>

#include "list.h"

using namespace std;

struct SpecialObject {
	string objID;
	string id;
	string gotoMap;
	string positionMap;
	string positionObj;
	string distance;
};

struct Object {
	int _no;
	string id;
	string name;
	string directory;
	string position;
	string scale;
	string swivelAngle;
	SpecialObject *spclObj;
};

void showObject(List<Object> *listObj);

#endif /* LIB_OBJECT_H_ */
