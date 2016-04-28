#include "map.h"

void putMap(Map *map, string id, List<Object> *data) {
	if (map->id == "") {
		map->id = id;
		map->data = data;
		return;
	}

	Map *m = getMap(map, id);
	if (m != 0x0) {
		m->data = data;
		return;
	}

	Map *i = map;
	while (i->next != 0x0) {
		i = i->next;
	}

	m = new Map;
	m->id = id;
	m->data = data;

	i->next = m;
}

Map *getMap(Map *map, string id) {
	Map *m = map;
	while (m->id != id) {
		if (m->next != 0x0) {
			m = m->next;
		} else {
			return 0x0;
		}
	}

	return m;
}
