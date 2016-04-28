
#ifndef LIB_LIST_H_
#define LIB_LIST_H_

#include <iostream>

using namespace std;

template<typename T>
struct List {
	string id;
	T *data;
	List<T> *next;
};

template<typename T>
void addList(List<T> *list, string id, T *data) {
	if (list->id == "") {
		list->id = id;
		list->data = data;
		return;
	}

	List<T> *i = list;
	while (i->next != 0x0) {
		i = i->next;
	}

	List<T> *l = new List<T>;
	l->id = id;
	l->data = data;

	i->next = l;
}

template<class T>
T *getList(List<T> *list, string id) {
	List<T> *i= list;
	while (i != 0x0) {
		if (i->id == id) {
			return i->data;
		}

		i = i->next;
	}

	return 0x0;
}

#endif /* LIB_LIST_H_ */
