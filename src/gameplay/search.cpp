#include <iostream>
#include <stdio_ext.h>

#include "search.h"
#include "../menu/menu.h"

using namespace std;

// tim duong di tu map hien tai den mot map bat ky
void findPath() {
	cout << "Chuc nang dang duoc xay dung, quay lai sau...";
	__fpurge(stdin);
	cin.get();
	gameMenu();
}
