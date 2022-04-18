#include "Kwadrat.h"
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define pi 3.1415

Kwadrat::Kwadrat() {
	p2 = Punkt();
	p3 = Punkt();
	p4 = Punkt();
}

Kwadrat::Kwadrat(Punkt p1, float bok, float kat):Figura(p1) {
	//y=sin alfa * b
	//x = cosalfa * b
	wierzcholki = new float[8];
	float temp[8];
	float s45 = 45 * pi / 180;
	float prz = sqrt(2)*bok;

	int x = abs(p1.getX() - cos(kat)*bok);
	int y = abs(p1.getY() - sin(kat)*bok);
	p2 = Punkt(x,y);

	x = abs(p1.getX() - cos(kat + s45)*prz);
	 y = abs(p1.getY() - sin(kat + s45)*prz);


	p3 = Punkt(x, y);

	 x = abs(p1.getX() - cos(kat + 2*s45)*bok);
	 y = abs(p1.getY() - sin(kat + 2*s45)*bok);
	 ustawWierzcholki();

	p4 = Punkt(x, y);

	ustawWierzcholki();
}

Kwadrat::Kwadrat(Punkt p1, float bok, float kat, Ekran e) {
	punkt=p1;
	wierzcholki = new float[8];
	float temp[8];
	float s45 = 45 * pi / 180;
	float prz = sqrt(2)*bok;

	int x = abs(p1.getX() - cos(kat)*bok);
	int y = abs(p1.getY() - sin(kat)*bok);

	p2 = Punkt(x, y);

	x = abs(p1.getX() - cos(kat + s45)*prz);
	y = abs(p1.getY() - sin(kat + s45)*prz);

	p3 = Punkt(x, y);

	x = abs(p1.getX() - cos(kat + 2 * s45)*bok);
	y = abs(p1.getY() - sin(kat + 2 * s45)*bok);

	p4 = Punkt(x, y);

	ustawWierzcholki();
}


void Kwadrat::setAll(Punkt p1, float bok, float kat) {

	hide();
	punkt = p1;
	wierzcholki = new float[8];
	float temp[8];
	float s45 = 45 * pi / 180;
	float prz = sqrt(2)*bok;

	int x = abs(p1.getX() - cos(kat)*bok);
	int y = abs(p1.getY() - sin(kat)*bok);
	p2 = Punkt(x, y);

	x = abs(p1.getX() - cos(kat + s45)*prz);
	y = abs(p1.getY() - sin(kat + s45)*prz);
	
	p3 = Punkt(x, y);

	x = abs(p1.getX() - cos(kat + 2 * s45)*bok);
	y = abs(p1.getY() - sin(kat + 2 * s45)*bok);

	p4 = Punkt(x, y);
	ustawWierzcholki();
	show();
}

void Kwadrat::setBgColor(ALLEGRO_COLOR bgc) {
	s_bgColor = bgc;
}

void Kwadrat::setColor(ALLEGRO_COLOR c) {
	m_color = c;
}

void Kwadrat::setFilled(bool f) {
	isFilled = f;
}

void Kwadrat::setThickness(int t) {
	thickness = t;
}

void Kwadrat::ustawWierzcholki() {
	wierzcholki[0] = punkt.getX();
	wierzcholki[1] = punkt.getY();
	wierzcholki[2] = p4.getX();
	wierzcholki[3] = p4.getY();
	wierzcholki[4] = p3.getX();
	wierzcholki[5] = p3.getY();
	wierzcholki[6] = p2.getX();
	wierzcholki[7] = p2.getY();
}

void Kwadrat::przesun(int vx, int vy) {
	hide();
	this->punkt.przesun(vx, vy);
	this->p2.przesun(vx, vy);
	this->p3.przesun(vx, vy);
	this->p4.przesun(vx, vy);
	ustawWierzcholki();
	show();
}


double Kwadrat::pole() {
	return dlugoscBoku * dlugoscBoku;
}

double Kwadrat::obwod() {
	return 4 * dlugoscBoku;
}

void Kwadrat::show() {
	if (isShown) return;
	if (isFilled) {
		al_draw_filled_polygon(wierzcholki, 4, m_color);
	}
	else {
		al_draw_polygon(wierzcholki, 4, ALLEGRO_LINE_JOIN_BEVEL, m_color, thickness, 10);
	}
	isShown = true;
	al_flip_display();
}

void Kwadrat::hide() {
	al_draw_filled_polygon(wierzcholki, 4, s_bgColor);
	al_flip_display();
	isShown = false;
}

void Kwadrat::setPunkt(Punkt p1) {
	punkt = p1;
}