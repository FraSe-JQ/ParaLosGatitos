#pragma once
#include "CEntidad.h"

class CParticulaO2 : public CEntidad{
private:
	bool estado;
public:
	CParticulaO2(int posx, int posy, int spex, int spey, int height, int width);
	~CParticulaO2();

	void setEstado(bool estado);

	bool getEstado();

	void dibujar();
	void mover() override;
};

CParticulaO2::CParticulaO2(int posx, int posy, int spex, int spey, int height, int width) : CEntidad(posx, posy, spex, spey, height, width) {
	estado = false;
}

CParticulaO2::~CParticulaO2()
{
}

void CParticulaO2::setEstado(bool estado){
	this->estado = estado;
}

bool CParticulaO2::getEstado(){
	return estado;
}

void CParticulaO2::dibujar(){
	Console::ForegroundColor = ConsoleColor::DarkCyan;
	Console::SetCursorPosition(posx, posy); cout << "°";
	Console::ResetColor();
}

void CParticulaO2::mover()
{
}

