#include "CGame.h"
#include <ctime>
int main() {
	srand(time(0));
	Console::CursorVisible = false;
	CJuego* partida = new CJuego(3);

	partida->iniciar();

	delete partida;
	system("pause");
	return EXIT_SUCCESS;
}