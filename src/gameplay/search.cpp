#include <iostream>
#include <stdio_ext.h>
#include <sstream>

#include "map_info.h"
#include "search.h"
#include "../menu/menu.h"
#include "../lib/stack.h"
#include "../lib/queue.h"

#define MAX 50

using namespace std;

int p[MAX];
char color[MAX];

/*
 * Thuat toan duyet do thi theo chieu rong (Breadth-First Search)
 */
void BFS(string mapID) {
	int s;
	istringstream(mapID.substr(3)) >> s;
	color[s] = 'G';
	p[s] = -1;
	pushQueue(s);
	while (!queueEmpty()) {
		int u = popQueue();

		ostringstream id;
		if (u < 10) {
			id << "MAP0" << u;
		} else {
			id << "MAP" << u;
		}

		Map<List<Object> > *map = getList(data, id.str())->next;
		while (map != 0x0) {
			int v;
			istringstream(map->id.substr(3)) >> v;
			if (color[v] == 'W') {
				color[v] = 'G';
				p[v] = u;
				pushQueue(v);
			}

			map = map->next;
		}

		color[u] = 'B';
	}
}

/*
 * Nhap vao ma mot map bat ky
 * in ra duong di tu map hien tai den map do theo thuat toan BFS
 * va thong ke cac mo hinh xuat hien nhieu nhat tren duong di
 */
void printPath(string map1, string map2) {
	int u;
	istringstream(map1.substr(3)) >> u;
	int v;
	istringstream(map2.substr(3)) >> v;
	List<Map<List<Object> > > *listMap = data;
	while (listMap != 0x0) {
		int i;
		istringstream(listMap->id.substr(3)) >> i;
		color[i] = 'W';
		p[i] = -1;

		listMap = listMap->next;
	}

	BFS(map1);
	if (color[v] == 'W') {
		cout << "Khong co duong di tu " << map1 << " den " << map2 << endl;
	} else {
		cout << "Duong di tu " << map1 << " den " << map2 << ": ";
		int x = v;
		while (x != u) {
			pushStack(x);
			x = p[x];
		}

		List<Object> *listObj;

		Map<int> *freq = new Map<int>;
		freq->next = 0x0;

		cout << map1;

		listObj = getList(data, map1)->data;

		while (listObj != 0x0) {
			Object *obj = listObj->data;
			string dir = obj->directory;
			int *f = new int;
			if (getMap(freq, dir) == 0x0) {
				*f = 1;
			} else {
				*f = *getMap(freq, dir)->data + 1;
			}
			putMap(freq, dir, f);
			listObj = listObj->next;
		}

		while (!stackEmpty()) {
			x = popStack();
			ostringstream id;
			if (x < 10) {
				id << "MAP0" << x;
			} else {
				id << "MAP" << x;
			}

			cout << " -> "<< id.str();

			listObj = getList(data, id.str())->data;

			while (listObj != 0x0) {
				Object *obj = listObj->data;
				string dir = obj->directory;
				int *f = new int;
				if (getMap(freq, dir) == 0x0) {
					*f = 1;
				} else {
					*f = *getMap(freq, dir)->data + 1;
				}
				putMap(freq, dir, f);
				listObj = listObj->next;
			}
		}
		cout << endl;

		while (freq != 0x0) {
			cout << freq->id << ": " << *freq->data << endl;
			freq = freq->next;
		}
	}
}

void findPath() {
	cout << "Vi tri hien tai: " << curMap.id << endl;

	cout << "Cac map hien co: ";
	List<Map<List<Object> > > *i = data;
	while (i != 0x0) {
		cout << i->id << "  ";
		i = i->next;
	}
	cout << endl;

	Map<List<Object> > *map;
	string mapID;
	do {
		cout << "Nhap ma ban do muon den de tim duong ([0] -Quay lai): MAP";
		cin >> mapID;
		if (mapID == "0") {
			gameMenu();
		}
		mapID = "MAP" + mapID;
		map = getList(data, mapID);
		if (map == 0x0) {
			cout << ERROR[1] << endl;
		}
	} while (map == 0x0);

	printPath(curMap.id, mapID);

	cout << "Nhan phim [Enter] de quay lai...";
	__fpurge(stdin);
	cin.get();
	gameMenu();
}
