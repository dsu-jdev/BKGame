
#ifndef OBJECT_H_
#define OBJECT_H_

#include <iostream>

using namespace std;

struct Object {
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
};

#endif /* OBJECT_H_ */
