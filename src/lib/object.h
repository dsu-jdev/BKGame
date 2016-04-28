
#ifndef LIB_OBJECT_H_
#define LIB_OBJECT_H_

#include <iostream>

using namespace std;

struct Object {
	int _no;
	string id;
	string name;
	string directory;
	string position;
	string scale;
	string swivelAngle;
};

struct SpecialObject {
	string objID;
	string id;
	string gotoMap;
	string positionMap;
	string positionObj;
	string distance;
	SpecialObject *next;
};

#endif /* LIB_OBJECT_H_ */
