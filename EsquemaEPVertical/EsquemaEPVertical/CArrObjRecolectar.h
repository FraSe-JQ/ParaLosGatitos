#pragma once
#include "CObjRecoletar.h"
#include <vector>

class CListaObjetos{
private:
	vector<CRecolectar*> listaObjeto;
public:
	CListaObjetos();
	~CListaObjetos();

	int getTamArr();
	int getPosxArr(int i);
	int getPosyArr(int i);
	bool getEstadoArr(int i);

	void setEstadoArr(int i, bool es);

	void agregarObj(CRecolectar* nuevo);
	void imprimirTodo();
};

CListaObjetos::CListaObjetos()
{
}

CListaObjetos::~CListaObjetos()
{
}

int CListaObjetos::getPosxArr(int i) {
	return listaObjeto[i]->getPosx();
}

int CListaObjetos::getPosyArr(int i) {
	return listaObjeto[i]->getPosy();
}

bool CListaObjetos::getEstadoArr(int i){
	return listaObjeto[i]->getEstado();
}

void CListaObjetos::setEstadoArr(int i, bool es){
	listaObjeto[i]->setEstado(es);
}

int CListaObjetos::getTamArr(){
	return listaObjeto.size();
}

void CListaObjetos::agregarObj(CRecolectar* nuevo){
	listaObjeto.push_back(nuevo);
}

void CListaObjetos::imprimirTodo(){
	for (int i = 0; i < listaObjeto.size(); i++){
		if (listaObjeto[i]->getEstado() == false) {
			listaObjeto[i]->dibujar();
		}
	}
}
