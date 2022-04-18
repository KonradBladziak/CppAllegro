#pragma once
#include "Kwadrat.h"
class Romb :virtual public Kwadrat
{
private:
	float e;
	float f;
public:
	Romb();
	Romb(Punkt p1, Punkt p3, float f);
	double pole() override;
	double obwod() override;

};

