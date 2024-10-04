#include "CCasa.h"

int main() {
	srand(time(0));
	Console::CursorVisible = false;
	CCasa* nuevaP = new CCasa();
	nuevaP->iniciar();

	return EXIT_SUCCESS;
}