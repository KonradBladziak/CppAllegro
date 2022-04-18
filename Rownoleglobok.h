#pragma once
#include "Romb.h"
#include "Prostokat.h"

class Rownoleglobok :public Romb, public Prostokat
{
public:
	Rownoleglobok();
	Rownoleglobok(Punkt p1, Punkt p2, Punkt p3);
	double pole() override;
	double obwod() override;
};

