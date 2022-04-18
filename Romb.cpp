#include "Romb.h"

Romb::Romb() {
	//TODO 
}

Romb::Romb(Punkt p1, Punkt p3, float f) {
	setPunkt(p1);
	this->p3 = p3;
	float e = p1.odleglosc(p3);
	wierzcholki = new float[8];

	Punkt s = Punkt(p1.getX() + (p3.getX() - p1.getX() / 2), p1.getY() + (p3.getY() - p1.getY() / 2));
	double sinalfa = (abs(s.getX() - p1.getX())) / (f / 2);
	double alfa1 = asin(sinalfa);
	double c = sqrt(pow(f / 2, 2) + pow(e / 2, 2));
	double sinbeta = (f / 2) / c;
	double beta = asin(sinbeta);
	dlugoscBoku = c;
	double alfa = alfa1 - beta;
	this->f = f;
	this->e = e;
	int x = abs(p1.getX() - cos(alfa)*c);
	int y = abs(p1.getY() - sin(alfa)*c);
	p3 = Punkt(x, y);

	alfa += 2 * beta;

	x = abs(p1.getX() - cos(alfa)*c);
	y = abs(p1.getY() - sin(alfa)*c);
	p4 = Punkt(x, y);

	ustawWierzcholki();

}

double Romb::pole() {
	return e * f;
}

double Romb::obwod() {
	return 4* dlugoscBoku;
}