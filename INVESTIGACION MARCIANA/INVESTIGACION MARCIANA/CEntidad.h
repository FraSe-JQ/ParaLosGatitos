#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace System;
using namespace std;

class CEntidad{
protected:
	int posx,
		posy,
		spex,
		spey,
		height,
		width;
public:
	CEntidad(int posx, int posy, int spex, int spey, int height, int width);
	~CEntidad();

	
	int getposx();
	int	getposy();
	int	getspex();
	int	getspey();
	int	getheight();
	int	getwidth();

	void setposx(int px);
	void setposy(int py);
	void setspex(int vx);
	void setspey(int vy);
	void setheight(int he);
	void setwidth(int wi);

	virtual void mover();
	virtual void borrar();
};

CEntidad::CEntidad(int posx, int posy, int spex, int spey, int height, int width){
	this->posx = posx;
	this->posy = posy;
	this->spex = spex;
	this->spey = spey;
	this->height = height;
	this->width = width;
}

CEntidad::~CEntidad()
{
}

void CEntidad::mover()
{
}

void CEntidad::borrar(){
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++) {
			Console::SetCursorPosition(posx + j, posy + i); cout << " ";
		}
	}
}

int CEntidad::getposx() { return posx; }
int	CEntidad::getposy() { return posy; }
int	CEntidad::getspex() { return spex; }
int	CEntidad::getspey() { return spey; }
int	CEntidad::getheight() { return height; }
int	CEntidad::getwidth() { return width; }

void CEntidad::setposx(int px) { this->posx = px; }
void CEntidad::setposy(int py) { this->posy = py; }
void CEntidad::setspex(int vx) { this->spex = vx; }
void CEntidad::setspey(int vy) { this->spey = spey; }
void CEntidad::setheight(int he) { this->height = height; }
void CEntidad::setwidth(int wi) { this->width = width; }
