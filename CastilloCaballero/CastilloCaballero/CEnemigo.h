#pragma once
#include "CEntidad.h"

class CEnemigo : public CEntidad{
private:
	bool castillo;
	bool atrapado;

public:
	CEnemigo(int px, int py, int vx, int vy, int lar, int anch);
	~CEnemigo();

	bool getCastillo();
	bool getAtrapado();

	void setCastillo(bool cas);
	void setAtrapado(bool atra);

	void dibujar() override;
	void mover(int x, int y);

};

CEnemigo::CEnemigo(int px, int py, int vx, int vy, int lar, int anch) : CEntidad(px, py, vx, vy, lar, anch){
	castillo = false;
	atrapado = false;
}

CEnemigo::~CEnemigo()
{
}

bool CEnemigo::getCastillo(){
	return castillo;
}

bool CEnemigo::getAtrapado(){
	return atrapado;
}

void CEnemigo::setCastillo(bool cas){
	this->castillo = cas;
}

void CEnemigo::setAtrapado(bool atra){
	this->atrapado = atra;
}

void CEnemigo::dibujar(){
	Console::SetCursorPosition(posx, posy);     cout << " @ ";
	Console::SetCursorPosition(posx, posy + 1); cout << "/|\\";
	Console::SetCursorPosition(posx, posy + 2); cout << "/ \\";
}

void CEnemigo::mover(int x, int y){
	int aux = rand() % 2000;
	if (aux == 0) {
		borrar();
		if (posx > x) posx -= velx;
		if (posx < x) posx += velx;
		if (posy > y) posy -= vely;
		if (posy < y) posy += vely;
		dibujar();
	}
}
