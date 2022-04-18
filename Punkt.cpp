#include "Punkt.h"
#include "Ekran.h"
#include <cmath> 

Punkt::Punkt(){
	Ekran *e = new Ekran();
	this->ekran = *e;
	kx = this->ekran.getSzerokosc() / 2;
	ky = this->ekran.getWysokosc() / 2;
}

Punkt::Punkt(Ekran e) {
	this->ekran = e;
	kx = this->ekran.getSzerokosc() / 2;
	ky = this->ekran.getWysokosc() / 2;
}

Punkt::Punkt(int kx, int ky)
{
	if (this->ekran.isOnScreen(kx, ky)) {
		this->kx = kx;
		this->ky = ky;
	}
	else{
		this->kx = this->ekran.getSzerokosc() / 2;
		this->ky = this->ekran.getWysokosc() / 2;
	}
}

Punkt::Punkt(int kx, int ky, Ekran e)
{
	this->ekran = e;
	if (this->ekran.isOnScreen(kx, ky)) {
		this->kx = kx;
		this->ky = ky;
	}
	else {
		this->kx = ekran.getSzerokosc() / 2;
		this->ky = ekran.getWysokosc() / 2;
	}
}


int Punkt::getX()
{
	return this->kx;
}

int Punkt::getY()
{
	return this->ky;
}

void Punkt::setxy(int kx, int ky)
{

	if (this->ekran.isOnScreen(kx, ky)) {
		this->kx = kx;
		this->ky = ky;
	}
	else {
		this->kx = this->ekran.getSzerokosc() / 2;
		this->ky = this->ekran.getWysokosc() / 2;
	}
}

void Punkt::przesun(int vx,int vy)
{
	if (this->ekran.isOnScreen(kx+vx, ky+vy)) {
		this->kx = kx + vx;
		this->ky = ky + vy;
	}

}


void Punkt::setRozdzielczosc(int x, int y)
{
	this->ekran.setAll(x, y);
	if (!this->ekran.isOnScreen(kx,ky)) {
		this->kx =ekran.getSzerokosc()/2;
		this->ky = ekran.getWysokosc() / 2;
	}
}

void Punkt::setEkran(Ekran e)
{
	this->ekran = e;
}

Ekran Punkt::getEkran()
{
	return this->ekran;
}

double Punkt::odleglosc(Punkt B)
{
	double od = sqrt(pow((double)kx - (double)B.getX(), 2) + pow((double)ky - (double)B.getY(), 2));

	return od;
}
