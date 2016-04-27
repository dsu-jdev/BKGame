
#ifndef MAP_H_
#define MAP_H_

#include <iostream>

#include "list.h"
#include "object.h"

using namespace std;

struct Map {
	string id;
	List<Object> *data;
	Map *next;
};

void putMap(Map *map, string id, List<Object> *data);
Map *getMap(Map *map, string);

#endif /* MAP_H_ */
