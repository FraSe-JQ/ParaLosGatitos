#pragma once
#include "CEntidad.h"

class CNave : public CEntidad{
private:

public:
	CNave(int posx, int posy, int spex, int spey, int height, int width);
	~CNave();

	void dibujar();
	void mover() override;
};

CNave::CNave(int posx, int posy, int spex, int spey, int height, int width): CEntidad(posx, posy, spex, spey, height, width){

}

CNave::~CNave()
{
}

void CNave::dibujar(){
	Console::SetCursorPosition(posx, posy); cout << "     ___";
	Console::SetCursorPosition(posx, posy+1); cout << " ___ / \\___";
	Console::SetCursorPosition(posx, posy+2); cout << "  ('O^O')";
	Console::SetCursorPosition(posx, posy+3); cout << "'==ooooooo=='";
}

void CNave::mover(){
	if (_kbhit()) {
		borrar();
		char tecla = toupper(getch());
		if (tecla == 'W' && posy > 5) posy -= spey;
		if (tecla == 'S' && posy+3 < 29) posy += spey;
		if (tecla == 'A' && posx > 0) posx -= spex;
		if (tecla == 'D' && posx+11 < 119) posx += spex;
		dibujar();
	}
}
