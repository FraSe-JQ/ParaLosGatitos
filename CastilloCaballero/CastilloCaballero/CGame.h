#pragma once
#include "CEnemigo.h"
#include "CCastillo.h"
#include "CCaballero.h"

class CGame{
private:
	vector <CEnemigo*> listaEnemigos;
	CCastillo* castillo;
	CCaballero* caballero;

	int vidas;
	int progreso;

public:
	CGame();
	~CGame();

	void iniciar();
	void moverTodosEnemigos();
	void getInfo();

	void manejarColisiones();
	bool dinamica1espacio(); // (ya me canse xd) la logica deberia ser parecido a las colisiones de abajo, pero aumentale +1 al largo y ancho.
	//tambien agregarle como un indicador(puedes utilizar cualquier cosa que indique verdadero o falso) y en el kbhit del movimiento del caballero
	//pones un if en la tela 'P' con el indicador y ya deberia quedar no? (suerte pa :D) 
	bool colisionEnPro();
	bool colisionCasEn();

};

CGame::CGame(){
	castillo = new CCastillo(60, 5);
	caballero = new CCaballero(2, 16, 1, 1, 3, 3);
	for (int i = 0; i < 5; i++){
		listaEnemigos.push_back(new CEnemigo((i*25)+10, 26, 1, 1, 3, 3));
	}
	vidas = 3;
	progreso = 0;
}

CGame::~CGame()
{
}

void CGame::iniciar(){
	bool end = false;
	caballero->dibujar();
	while (!end){
		castillo->dibujar();
		caballero->mover();
		moverTodosEnemigos();
		manejarColisiones();
		if (vidas == 0) break;
		if (progreso == 5 || vidas + progreso >= 6) end = true; 
	}
	system("cls");
	if (end) {
		Console::SetCursorPosition(50, 15); cout << "YOU WIN";
	} else {
		Console::SetCursorPosition(50, 15); cout << "YOU LOUSE";
	}
}

void CGame::moverTodosEnemigos(){
	for (int i = 0; i < listaEnemigos.size(); i++){
		if(!listaEnemigos[i]->getAtrapado())listaEnemigos[i]->mover(castillo->getPosX(), castillo->getPosY());
	}
}

void CGame::getInfo(){
	Console::SetCursorPosition(80, 0); cout << "Progreso: " << progreso << "/5 || Vidas: " << vidas << "/3";
}

void CGame::manejarColisiones(){
	if (colisionCasEn()) --vidas;
	if (colisionEnPro())++progreso;
	getInfo();
}

bool CGame::colisionEnPro(){
	for (int i = 0; i < listaEnemigos.size(); i++) {
		if (listaEnemigos[i]->getAtrapado() == false && listaEnemigos[i]->getCastillo() == false) {
			for (int j = 0; j < caballero->getTamVecProyectiles(); j++) {
				if (caballero->getColisionProyectiles(j) == false || caballero->getEstadoProyectiles(j) == false) {
					for (int k = 0; k < listaEnemigos[i]->getLargo(); k++){
						for (int l = 0; l < listaEnemigos[i]->getAncho(); l++){
							if (listaEnemigos[i]->getPosX() + l == caballero->getPosxProyectiles(j) && listaEnemigos[i]->getPosY() + k == caballero->getPosyProyectiles(j)) {
								caballero->setColisioProyectiles(j, true);
								listaEnemigos[i]->setAtrapado(true);
								listaEnemigos[i]->borrar();
								return true;
							}
						}
					}
				}
			}
		}
	}
	
	return false;
}

bool CGame::colisionCasEn(){
	for (int i = 0; i < listaEnemigos.size(); i++){
		if (listaEnemigos[i]->getAtrapado() == false && listaEnemigos[i]->getCastillo() == false) {
			for (int j = 0; j < castillo->getLargo(); j++) {
				for (int k = 0; k < castillo->getAncho(); k++) {
					if (castillo->getPosX() + k == listaEnemigos[i]->getPosX() && castillo->getPosY() + j == listaEnemigos[i]->getPosY()) {
						listaEnemigos[i]->setCastillo(true);
						return true;
					}
				}
			}
		}
	}
	return false;
}
