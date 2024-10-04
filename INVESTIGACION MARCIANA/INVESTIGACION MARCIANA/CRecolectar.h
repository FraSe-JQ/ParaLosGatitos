#pragma once
#include "CEntidad.h"

class CRecolectar : public CEntidad  {
private:
	int forma;
	bool estado;
public:
	CRecolectar(int posx, int posy, int spex, int spey, int height, int width, int forma);
	~CRecolectar();

	void setEstado(bool estado);
	void setForma(int forma);

	bool getEstado();
	int getForma();

	void dibujar();
	void mover() override;
};

CRecolectar::CRecolectar(int posx, int posy, int spex, int spey, int height, int width, int forma) : CEntidad(posx, posy, spex, spey, height, width){
	this->forma = forma;
	this->estado = false;
}

CRecolectar::~CRecolectar(){

}

void CRecolectar::setEstado(bool estado){
	this->estado = estado;
}

void CRecolectar::setForma(int forma){
	this->forma = forma;
}

bool CRecolectar::getEstado(){
	return estado;
}

inline int CRecolectar::getForma(){
	return forma;
}

void CRecolectar::dibujar(){
	switch (forma){
	case 1:
		Console::ForegroundColor = ConsoleColor::DarkGreen;
		Console::SetCursorPosition(posx, posy);   cout << " (W)";
		Console::SetCursorPosition(posx, posy+1); cout << "_\\|/_";
		Console::ResetColor();
		break;
	case 2:
		Console::ForegroundColor = ConsoleColor::DarkCyan;
		Console::SetCursorPosition(posx, posy); cout << "°";
		Console::ResetColor();
		break;
	default:
		break;
	}
}

void CRecolectar::mover(){
	borrar();
	dibujar();
}
