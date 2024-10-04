#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>
#include <vector>

using namespace std;
using namespace System;


class CEntidad{
protected:
	int posx,
		posy,
		velx,
		vely,
		largo,
		ancho;

public:
	CEntidad(int px, int py, int vx, int vy, int lar, int anch);
	~CEntidad();

	// Declaración de getters
	int getPosX();
	int getPosY();
	int getVelX();
	int getVelY();
	int getLargo();
	int getAncho();

	// Declaración de setters
	void setPosX(int x);
	void setPosY(int y);
	void setVelX(int x);
	void setVelY(int y);
	void setLargo(int l);
	void setAncho(int a);

	void borrar();
	virtual void dibujar();
	virtual void mover();
};

CEntidad::CEntidad(int px, int py, int vx, int vy, int lar, int anch){
	this->posx = px;
	this->posy = py;
	this->velx = vx;
	this->vely = vy;
	this->largo = lar;
	this->ancho = anch;
}

CEntidad::~CEntidad(){}

void CEntidad::borrar(){
	for (int i = 0; i < largo; i++){
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(posx+j,posy+i); cout << " ";
		}
	}
}

inline void CEntidad::dibujar()
{
}

inline void CEntidad::mover()
{
}

// Getters
int CEntidad::getPosX() { return posx; }
int CEntidad::getPosY() { return posy; }
int CEntidad::getVelX() { return velx; }
int CEntidad::getVelY() { return vely; }
int CEntidad::getLargo() { return largo; }
int CEntidad::getAncho() { return ancho; }

// Setters
void CEntidad::setPosX(int x) { posx = x; }
void CEntidad::setPosY(int y) { posy = y; }
void CEntidad::setVelX(int x) { velx = x; }
void CEntidad::setVelY(int y) { vely = y; }
void CEntidad::setLargo(int l) { largo = l; }
void CEntidad::setAncho(int a) { ancho = a; }

