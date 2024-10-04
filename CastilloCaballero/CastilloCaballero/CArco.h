#pragma once
#include "CEntidad.h"
#include "CProyectil.h"

class CArco : public CEntidad {
private:
	vector <CProyectil* > listaProyectil;
public:
	CArco(int px, int py);
	~CArco();

	int getTamVec();
	int getPosxProyectil(int i);
	int getPosyProyectil(int i);
	bool getEstadoProyectil(int i);
	bool getEstadoColision(int i);

	void setEstadoColision(int i, bool es);

	void disparo(char tecla);
	void moverProyectiles();
};

CArco::CArco(int px, int py) : CEntidad(px, py, 1,1,1,1){

}

CArco::~CArco(){
}

int CArco::getTamVec(){
	return listaProyectil.size();
}

int CArco::getPosxProyectil(int i){
	return listaProyectil[i]->getPosX();
}

int CArco::getPosyProyectil(int i){
	return listaProyectil[i]->getPosY();
}

bool CArco::getEstadoProyectil(int i){
	return listaProyectil[i]->getEstado();
}

bool CArco::getEstadoColision(int i){
	return listaProyectil[i]->getColision();
}

void CArco::setEstadoColision(int i, bool es){
	listaProyectil[i]->setColision(es);
}

void CArco::disparo(char tecla){
	listaProyectil.push_back(new CProyectil(posx, posy, tecla));
}

void CArco::moverProyectiles(){
	for (int i = 0; i < listaProyectil.size(); i++) {
		if (listaProyectil[i]->getEstado() == false && listaProyectil[i]->getColision() == false) {
			listaProyectil[i]->mover();
		}
		else{
			listaProyectil[i]->borrar();
			listaProyectil.erase(listaProyectil.begin() + i);
		}
	}
}

