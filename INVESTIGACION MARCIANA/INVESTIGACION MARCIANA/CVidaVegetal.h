#pragma once
#include "CEntidad.h"

class CVidaVegetal : public CEntidad{
private:
	bool estado;
public:
	CVidaVegetal(int posx, int posy, int spex, int spey, int height, int width);
	~CVidaVegetal();

	void dibujar();
	void mover() override;
};

CVidaVegetal::CVidaVegetal(int posx, int posy, int spex, int spey, int height, int width) : CEntidad(posx, posy, spex, spey, height, width){
	estado = false;
}

CVidaVegetal::~CVidaVegetal(){
}

void CVidaVegetal::dibujar(){
	Console::ForegroundColor = ConsoleColor::DarkGreen;
	Console::SetCursorPosition(posx, posy);   cout << " (W)";
	Console::SetCursorPosition(posx, posy + 1); cout << "_\\|/_";
	Console::ResetColor();
}

void CVidaVegetal::mover()
{
}

