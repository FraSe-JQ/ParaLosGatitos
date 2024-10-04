#pragma once
#include "CEntidad.h"

class CCastillo : public CEntidad{
private:

public:
	CCastillo(int posx, int posy);
	~CCastillo();

	void dibujar() override;
};

CCastillo::CCastillo(int posx, int posy) : CEntidad(posx, posy, 0, 0, 4,5){

}

CCastillo::~CCastillo(){
}

void CCastillo::dibujar(){
	Console::SetCursorPosition(posx, posy); cout << "-|||-";
	Console::SetCursorPosition(posx, posy+1); cout << " ||| ";
	Console::SetCursorPosition(posx, posy+2); cout << "|||||";
	Console::SetCursorPosition(posx, posy+3); cout << "=====";
}
