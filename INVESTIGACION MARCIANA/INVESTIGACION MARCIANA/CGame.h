#pragma once
#include "CNave.h"
#include "CDido.h"
#include "CDodo.h"
#include "CVidaVegetal.h"
#include "CParticulaO2.h"
#include <vector>

class CGame{
private:
	CNave* naveTerricola;
	CDodo* aveDodo;
	vector <CParticulaO2* > listaParticulaO2;
	vector <CVidaVegetal* > listaVidaVegetal;
	vector <CDido*> listaAveDido;

	int vidas;
	int progresoVA;
	int progresoVV;
	int progresoPM;

public:
	CGame();
	~CGame();

	void inciar();
	void imprimirTodoRecoleccion();
	void imrpimirTodoAveDido();
	void colisionNaVv();
	void colisionNaPa();
	void colisionNaDi();
	void colisionNaDo();
};

CGame::CGame(){
	int auxy = rand() % 19 + 6;
	int auxx = rand() % 110;

	naveTerricola = new CNave(1,5,1,1,4,13);
	aveDodo = new CDodo(auxx,auxy,0,1,4,8);
	
	for (int i = 0; i < 4; i++){
		auxy = rand() % 20 + 5;
		if (i == 0 || i == 1) {
			listaAveDido.push_back(new CDido(1, auxy, 1, 0, 2, 3));
		}else {
			listaAveDido.push_back(new CDido(116, auxy, 1, 0, 2, 3));
		}
	}
	for (int i = 0; i < 6; i++){
		auxy = rand() % 19 + 5;
		auxx = rand() % 115;
		listaParticulaO2.push_back(new CParticulaO2(auxx, auxy, 0,0,1,1));
	}
	int aux = rand() % 4 + 2;
	for (int i = 0; i < aux; i++){
		auxy = rand() % 19 + 5;
		auxx = rand() % 115;
		listaVidaVegetal.push_back(new CVidaVegetal(auxx, auxy, 0, 0, 2, 5));
	}

	vidas = 3;
	progresoPM = 0;
	progresoVA = 0;
	progresoVV = 0;
}

CGame::~CGame()
{
}

void CGame::inciar() {
	bool end = false;
	Console::SetCursorPosition(15, 0); cout << "Vida Animal: " << progresoVA << "/1     Vida Vegetal: " << progresoVV << "/1"; //5
	Console::SetCursorPosition(15, 1); cout << "Particulas Marcianas O2: " << progresoPM << "/6                   VIDAS: " << vidas << "/3";

	while (!end) {
		naveTerricola->dibujar();
		Console::SetCursorPosition(15, 0); cout << "Vida Animal: " << progresoVA << "/1     Vida Vegetal: " << progresoVV << "/1"; //5
		Console::SetCursorPosition(15, 1); cout << "Particulas Marcianas O2: " << progresoPM << "/6                   VIDAS: " << vidas << "/3";
		imrpimirTodoAveDido();
		imprimirTodoRecoleccion();
		naveTerricola->mover();
		aveDodo->mover();
		colisionNaDi();
		colisionNaPa();
		colisionNaVv();
		colisionNaDo();
		if (vidas == 0) break;
		if (progresoPM == 6 && progresoVA == 1 && progresoVV == 1) end = true;
		_sleep(20);
	}
	system("cls");
	if (end == false) {
		Console::SetCursorPosition(15, 15); cout << "You Louse";
	}
	else {
		Console::SetCursorPosition(15, 15); cout << "You Win";
	}

	_sleep(500);
}

void CGame::imprimirTodoRecoleccion(){
	for (int i = 0; i < listaParticulaO2.size(); i++) {
		if(listaParticulaO2[i]->getEstado() == false) listaParticulaO2[i]->dibujar();
	}
	for (int i = 0; i < listaVidaVegetal.size(); i++) {
		listaVidaVegetal[i]->dibujar();
	}
}

void CGame::imrpimirTodoAveDido(){
	for (int i = 0; i < listaAveDido.size(); i++){
		listaAveDido[i]->mover();
	}
}

