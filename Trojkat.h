#pragma once
#include "Punkt.h"
#include "Figura.h"
#include <cmath>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


class Trojkat:public Figura {

private:
	ALLEGRO_COLOR s_bgColor;
	ALLEGRO_COLOR m_color;
	bool isShown = false;
	bool isFilled = false;
	Punkt p2;
	Punkt p3;

	int thickness;

public:

	Trojkat();
	Trojkat(Punkt p1, Punkt p2, Punkt p3);

	void Punkty(Punkt p1, Punkt p2, Punkt p3);
	void setBgColor(ALLEGRO_COLOR bgc) override;
	void setColor(ALLEGRO_COLOR c)override;
	void setThickness(int t)override;
	void setFilled(bool f)override;
	double odleglosc(Punkt A, Punkt B);
	double pole() override;
	double obwod() override;
	void typtrojkata();
	void przesun(int vx, int vy);
	double dlugoscBoku(int numerBoku);
	void setRozdzielczosc(int h, int w);
	bool czyBlizszy(Trojkat* drugi, Punkt p);

	void show()override;
	void hide()override;


};

