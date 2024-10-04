#pragma once
#include "CEntidad.h"

class CNoJugable : public CEntidad{
private:
	int maxLateral;
	int minLateral;
public:
	CNoJugable(int posx, int posy, int velx, int vely, int forma);
	~CNoJugable();

	int getMaxLateral();
	int getMinLateral();

	void dibujar() override;
};

CNoJugable::CNoJugable(int posx, int posy, int velx, int vely, int forma) : CEntidad(posx, posy, 19, 2, velx, vely, forma) {
	this->minLateral = posx;
	this->maxLateral = posx + 3;
	if (forma == 4) {
		ancho = 6;
	}
}

CNoJugable::~CNoJugable()
{
}

int CNoJugable::getMaxLateral(){
	return maxLateral;
}

int CNoJugable::getMinLateral(){
	return minLateral;
}


void CNoJugable::dibujar(){
	Console::ForegroundColor = ConsoleColor::Red;
	switch (forma) {
	case 1:
		Console::SetCursorPosition(posx, posy);     cout << "       __|__       ";
		Console::SetCursorPosition(posx, posy + 1); cout << "--@--@--(_)--@--@--";
		break;
	case 2:
		Console::SetCursorPosition(posx, posy);     cout << "       __|__";
		Console::SetCursorPosition(posx, posy + 1); cout << "--o--o--(_)--o--o--";
		break;
	case 3:
		Console::SetCursorPosition(posx, posy);     cout << "       __|__";
		Console::SetCursorPosition(posx, posy + 1); cout << "*----o--(_)--o----*";
		break;
	case 4:
		Console::SetCursorPosition(posx, posy);     cout << "[][][]";
		Console::SetCursorPosition(posx, posy + 1); cout << "[][][]";
		break;
	default:
		break;
	}
	Console::ResetColor();
}
