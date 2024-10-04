#pragma once
#include "CArrObjRecolectar.h"
#include "CJugador.h"
#include "CArrNoJugable.h"

class CJuego{
private:
	CListaObjetos* listaRecolectar;
	CJugador* jugador;
	CListaNoJugable* listaEnemigos;

	int vidas;
	int progreso;
	int objRecolectar;
public:
	CJuego(int vidas);
	~CJuego();

	void iniciar();
	void eventoColisiones();
	bool colisionJuEn(); //Colision Jugador Enemigo
	bool colisionJuObj(); //Colision Jugador Objetos
	bool verifiWinLose();
};

CJuego::CJuego(int vidas) {
	jugador = new CJugador(2, 15, 1, 1, 1, 1, 2);
	listaEnemigos = new CListaNoJugable();
	listaRecolectar = new CListaObjetos();
	this->vidas = vidas;
	progreso = 0;
	objRecolectar = rand() % 15 + 5;

	for (int i = 0; i < 3; i++) {
		int aux_forma = rand() % 4 + 1;
		listaEnemigos->agregarNoJugable(new CNoJugable(((i*35)+19), 1, -1, 1, aux_forma));
	}
	for (int i = 0; i < objRecolectar; i++){
		int aux_x = rand() % 109 + 10;
		int aux_y = rand() % 29 + 1;
		listaRecolectar->agregarObj(new CRecolectar(aux_x, aux_y));
	}
}

CJuego::~CJuego(){
	delete listaEnemigos;
	delete listaRecolectar;
	delete jugador;
}

 void CJuego::iniciar(){
	 bool end = false;
	 listaRecolectar->imprimirTodo();
	 jugador->dibujar();
	 Console::SetCursorPosition(0, 0);  cout << "Vidas: " << vidas;
	 Console::SetCursorPosition(0, 1);  cout << "Progreso: " << progreso << "/" << objRecolectar;
	 while (!end){
		 if (colisionJuEn() == true || colisionJuObj() == true) {
			 Console::SetCursorPosition(0, 0);  cout << "Vidas: " << vidas;
			 Console::SetCursorPosition(0, 1);  cout << "Progreso: " << progreso << "/" << objRecolectar;
		 }
		 jugador->mover();
		 listaEnemigos->moverTodo();
		 listaRecolectar->imprimirTodo();
		 if (vidas == 0 || progreso == objRecolectar) break;
	 }
	 if (verifiWinLose()) {
		 cout << "You WIN";
	 }else {
		 cout << "You LOUSE";
	 }
}

 void CJuego::eventoColisiones(){
	 if (colisionJuEn()) { --vidas; }
	 if (colisionJuObj()) { ++progreso; }
 }

 bool CJuego::colisionJuEn(){
	 for (int i = 0; i < listaEnemigos->getTamArr(); i++){
		 if (listaEnemigos->getFormaArr(i) == 4) {
			 jugador->dibujar();
		 }else {
			 for (int j = 0; j < listaEnemigos->getAnchoArr(i); j++) {
				 if (jugador->getPosx() == listaEnemigos->getPosxArr(i) + j && jugador->getPosy() == listaEnemigos->getPosyArr(i)) {
					 jugador->setPosx(3);
					 jugador->setPosy(15);
					 jugador->dibujar();
					 --vidas;
					 return true;
				 }
			 }
		 }
	 }
	 return false;
 }

 bool CJuego::colisionJuObj(){
	 for (int i = 0; i < listaRecolectar->getTamArr(); i++) {
		 if (listaRecolectar->getEstadoArr(i) == false) {
			 if (jugador->getPosx() == listaRecolectar->getPosxArr(i) && jugador->getPosy() == listaRecolectar->getPosyArr(i)) {
				 listaRecolectar->setEstadoArr(i, true);
				 jugador->dibujar();
				 ++progreso;
				 return true;
			 }
		 }
	 }
	 return false;
 }

 bool CJuego::verifiWinLose(){
	 int aux = 0;
	 for (int i = 0; i < listaRecolectar->getTamArr(); i++){
		 if (listaRecolectar->getEstadoArr(i) == true) {
			 ++aux;
		 }
	 }
	 if (aux == objRecolectar) {
		 return true;
	 }
	 return false;
 }