void CGame::colisionNaVv(){
	for (int k = 0; k < listaVidaVegetal.size(); k++) {
		for (int i = 0; i < naveTerricola->getheight(); i++) {
			for (int j = 0; j < naveTerricola->getwidth(); j++) {
				if (naveTerricola->getposx() + j == listaVidaVegetal[k]->getposx() && naveTerricola->getposy() + i == listaVidaVegetal[k]->getposy() ||
					naveTerricola->getposx() + j == listaVidaVegetal[k]->getposx() + listaVidaVegetal[k]->getwidth() && naveTerricola->getposy() + i == listaVidaVegetal[k]->getposy() + listaVidaVegetal[k]->getheight()) {
					progresoVV = 1;
					break;
				}
			}
		}
	}
}

void CGame::colisionNaPa(){
	for (int k = 0; k < listaParticulaO2.size(); k++) {
		if(listaParticulaO2[k]->getEstado() == false){
			for (int i = 0; i < naveTerricola->getheight(); i++) {
				for (int j = 0; j < naveTerricola->getwidth(); j++) {
					if (naveTerricola->getposx() + j == listaParticulaO2[k]->getposx() && naveTerricola->getposy() + i == listaParticulaO2[k]->getposy() ||
						naveTerricola->getposx() + j == listaParticulaO2[k]->getposx() + listaParticulaO2[k]->getwidth() && naveTerricola->getposy() + i == listaParticulaO2[k]->getposy() + listaParticulaO2[k]->getheight()) {
						++progresoPM;
						listaParticulaO2[k]->setEstado(true);
						break;
					}
				}
			}
		}
	}
}

void CGame::colisionNaDi(){
	if (progresoVA == 0) {
		for (int i = 0; i < listaAveDido.size(); i++) {
			for (int j = 0; j < listaAveDido[i]->getheight(); j++) {
				for (int k = 0; k < listaAveDido[i]->getwidth(); k++) {
					if ((naveTerricola->getposx() == listaAveDido[i]->getposx() + k && naveTerricola->getposy() == listaAveDido[i]->getposy() + j) || //horizontal
						(naveTerricola->getposx() + 12 == listaAveDido[i]->getposx() + k && naveTerricola->getposy() == listaAveDido[i]->getposy() + j) ||
						(naveTerricola->getposx() + 6 == listaAveDido[i]->getposx() + k && naveTerricola->getposy() == listaAveDido[i]->getposy() + j) ||
						(naveTerricola->getposx() == listaAveDido[i]->getposx() + k && naveTerricola->getposy() + 1 == listaAveDido[i]->getposy() + j) || //vertical
						(naveTerricola->getposx() + 12 == listaAveDido[i]->getposx() + k && naveTerricola->getposy() + 2 == listaAveDido[i]->getposy() + j) ||
						(naveTerricola->getposx() + 6 == listaAveDido[i]->getposx() + k && naveTerricola->getposy() + 3 == listaAveDido[i]->getposy() + j)) {
						progresoVA = 1;
						break;
					}
				}
			}
		}
	}
}

void CGame::colisionNaDo(){
	for (int i = 0; i < aveDodo->getheight(); i++) {
		for (int j = 0; j < aveDodo->getwidth(); j++) {
			if ((naveTerricola->getposx() == aveDodo->getposx() + j && naveTerricola->getposy() == aveDodo->getposy() + i) || //horizontal
				(naveTerricola->getposx() + 12 == aveDodo->getposx() + j && naveTerricola->getposy() == aveDodo->getposy() + i) ||
				(naveTerricola->getposx() + 6 == aveDodo->getposx() + j && naveTerricola->getposy() == aveDodo->getposy() + i) ||
				(naveTerricola->getposx() == aveDodo->getposx() + j && naveTerricola->getposy() + 1 == aveDodo->getposy() + i) || //vertical
				(naveTerricola->getposx() + 12 == aveDodo->getposx() + j && naveTerricola->getposy() + 2 == aveDodo->getposy() + i) ||
				(naveTerricola->getposx() + 6 == aveDodo->getposx() + j && naveTerricola->getposy() + 3 == aveDodo->getposy() + i)) {
				naveTerricola->borrar();
				int aux_x = rand() % 110;
				int aux_y = rand() % 20 + 6;
				naveTerricola->setposx(aux_x);
				naveTerricola->setposy(aux_y);
				--vidas;
			}
		}
	}
}

