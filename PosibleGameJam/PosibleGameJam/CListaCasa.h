#pragma once
#include "CListaPartes.h"

class CListaCasas{
private:
	vector <CListaPartes*> listaCasas;

public:
	CListaCasas();
	~CListaCasas();
	
	void agregarCasa();
	void moverCasa();
};

CListaCasas::CListaCasas()
{
}

CListaCasas::~CListaCasas()
{
}

void CListaCasas::agregarCasa(){
	listaCasas.push_back(new CListaPartes());
}

void CListaCasas::moverCasa(){
	for (int i = 0; i < listaCasas.size(); i++){
		listaCasas[i]->moverCasa();
	}
}
