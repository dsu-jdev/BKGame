#include "menu/menu.h"
#include "data/data.h"

int main(int argc, char **argv) {
	logo();
	mainMenu();
	show(readData());

	return 0;
}
