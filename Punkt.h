#pragma once 
#include "Ekran.h"

class Punkt {

private:
	int kx;
	int ky;
	Ekran ekran;

public:

	Punkt(int kx, int ky);
	Punkt(int kx, int ky, Ekran e);
	Punkt();
	Punkt(Ekran e);
	int getX();
	int getY();
	void setxy(int kx, int ky);
	void przesun(int vx,int vy);
	double odleglosc(Punkt b);

	void setRozdzielczosc(int w, int h);
	void setEkran(Ekran e);
	Ekran getEkran();






};

