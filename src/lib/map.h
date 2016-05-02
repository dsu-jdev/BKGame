
#ifndef LIB_MAP_H_
#define LIB_MAP_H_

#include "list.h"
#include "object.h"

template<typename T>
struct Map {
	string id;
	T *data;
	string currPos;
	Map<T> *next;
};

template<typename T>
void putMap(Map<T> *map, string id, T *data) {
	if (map->id == "") {
		map->id = id;
		map->data = data;
		map->next = 0x0;
		return;
	}

	Map<T> *m = getMap(map, id);
	if (m != 0x0) {
		m->data = data;
		return;
	}

	Map<T> *i = map;
	while (i->next != 0x0) {
		i = i->next;
	}

	m = new Map<T>;
	m->id = id;
	m->data = data;
	m->next = 0x0;

	i->next = m;
}

template<typename T>
Map<T> *getMap(Map<T> *map, string id) {
	Map<T> *m = map;
	while (m->id != id) {
		if (m->next != 0x0) {
			m = m->next;
		} else {
			return 0x0;
		}
	}

	return m;
}

#endif /* LIB_MAP_H_ */
