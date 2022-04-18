#include "Ekran.h"
#include <iostream>
Ekran::Ekran()
{
	wysokosc = 480;
	szerokosc = 640;
}

Ekran::Ekran(int w, int h)
{
	wysokosc = h;
	szerokosc = w;
}

void Ekran::setWysokosc(int w)
{
	wysokosc = w;
}

int Ekran::getWysokosc()
{
	return wysokosc;
}

void Ekran::setSzerokosc(int w)
{
	szerokosc = w;
}

int Ekran::getSzerokosc()
{
	return szerokosc;
}

void Ekran::setAll(int w, int h)
{
	wysokosc = h;
	szerokosc = w;
}

bool Ekran::isOnScreen(int x, int y)
{
	if (x >szerokosc || x < 0 || y>wysokosc || y < 0) {
		std::cout << "PUNKT POZA EKRANEM"<<std::endl;
		return false;
	}
	else {
		return true;
	}
}
