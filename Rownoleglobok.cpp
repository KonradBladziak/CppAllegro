#include "Rownoleglobok.h"


Rownoleglobok::Rownoleglobok(Punkt p1, Punkt p2, Punkt p3):Kwadrat(p1,0,0){
	Romb::p2 = p2;
	Romb::p3 = p3;

	int p4x = p1.getX()+p3.getX()- p2.getX();
	int p4y = p1.getY() + p3.getY() - p2.getY();
	Romb::p4 = Punkt(p4x, p4y);

	Prostokat::dlugoscBoku = p1.odleglosc(p2); // d?ugosc boku A
	Prostokat::dlugoscBokuB = p1.odleglosc(p4);


	wierzcholki = new float[8];
	Romb::ustawWierzcholki();
}
double Rownoleglobok::pole() {
	return Prostokat::pole();
}

double Rownoleglobok::obwod() {
	return Prostokat::obwod();
}