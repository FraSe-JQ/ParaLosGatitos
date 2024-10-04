#pragma once
#include "CEntidad.h"

class CDido : public CEntidad{
private:
	bool estado;
public:
	CDido(int posx, int posy, int spex, int spey, int height, int width);
	~CDido();
	void setEstado(bool estado);

	bool getEstado();

	void mover() override;
	void dibuja(int aux);
};

CDido::CDido(int posx, int posy, int spex, int spey, int height, int width) : CEntidad(posx, posy, spex, spey, height, width){
	estado = false;
}

CDido::~CDido()
{
}

void CDido::setEstado(bool estado) {
	this->estado = estado;
}

bool CDido::getEstado() {
	return this->estado;
}

void CDido::mover() {
	int aux = 1;
	borrar();
	if (posx == 0 || posx+3 == 119) {
		spex *= -1;
		aux *= -1;
	}
	if (posy == 5 || posy+1 == 29) {
		spey *= -1;
	}
	posx += spex;
	posy += spey;
	dibuja(aux);
}

void CDido::dibuja(int aux){
	switch (aux) {
	case 1:
		Console::SetCursorPosition(posx, posy);   cout << ">U)";
		Console::SetCursorPosition(posx, posy+1); cout << "(_>";
		break;
	case -1:
		Console::SetCursorPosition(posx, posy);     cout << "(U<";
		Console::SetCursorPosition(posx, posy + 1); cout << "<_)";
		break;
	default:
		break;
	}
}
