#pragma once
#include "Punkt.h"
#include "Ekran.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Figura
{
protected:
	Punkt punkt;
public:
	Figura();
	Figura(Punkt p) :punkt(p) {};
	virtual double pole() = 0;
	virtual double obwod()= 0;
	virtual void setBgColor(ALLEGRO_COLOR bgc)=0;
	virtual void setColor(ALLEGRO_COLOR c)=0;
	virtual void setThickness(int t)=0;
	virtual void setFilled(bool f)=0;
	virtual void show()=0;
	virtual void hide()=0;
};

