#pragma once
#include "Kwadrat.h"
class Prostokat : virtual public Kwadrat
{
protected:
	float dlugoscBokuB;
public:
	Prostokat();
	Prostokat(Punkt p1, Punkt p2, float bokB);
	Prostokat(Punkt p1, Punkt p2, float bokB, Ekran e);
	void setAll(Punkt p1, Punkt p3);
	double pole() override;
	double obwod() override;


};

