#include "Trojkat.h"
#include <cmath> 
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
using namespace std;



Trojkat::Trojkat() {
	p2 = Punkt();
	p3 = Punkt();
}

Trojkat::Trojkat(Punkt p1, Punkt p2, Punkt p3) {

		punkt =p1;
		this->p2 = p2;
		this->p3 = p3;
}


void Trojkat::setBgColor(ALLEGRO_COLOR bgc) {
	s_bgColor = bgc;
}

void Trojkat::setColor(ALLEGRO_COLOR c) {
	m_color = c;
}

void Trojkat::setFilled(bool f) {
	isFilled = f;
}

void Trojkat::setThickness(int t) {
	thickness = t;
}


void Trojkat::Punkty(Punkt p1, Punkt p2, Punkt p3)
{
		punkt = p1;
		this->p2 = p2;
		this->p3 = p3;
	
}


double Trojkat::pole()
{
	double pole = (abs(((double)p2.getX() - (double)punkt.getX()) * ((double)p3.getY() - (double)punkt.getY()) - ((double)p2.getY() - (double)punkt.getY()) * ((double)p3.getX() - (double)punkt.getX()))) / 2;
	
	
	return pole;
}

double Trojkat::odleglosc(Punkt A, Punkt B)
{
	double od = sqrt(pow((double)A.getX() - (double)B.getX(), 2)+ pow((double)A.getY() - (double)B.getY(), 2));

	return od;
}

double Trojkat::dlugoscBoku(int numerBoku) {
	if (numerBoku == 0) {
		return odleglosc(punkt, p2);
	}
	if (numerBoku == 1){
		return odleglosc(p2, p3);
	}
	if (numerBoku == 2){
		return odleglosc(p3,punkt);
	}
	return -1;
}

double Trojkat::obwod()
{
	double ob = odleglosc(punkt, p2) + odleglosc(p2, p3) + odleglosc(punkt, p3);

	return ob ;
}

void Trojkat::typtrojkata()
{
	double A = odleglosc(punkt, p2);
	double B = odleglosc(p2, p3);
	double C = odleglosc(punkt, p3);

	cout << A << B << C << endl;


	if (A == B && A == C) {

		cout << "Rownoboczny" << endl;

	}

	if (A == B || A == C || B == C) {

		cout << "Rownoramienny" << endl;

	}
	//TODO - niedok?adny sposób, do naprawy
	int a = ceil(pow(A, 2));
	int b = ceil(pow(B, 2));
	int c = ceil(pow(C, 2));
	if ((a==(b+c))||(b==(a+c))||(c==(a+b))) {
	
		cout << "Prostokatny " << endl;

	}

}

void Trojkat::przesun(int vx, int vy) {
	this->punkt.przesun(vx, vy);
	this->p2.przesun(vx, vy);
	this->p3.przesun(vx, vy);
}

void Trojkat::setRozdzielczosc(int h, int w) {
	this->punkt.setRozdzielczosc(w, h);
	this->p2.setRozdzielczosc(w, h);
	this->p3.setRozdzielczosc(w, h);
}

// figura -> czyBlizszy(trojkat, srodek)

// zwraca true, jesli drugi jest blizej
// zwraca false, jesli this jest blizej
bool Trojkat::czyBlizszy(Trojkat* drugi, Punkt p) {
	int odl = p.getEkran().getSzerokosc();
	if (odl > odleglosc(this->punkt, p)) {
		odl = odleglosc(this->punkt, p);
	}
	if (odl > odleglosc(this->p2, p)) {
		odl = odleglosc(this->p2, p);
	}
	if (odl > odleglosc(this->p3, p)) {
		odl = odleglosc(this->p3, p);
	}
	bool wynik = false;
	// odl - odleglosc od najblizszego punktu naszego trojkata do 'srodka'

	if (odl > odleglosc(drugi->punkt, p)) {
		wynik = true;
	}
	else if (odl > odleglosc(drugi->p2, p)) {
		wynik = true;
	}
	else if (odl > odleglosc(drugi->p3, p)) {
		wynik = true;
	}

	return wynik;


}


void Trojkat::show() {
	if (isShown) return;
	if (isFilled) {
		al_draw_filled_triangle(punkt.getX(), punkt.getY(),
			p2.getX(), p2.getY(),
			p3.getX(), p3.getY(),
			m_color);
	}
	else {
		al_draw_triangle(punkt.getX(), punkt.getY(),
			p2.getX(), p2.getY(),
			p3.getX(), p3.getY(),
			m_color, thickness);
	}
	isShown = true;
	al_flip_display();
}

void Trojkat::hide() {
	al_draw_filled_triangle(punkt.getX(), punkt.getY(),
		p2.getX(), p2.getY(),
		p3.getX(), p3.getY(),
		s_bgColor);
		al_flip_display();
}

