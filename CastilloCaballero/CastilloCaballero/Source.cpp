#include "CGame.h"
#include <ctime>
int main() {
	srand(time(0));
	Console::CursorVisible = false;
	CGame* nuevoJuego = new CGame();

	nuevoJuego->iniciar();

	_sleep(800);
	_getch();
	return 0;
}