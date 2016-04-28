#include <iostream>
#include <stdio_ext.h>

#include "map_info.h"
#include "move.h"
#include "../lib/list.h"
#include "../lib/object.h"
#include "../menu/menu.h"

using namespace std;

void move() {
	cout << "Nhap ID tuong ung cac doi tuong de di chuyen ([B] - Quay lai): ";
	__fpurge(stdin);
	int ch;
//	List<Object> *test = currMap.data;
//	cout << test->next->next->data->_no;
	cin >> ch;

	gameMenu();
}
