#pragma once
#include <conio.h>
#include "CListaCasa.h"

class CCasa{
private:
	CListaCasas* casas;
public:
	CCasa();
	~CCasa();

	void iniciar();
};

CCasa::CCasa(){
	casas = new CListaCasas();
}

CCasa::~CCasa()
{
}

void CCasa::iniciar(){
	bool end = false;
	while (!end){
		if (_kbhit()) {
			char tecla = toupper(getch());
			switch (tecla){
			case 27: end = true; break;
			case 'G': casas->agregarCasa(); break;
			default:
				break;
			}
		}
		casas->moverCasa();
		_sleep(200);
	}
}
