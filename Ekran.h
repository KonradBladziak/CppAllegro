#pragma once
class Ekran
{
private:
	int wysokosc;
	int szerokosc;
public:
	Ekran();
	Ekran(int w, int h);
	void setWysokosc(int w);
	int getWysokosc();
	void setSzerokosc(int w);
	int getSzerokosc();

	void setAll(int w, int h);
	bool isOnScreen(int x, int y);


};

