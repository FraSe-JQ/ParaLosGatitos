#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;
using namespace System;

void inicializarMatriz(int** matriz, int largo, int ancho, int cant);
void refrescarMatriz(int** matriz, int largo, int ancho, int& cont);
void imprimirMatriz(int** matriz, int largo, int ancho);
bool verificarMatriz(int** matriz, int largo, int ancho);

int main() {
	srand(time(0));
	int largo = 6;
	int ancho = 10;
	int cantidadIncial = 7;
	int contador = 0;
	int** matriz = new int* [largo];
	for (int i = 0; i < largo; i++){
		matriz[i] = new int[ancho];
	}
	inicializarMatriz(matriz, largo, ancho, cantidadIncial);
	imprimirMatriz(matriz, largo, ancho);
	_getch();
	while (true){
		Console::SetCursorPosition(0, 0); cout << "Avances: " << contador;
		refrescarMatriz(matriz, largo, ancho, contador);
		imprimirMatriz(matriz, largo, ancho);
		if (verificarMatriz(matriz, largo, ancho)) break;
		_sleep(1000);
	}

	for (int i = 0; i < largo; i++){
		delete[] matriz[i];
	}
	delete[] matriz;

	_getch();
	return EXIT_SUCCESS;
}

void inicializarMatriz(int** matriz, int largo, int ancho, int cant) {
	for (int i = 0; i < largo; i++) {
		for (int j = 0; j < ancho; j++) {
			matriz[i][j] = 0;
		}
	}

	for (int i = 0; i < cant; i++){
		int aux;
		int aux1;
		do{
			aux = rand() % largo;
			aux1 = rand() % ancho;
		} while (matriz[aux][aux1] == 1);

		matriz[aux][aux1] = 1;
	}
}

void refrescarMatriz(int** matriz, int largo, int ancho, int& cont){
	for (int i = 0; i < largo; i++){
		for (int j = 0; j < ancho; j++) {
			if (matriz[i][j] == 1 && matriz[i][j-1] == 0) {
				matriz[i][j] = 0;
				matriz[i][j-1] = 1;
				++cont;
			}
		}
	}

	for (int i = 0; i < largo; i++){
		if (matriz[i][0] == 1) {
			matriz[i][0] = 0;
			++cont;
		}
	}
}

void imprimirMatriz(int** matriz, int largo, int ancho){
	for (int i = 0; i < largo; i++){
		for (int j = 0; j < ancho; j++) {
			int aux = matriz[i][j];
			Console::SetCursorPosition(j+5, i+5); cout << aux;
		}
	}
}

bool verificarMatriz(int** matriz, int largo, int ancho){
	for (int i = 0; i < largo; i++){
		for (int j = 0; j < ancho; j++) {
			if (matriz[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}
