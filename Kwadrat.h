#pragma once
#include "Punkt.h"
#include "Figura.h"
#include <cmath>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


class Kwadrat:public Figura {

protected:
	ALLEGRO_COLOR s_bgColor;
	ALLEGRO_COLOR m_color;
	bool isShown = false;
	bool isFilled = false;
	Punkt p2;
	Punkt p3;
	Punkt p4;
	float dlugoscBoku;
	float kat;

	float* wierzcholki;

	int thickness;

public:

	Kwadrat();
	Kwadrat(Punkt p1, float bok, float kat);
	Kwadrat(Punkt p1, float bok, float kat, Ekran e);

	void setAll(Punkt p1, float bok, float kat);
	void setBgColor(ALLEGRO_COLOR bgc)override;
	void setColor(ALLEGRO_COLOR c)override;
	void setThickness(int t)override;
	void setFilled(bool f)override;
	void przesun(int vx, int vy);
	void ustawWierzcholki();
	double pole() override;
	double obwod() override;
	void setPunkt(Punkt p1);
	void show();
	void hide();


};