
#ifndef LIB_MAP_H_
#define LIB_MAP_H_

#include "list.h"
#include "object.h"

struct Map {
	string id;
	List<Object> *data;
	string currPos;
	Map *next;
};

void putMap(Map *map, string id, List<Object> *data);
Map *getMap(Map *map, string);

#endif /* LIB_MAP_H_ */
