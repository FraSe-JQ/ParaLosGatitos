#pragma once
#include "CPartes.h"
#include <vector>
class CListaPartes{
private:
	vector <CPartes*> ListaPartes;
public:
	CListaPartes();
	~CListaPartes();

	void moverCasa();
};

CListaPartes::CListaPartes(){
	int aux_posx = rand() % 80 + 20;
	int aux_posy = rand() % 10 + 10;
	for (int i = 0; i < 3; i++) {
		int aux_x = rand() % 95 + 5;
		int aux_y = rand() % 15 + 5;
		if (i == 2) ListaPartes.push_back(new CPartes(aux_x, aux_y, 1, 1, 5, 8, i + 1, aux_posx, aux_posy));
		ListaPartes.push_back(new CPartes(aux_x, aux_y, 1, 1, 6, 13, i + 1, aux_posx, aux_posy));
	}
}

CListaPartes::~CListaPartes(){

}


void CListaPartes::moverCasa() {
	for (int i = 0; i < 3; i++) {
		ListaPartes[i]->mover();
	}
}
