#include <iostream>

#include <iomanip>

#include "map_info.h"

using namespace std;

List<Map> data = *readData();
Map currMap;

void init() {
	currMap = *getList(&data, "MAP01");
	currMap.currPos = "0,0,0";
}

void showMapInfo() {
	cout << "================================================================" << endl;
	cout << "Map hien tai: " << currMap.id << endl;
	cout << "Vi tri: " << currMap.currPos << endl;
	cout << "Cac doi tuong co trong map:" << endl;
	showObject(currMap.data);
	cout << "================================================================" << endl << endl;
}
