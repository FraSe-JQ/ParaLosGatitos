#include "CGame.h"

int main() {
	srand(time(0));
	CGame* nuevaPartida = new CGame();
	Console::CursorVisible = false;
	nuevaPartida->inciar();

	system("pause");
	return EXIT_SUCCESS;
}