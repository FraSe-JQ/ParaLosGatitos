#pragma once
#include <iostream>

using namespace std;
using namespace System;

class CEntidad {
protected:
	int posx,
		posy,
		ancho,
		largo,
		velx,
		vely,
		forma;
public:
	CEntidad(int posx, int posy, int ancho, int largo, int velx, int vely, int forma);
	~CEntidad();

	int getPosx();
	int getPosy();
	int getVelx();
	int getVely();
	int getLargo();
	int getAncho();
	int getForma();

	void setPosx(int x);
	void setPosy(int y);
	void setVelx(int vx);
	void setVely(int vy);
	void setLargo(int l);
	void setAncho(int a);
	void setForma(int f);


	virtual void borrar();
	virtual void dibujar();
};

CEntidad::CEntidad(int posx, int posy, int ancho, int largo, int velx, int vely, int forma){
	this->posx = posx;
	this->posy = posy;
	this->ancho = ancho;
	this->largo = largo;
	this->velx = velx;
	this->vely = vely;
	this->forma = forma;
}

CEntidad::~CEntidad(){

}

int CEntidad::getPosx(){
	return posx;
}

int CEntidad::getPosy()
{
	return posy;
}

int CEntidad::getVelx()
{
	return velx;
}

int CEntidad::getVely()
{
	return vely;
}

int CEntidad::getLargo()
{
	return largo;
}

int CEntidad::getAncho()
{
	return ancho;
}

int CEntidad::getForma()
{
	return forma;
}

void CEntidad::setPosx(int x){
	posx = x;
}

void CEntidad::setPosy(int y){
	posy = y;
}

void CEntidad::setVelx(int vx){
	velx = vx;
}

void CEntidad::setVely(int vy){
	vely = vy;
}

void CEntidad::setLargo(int l){
	largo = l;
}

void CEntidad::setAncho(int a){
	ancho = a;
}

void CEntidad::setForma(int f){
	forma = f;
}

void CEntidad::borrar(){
	for (int i = 0; i < largo; i++){
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(posx + j, posy + i); cout << " ";
		}
	}
}

void CEntidad::dibujar(){
	Console::SetCursorPosition(posx, posy); cout << (char)forma;
}
