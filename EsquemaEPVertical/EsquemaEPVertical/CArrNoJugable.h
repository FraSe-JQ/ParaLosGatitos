#pragma once
#include "CNoJugable.h"
#include <vector>

class CListaNoJugable {
private:
	vector <CNoJugable*> listaNoJugable;

public:
	CListaNoJugable();
	~CListaNoJugable();

	int getTamArr();
	int getPosxArr(int i);
	int getPosyArr(int i);
	int getAnchoArr(int i);
	int getFormaArr(int i);

	void agregarNoJugable(CNoJugable* nuevo);
	void moverTodo();
};

CListaNoJugable::CListaNoJugable() {

}

CListaNoJugable::~CListaNoJugable()
{
}

int CListaNoJugable::getTamArr(){
	return listaNoJugable.size();
}

int CListaNoJugable::getPosxArr(int i){
	if (i >= 0 && i < listaNoJugable.size() && listaNoJugable[i] != nullptr) {
		return listaNoJugable.at(i)->getPosx();
	}
}

int CListaNoJugable::getPosyArr(int i){
	if (i >= 0 && i < listaNoJugable.size() && listaNoJugable[i] != nullptr) {
		return listaNoJugable.at(i)->getPosy();
	}
}

int CListaNoJugable::getAnchoArr(int i){
	if (i >= 0 && i < listaNoJugable.size() && listaNoJugable[i] != nullptr) {
		return listaNoJugable.at(i)->getAncho();
	}
}

int CListaNoJugable::getFormaArr(int i){
	return listaNoJugable[i]->getForma();
}

void CListaNoJugable::agregarNoJugable(CNoJugable* nuevo){
	listaNoJugable.push_back(nuevo);
}

void CListaNoJugable::moverTodo(){
	for (int i = 0; i < listaNoJugable.size(); i++){
		listaNoJugable[i]->borrar();
		int auxvelx = listaNoJugable[i]->getVelx();
		int auxvely = listaNoJugable[i]->getVely();
		int auxposx = getPosxArr(i);
		int auxposy = getPosyArr(i);
		if (getPosyArr(i) == 0) {
			listaNoJugable[i]->setVely(auxvely*= -1);
		}
		if (getPosyArr(i) +1 == 29) {
			listaNoJugable[i]->setVely(auxvely *= -1);
		}
		if (getPosxArr(i) == listaNoJugable[i]->getMaxLateral()) {
			listaNoJugable[i]->setVelx(auxvelx *= -1);
		}
		if (getPosxArr(i) == listaNoJugable[i]->getMinLateral()) {
			listaNoJugable[i]->setVelx(auxvelx *= -1);
		}
		listaNoJugable[i]->setPosx(auxposx + auxvelx);
		listaNoJugable[i]->setPosy(auxposy + auxvely);
		listaNoJugable[i]->dibujar();
		_sleep(1);
	}
}

