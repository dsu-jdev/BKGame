#include <iostream>

#include <iomanip>

#include "map_info.h"

using namespace std;

List<Map<List<Object> > > *data = readData(); // Du lieu tat ca cac ban do
Map<List<Object> > curMap; // Du lieu cua map hien tai

/*
 * Khoi tao cac gia tri mac dinh khi bat dau tro choi
 */
void init() {
	curMap = *getList(data, "MAP01");
	curMap.currPos = "0,0,0";
}

/*
 * Hien thi thong tin tat ca cac doi tuong co trong map khi nguoi choi di chuyen
 */
void showMapInfo() {
	cout << "================================================================" << endl;
	cout << "Map hien tai: " << curMap.id << endl;
	cout << "Vi tri: " << curMap.currPos << endl;
	cout << "Cac doi tuong co trong map:" << endl;
	showObject(curMap.data);
	cout << "================================================================" << endl;
}
