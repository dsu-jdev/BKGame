#include <stdio_ext.h>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "check.h"
#include "map_info.h"
#include "../lib/map.h"
#include "../menu/menu.h"

using namespace std;

/*
 * Kiem tra su ton tai cua cac file mo hinh ung voi tung doi tuong
 * Neu co file mo hinh thi kiem tra xem co du so byte khong
 * Thong ke cac ket qua da kiem tra
 */
void checkValid() {
	int OK = 0;
	int FALSE = 0;
	int deficient = 0;
	int redundant = 0;

	List<void> *directory = new List<void>;
	directory->next = 0x0;

	List<Map<List<Object> > > *i = data;
	while (i != 0x0) {
		cout << "Dang kiem tra " << i->id << "..." << endl;
		List<Object> *j = i->data->data;
		while (j != 0x0) {
			Object *obj = j->data;
			cout << setw(32) << left << "\t" + obj->name + " (" + obj->id + ")";

			string dir = obj->directory.substr(0, 6) + "/" + obj->directory.substr(6);

			ifstream ifs(dir.c_str());
			if (ifs.good()) {
				List<void> *k = directory;
				while (k != 0X0) {
					if (k->id == dir) {
						break;
					}
					k = k->next;
				}
				if (k == 0x0) {
					void *t = 0x0;
					addList(directory, dir, t);
				}

				string modelName;
				ifs >> modelName;

				unsigned byteData;
				ifs >> byteData;

				string data;
				ifs >> data;

				if (byteData == data.size()) {
					cout << "OK!";
				} else {
					if (byteData > data.size()) {
						cout << "Thieu byte";
					} else {
						cout << "Thua byte";
					}
				}
			} else {
				cout << "FALSE!";
				FALSE++;
			}
			cout << endl;
			j = j->next;
		}

		cout << endl;
		i = i->next;
	}

	List<void> *k = directory;
	while (k != 0x0) {
		ifstream ifs(k->id.c_str());
		string modelName;
		ifs >> modelName;

		unsigned byteData;
		ifs >> byteData;

		string data;
		ifs >> data;

		if (byteData == data.size()) {
			OK++;
		} else {
			if (byteData > data.size()) {
				deficient++;
			} else {
				redundant++;
			}
		}
		k = k->next;
	}

	cout << "Ket qua:" << endl;
	cout << "\tSo mo hinh du byte: " << OK << endl;
	cout << "\tSo mo hinh thieu byte: " << deficient << endl;
	cout << "\tSo mo hinh thua byte: " << redundant << endl;
	cout << "\tSo doi tuong khong co file mo hinh: " << FALSE << endl;

	cout << "Nhan phim [Enter] de quay lai...";
	__fpurge(stdin);
	cin.get();
	gameMenu();
}
