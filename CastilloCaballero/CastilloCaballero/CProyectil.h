#pragma once
#include "CEntidad.h"

class CProyectil : public CEntidad{
private:
	bool estado;
	bool colision;
	char ultimaDirec;
public:
	CProyectil(int px, int py, char ultimaDirec);
	~CProyectil();

	// Declaración de getters
	bool getEstado();
	bool getColision();
	char getUltimaDirec();

	// Declaración de setters
	void setEstado(bool e);
	void setColision(bool c);
	void setUltimaDirec(char d);

	void dibujar() override;
	void mover() override;
};

CProyectil::CProyectil(int px, int py, char uD) : CEntidad(px, py, 1, 1, 1, 1){
	estado = false;
	colision = false;
	ultimaDirec = uD;
}

CProyectil::~CProyectil(){

}

void CProyectil::dibujar(){
	Console::SetCursorPosition(posx, posy); cout << (char)4;
}

void CProyectil::mover(){
	borrar();
	if (posx == 0 || posx == 119 || posy == 0 || posy == 29) estado = true;
	if (estado == false) {
		switch (ultimaDirec) {
		case 'W':
			posy -= vely;
			break;
		case 'S':
			posy += vely;
			break;
		case 'A':
			posx -= velx;
			break;
		case 'D':
			posx += velx;
			break;
		default:
			break;
		}
	}
	dibujar();
	_sleep(1);
}

// Getters
bool CProyectil::getEstado() { return estado; }
bool CProyectil::getColision() { return colision; }
char CProyectil::getUltimaDirec() { return ultimaDirec; }

// Setters
void CProyectil::setEstado(bool e) { estado = e; }
void CProyectil::setColision(bool c) { colision = c; }
void CProyectil::setUltimaDirec(char d) { ultimaDirec = d; }