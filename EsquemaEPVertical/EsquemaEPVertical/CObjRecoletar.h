#pragma once
#include "CEntidad.h"

class CRecolectar : public CEntidad{
private:
	bool estado;
public:
	CRecolectar(int posx, int posy);
	~CRecolectar();

	bool getEstado();

	void setEstado(bool e);

	void dibujar() override;
};

CRecolectar::CRecolectar(int posx, int posy) : CEntidad(posx, posy,1,1,0,0,219){
	estado = false;
}

CRecolectar::~CRecolectar(){

}

bool CRecolectar::getEstado(){
	return estado;
}

void CRecolectar::setEstado(bool e){
	estado = e;
}

void CRecolectar::dibujar(){
	Console::SetCursorPosition(posx, posy); cout << "+";
}

