#pragma once
#include "CEntidad.h"
#include "CArco.h"

class CCaballero : public CEntidad{
private:
	char ultimaTecla;
	CArco* arcoCaballero;
public:
	CCaballero(int px, int py, int vx, int vy, int lar, int anch);
	~CCaballero();

	char getUltimaTecla();
	int getTamVecProyectiles();
	int getPosxProyectiles(int i);
	int getPosyProyectiles(int i);
	bool getEstadoProyectiles(int i);
	bool getColisionProyectiles(int i);
	void setColisioProyectiles(int i, bool es);


	void dibujar();
	void mover();
};

CCaballero::CCaballero(int px, int py, int vx, int vy, int lar, int anch) : CEntidad(px, py, vx, vy, lar, anch) {
	ultimaTecla = 'W';
	arcoCaballero = new CArco(posx, posy);
}

CCaballero::~CCaballero(){
}

char CCaballero::getUltimaTecla(){ return ultimaTecla; }

int CCaballero::getTamVecProyectiles(){
	return arcoCaballero->getTamVec();
}

int CCaballero::getPosxProyectiles(int i){
	return arcoCaballero->getPosxProyectil(i);
}

int CCaballero::getPosyProyectiles(int i){
	return arcoCaballero->getPosyProyectil(i);
}

bool CCaballero::getEstadoProyectiles(int i){
	return arcoCaballero->getEstadoProyectil(i);
}

bool CCaballero::getColisionProyectiles(int i){
	return arcoCaballero->getEstadoProyectil(i);
}

void CCaballero::setColisioProyectiles(int i, bool es){
	arcoCaballero->setEstadoColision(i, es);
}

void CCaballero::dibujar(){
	Console::SetCursorPosition(posx, posy);   cout << (char)18 << "* ";
	Console::SetCursorPosition(posx, posy+1); cout << "/|\\";
	Console::SetCursorPosition(posx, posy+2); cout << "/ \\";
}

void CCaballero::mover(){
	if (_kbhit()) {
		borrar();
		char tecla = toupper(getch());
		if (tecla == 'W' && posy > 0) posy -= vely;
		if (tecla == 'S' && posy < 29) posy += vely;
		if (tecla == 'A' && posx > 0) posx -= velx;
		if (tecla == 'D' && posx < 119) posx += velx;
		if (tecla == 'P') arcoCaballero->disparo(ultimaTecla);
		if (tecla == 'W' || tecla == 'S' || tecla == 'A' || tecla == 'D') ultimaTecla = tecla;
		arcoCaballero->setPosX(posx);
		arcoCaballero->setPosY(posy);
	}
	arcoCaballero->moverProyectiles();
	dibujar();
}