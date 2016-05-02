
#ifndef SRC_GAMEPLAY_MAP_INFO_H_
#define SRC_GAMEPLAY_MAP_INFO_H_

#include "../data/data.h"

extern List<Map<List<Object> > > *data;
extern Map<List<Object> > curMap;

void init();
void showMapInfo();

#endif /* SRC_GAMEPLAY_MAP_INFO_H_ */
