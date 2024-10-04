#pragma once
#include "CEntidad.h"
#include <conio.h>

class CJugador : public CEntidad{
private:
public:
	CJugador(int posx, int posy, int ancho, int largo, int velx, int vely, int forma);
	~CJugador();

	void mover();
};

CJugador::CJugador(int posx, int posy, int ancho, int largo, int velx, int vely, int forma) : CEntidad(posx, posy, ancho, largo, velx, vely, forma){

}

CJugador::~CJugador()
{
}

void CJugador::mover(){
	if (_kbhit()) {
		borrar();
		char tecla = toupper(getch());
		if (tecla == 'W' && posy > 0 ) { posy -= vely; }
		if (tecla == 'S' && posy < 29) { posy += vely; }
		if (tecla == 'A' && posx > 0 ) { posx -= velx; }
		if (tecla == 'D' && posx < 119) { posx += velx; }
		dibujar();
	}
}
