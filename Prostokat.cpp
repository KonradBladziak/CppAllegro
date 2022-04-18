#include "Prostokat.h"
#define pi 3.1415

Prostokat::Prostokat() {
	//TODO
}

Prostokat::Prostokat(Punkt p1, Punkt p2, float bokB){
	setPunkt(p1);
	this->p2 = p2;
	float s45 = 45 * pi / 180;
	wierzcholki = new float[8];

	dlugoscBokuB = bokB;
	// cosalfa = b/c
	// sinalfa = a/c
	double a = p1.odleglosc(p2);
	dlugoscBoku = a;
	double c = sqrt(pow(a, 2) + pow(bokB, 2));
	double w = abs(p2.getX() - p1.getX());
	double h = abs(p2.getY() - p1.getY());
	double sinalfa = h / a;
	double cosalfa = w / a;
	double alfa1 = asin(sinalfa);
	double sinbeta = a / c;
	double beta = asin(sinbeta);

	double alfa =alfa1-beta;
	int x = abs(cos(alfa)*c - p1.getX());
	int y = abs(sin(alfa)*c -p1.getY());
	p3 = Punkt(x, y);
	alfa = alfa1 + 2*s45;
	x = abs(cos(alfa)*bokB- p1.getX() );
	y = abs( sin(alfa)*bokB- p1.getY());
	p4 = Punkt(x, y);
	ustawWierzcholki();

}

double Prostokat::pole() {
	return dlugoscBoku * dlugoscBokuB;
}

double Prostokat::obwod() {
	return (2* dlugoscBoku)+(2*dlugoscBokuB);
}