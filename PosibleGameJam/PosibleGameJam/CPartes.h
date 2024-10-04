#pragma once
#include <iostream>

using namespace std;
using namespace System;

class CPartes{
private:
	int x,
		y,
		vx,
		vy,
		largo,
		ancho,
		forma;
	int posx;
	int posy;
public:
	CPartes(int x, int y, int vx, int vy, int largo, int ancho, int forma, int posx, int posy);
	~CPartes();

	void dibujar();
	void borrar();
	void mover();
};

CPartes::CPartes(int x, int y, int vx, int vy, int largo, int ancho, int forma, int posx, int posy){
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
	this->largo = largo;
	this->ancho = ancho;
	this->forma = forma;
	this->posx = posx;
	this->posy = posy;
}

CPartes::~CPartes(){
}

void CPartes::dibujar(){
	switch (forma){
	case 1:
		Console::SetCursorPosition(x, y);   cout << "      *      ";
		Console::SetCursorPosition(x, y+1); cout << "     / \\     ";
		Console::SetCursorPosition(x, y+2); cout << "    /   \\    ";
		Console::SetCursorPosition(x, y+3); cout << "   /     \\   ";
		Console::SetCursorPosition(x, y+4); cout << "  /       \\  ";
		Console::SetCursorPosition(x, y+5); cout << "  ---------  ";
		break;
	case 2:
		Console::SetCursorPosition(x, y);   cout << "-------------";
		Console::SetCursorPosition(x, y+1); cout << "|           |";
		Console::SetCursorPosition(x, y+2); cout << "|           |";
		Console::SetCursorPosition(x, y+3); cout << "|           |";
		Console::SetCursorPosition(x, y+4); cout << "|           |";
		Console::SetCursorPosition(x, y+5); cout << "-------------";
		break;
	case 3:
		Console::SetCursorPosition(x, y);   cout << "--------";
		Console::SetCursorPosition(x, y+1); cout << "|      |";
		Console::SetCursorPosition(x, y+2); cout << "|      |";
		Console::SetCursorPosition(x, y+3); cout << "|      |";
		Console::SetCursorPosition(x, y+4); cout << "--------";
		break;
	default:
		break;
	}
}

void CPartes::borrar(){
	for (int i = 0; i < largo; i++){
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x+j, y+i); cout << " ";
		}
	}
}

void CPartes::mover(){
	borrar();
	switch (forma){
	case 1:
		if (x < posx) x += vx;
		if (x > posx) x -= vx;
		if (y < posy) y += vy;
		if (y > posy) y += vy;
		break;
	case 2:
		if (x < posx) x += vx;
		if (x > posx) x -= vx;
		if (y < posy+5) y += vy;
		if (y > posy+5) y += vy;
		break;
	case 3:
		if (x < posx+3) x += vx;
		if (x > posx+3) x -= vx;
		if (y < posy+6) y += vy;
		if (y > posy+6) y += vy;
		break;
	}
	dibujar();
}
