#pragma once
#include "CEntidad.h"

class CDodo : public CEntidad{
private:
	bool estado;
public:
	CDodo(int posx, int posy, int spex, int spey, int height, int width);
	~CDodo();
	void setEstado(bool estado);

	bool getEstado();

	void mover() override;
	void dibujar();
};

CDodo::CDodo(int posx, int posy, int spex, int spey, int height, int width) : CEntidad(posx, posy, spex, spey, height, width){
	estado = false;
}	

CDodo::~CDodo(){
}

void CDodo::setEstado(bool estado){
	this->estado = estado;
}

bool CDodo::getEstado(){
	return this->estado;
}

void CDodo::mover(){
	borrar();
	if (posy == 5) {
		spey *= -1;
	}
	if (posy + 3 == 29) {
		spey *= -1;
	}
	posy += spey;
	dibujar();
}

void CDodo::dibujar(){
	Console::SetCursorPosition(posx, posy); cout << "/ \\ / \\";
	Console::SetCursorPosition(posx, posy+1); cout << " ((ovo))";
	Console::SetCursorPosition(posx, posy+2); cout << " ():::()";
	Console::SetCursorPosition(posx, posy+3); cout << "   VVV";
}
