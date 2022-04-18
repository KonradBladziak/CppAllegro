

#define ZadanieD

#ifdef ZadanieD
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>
#include <windows.h>

#include "Trojkat.h"
#include "Punkt.h"
#include "Kwadrat.h"
#include "Figura.h"
#include "Prostokat.h"
#include "Romb.h"
#include "Rownoleglobok.h"


using namespace std;

#define pi 3.1415
int main()
{
	
	Trojkat* figura = new Trojkat(Punkt(120, 50), Punkt(30, 16), Punkt(160, 30));
	Kwadrat* f2 = new Kwadrat(Punkt(400, 400), 80, 20);
	Kwadrat* p1 = new Prostokat(Punkt(0, 0), Punkt(100, 0), 150);

	Kwadrat* r1 = new Rownoleglobok(Punkt(150, 240), Punkt(320, 200), Punkt(430, 400));


	const float DISP_WIDTH = 640;
	const float DISP_HEIGHT = 480;
	figura->setRozdzielczosc(DISP_HEIGHT, DISP_WIDTH);

	if (!al_init()) {						
		fprintf(stderr, "Nie zainicjalizowano allegro!\n");
		return -1;
	}

	al_init_primitives_addon();

	ALLEGRO_DISPLAY* disp = al_create_display(DISP_WIDTH, DISP_HEIGHT);
	ALLEGRO_COLOR black1 = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR white = al_map_rgb(255, 0, 255);
	al_clear_to_color(black1);


	Figura** tablica = new Figura * [100];
	srand(time(NULL));
	int fig;
	int x, y;
	Punkt a, b, c;
	float bok, kat;
	int r, g, b1;
	int k;
	Figura* temp;
	for (int i = 0; i < 100; i++) {
		Sleep(100);
		fig = rand() % 5;
		tablica[i] = NULL;
		switch (fig) {
		case 0:
			x = rand() % (int)DISP_WIDTH;
			y = rand() % (int)DISP_HEIGHT;
			a = Punkt(x, y);
			x = rand() % (int)DISP_WIDTH;
			y = rand() % (int)DISP_HEIGHT;
			b = Punkt(x, y);
			x = rand() % (int)DISP_WIDTH;
			y = rand() % (int)DISP_HEIGHT;
			c = Punkt(x, y);
			tablica[i] = new Trojkat(a, b, c);
			break;
		case 1:
			k = rand() % 360;
			kat = k * pi / 180;
			bok = rand() % 200;
			x = rand() % (int)DISP_WIDTH;
			y = rand() % (int)DISP_HEIGHT;
			a = Punkt(x, y);
			tablica[i] = new Kwadrat(a, bok, kat);
			break;
		case 2:
			bok = rand() % 200; x = rand() % (int)DISP_WIDTH;
			y = rand() % (int)DISP_HEIGHT;
			a = Punkt(x, y);
			x = rand() % (int)DISP_WIDTH;
			y = rand() % (int)DISP_HEIGHT;
			b = Punkt(x, y);
			tablica[i] = new Prostokat(a, b, bok);
			break;
		case 3:
			bok = rand() % 200; x = rand() % (int)DISP_WIDTH;
			y = rand() % (int)DISP_HEIGHT;
			a = Punkt(x, y);
			x = rand() % (int)DISP_WIDTH;
			y = rand() % (int)DISP_HEIGHT;
			b = Punkt(x, y);
			tablica[i] = new Romb(a, b, bok);
			break;
		case 4:
			x = rand() % (int)DISP_WIDTH;
			y = rand() % (int)DISP_HEIGHT;
			a = Punkt(x, y);
			x = rand() % (int)DISP_WIDTH;
			y = rand() % (int)DISP_HEIGHT;
			b = Punkt(x, y);
			x = rand() % (int)DISP_WIDTH;
			y = rand() % (int)DISP_HEIGHT;
			c = Punkt(x, y);
			tablica[i] = new Rownoleglobok(a, b, c);
			break;
		}
		if (tablica[i] != NULL) {
			r = rand() % 255;
			g = rand() % 255;
			b1 = rand() % 255;
			white = al_map_rgb(r, g, b1);
			tablica[i]->setBgColor(black1);
			tablica[i]->setFilled(true);
			tablica[i]->setColor(white);
			tablica[i]->show();
		}
	}
	system("pause");
}
#endif

#ifdef ZadanieP
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;



enum class Studia { stacjonarne, niestacjonarne };
enum class Stopien { inzynierski, magisterski,doktorancki };
enum class StopienNaukowy { mgr, dr, dr_hab, prof};



class Katedra
{
protected:
	char m_nazwa[100] = "";
public:
	Katedra(const char* nazwa) { setNazwa(nazwa); }
	void setNazwa(const char* nazwa) { strncpy(m_nazwa, nazwa, 100); }
	const char* getNazwa() const { return m_nazwa; }
};

class Kierunek
{
protected:
	char m_nazwa[100] = "";
public:
	Kierunek(const char* nazwa) { setNazwa(nazwa); }
	void setNazwa(const char* nazwa) { strncpy(m_nazwa, nazwa, 100); }
	const char* getNazwa() const { return m_nazwa; }
};


class Osoba
{
protected:
	char m_imie[30] = "";
	char m_nazwisko[40] = "";
	int m_wiek = 18;
public:
	Osoba(const char* imie, const char* nazwisko, int wiek)
	{
		setImie(imie);
		setNazwisko(nazwisko);
		setWiek(wiek);
	}

	void setImie(const char* imie) { strncpy(m_imie, imie, 30); }
	void setNazwisko(const char* nazwisko) { strncpy(m_nazwisko, nazwisko, 40); }
	void setWiek(int wiek) { m_wiek = (wiek > 0) ? wiek : 0; }

	const char* getImie() const { return m_imie; }
	const char* getNazwisko() const { return m_nazwisko; }
	int getWiek() const { return m_wiek; }
};



class Student :public Osoba
{
protected:
	Kierunek* m_kierunek = nullptr;
	int m_semestr = 1;
	Studia m_rodzajStudiow = Studia::stacjonarne;
	Stopien m_stopien = Stopien::inzynierski;
public:
	Student(Osoba& kandydat, Kierunek* kierunek, int semestr, Studia rodzaj, Stopien stopien)
		: Osoba(kandydat), m_kierunek(kierunek), m_rodzajStudiow(rodzaj), m_stopien(stopien)
	{
		setSemestr(semestr);
	}
	void setKierunek(Kierunek* kierunek) { m_kierunek = kierunek; }
	void setSemestr(int semestr) { m_semestr = (semestr > 0 && semestr < 8) ? semestr : 1; }
	void setRodzajStudiow(Studia rodzaj) { m_rodzajStudiow = rodzaj; }
	void setStopien(Stopien stopien) { m_stopien = stopien; }

	Kierunek* getKierunek() const { return m_kierunek; }
	int getSemestr() const { return m_semestr; }
	Studia getRodzajStudiow() const { return m_rodzajStudiow; }
	Stopien getStopien() const { return m_stopien; }
};

class Pracownik : public Osoba
{
protected:
	int m_stazPracy = 0;
	Katedra* m_katedra = nullptr;
	StopienNaukowy m_stopien = StopienNaukowy::mgr;
public:
	
	
	Pracownik(Osoba& osoba, Katedra* katedra, StopienNaukowy stopien)
		:Osoba(osoba), m_katedra(katedra), m_stopien(stopien)
	{}

	void zwiekszStaz() { m_stazPracy++; }
	void setKatedra(Katedra* katedra) { m_katedra = katedra; }
	
	void setStopienNaukowy(StopienNaukowy stopien)
	{
		m_stopien = stopien;
	}

	
	int getStaz() const { return m_stazPracy; }
	Katedra* getKatedra() const { return m_katedra; }
	StopienNaukowy getStopienNaukowy() const { return m_stopien; }

	virtual int pensja() = 0;

};




class Doktorant final : public Pracownik, public Student
{

public:
	
	void setSemestr(int semestr)
	{ 
		
	Student:m_semestr = semestr;

	}

	int getSemestr() {
	
		return m_semestr;
	}

	void setStopienNaukowy(StopienNaukowy stopien)
	{

		//Student:m_stopien = stopien;

	}
	

	int pensja()override {

		if (getSemestr() > 2) {
		
			return 1500 + (200 * getSemestr() / 2);
		
		}

	}

};


class PracownikNaukowy : public Pracownik
{
protected:
	int m_liczbaPublikacji = 0;
public:
	PracownikNaukowy(Pracownik& pracownik)
		:Pracownik(pracownik)
	{}
	void zwiekszLiczbePublikacji() { m_liczbaPublikacji++; }
	int getLiczbaPublikacji() const { return m_liczbaPublikacji; }

	int pensja()override {
	
		int pensja = getLiczbaPublikacji() * 50 + (int)getStopienNaukowy();
		 
	}

};

class PracownikDydaktyczny : public Pracownik
{
protected:
	int m_liczbaPrzedmiotow = 0;
public:
	PracownikDydaktyczny(Pracownik& pracownik, int lp)
		: Pracownik(pracownik)
	{
		setLiczbaPrzedmiotow(lp);
	}
	void setLiczbaPrzedmiotow(int lp) { m_liczbaPrzedmiotow = (lp > 0) ? lp : 0; }
	int getLiczbePrzedmiotow() const { return m_liczbaPrzedmiotow; }

	int pensja()override {

		int pensja = getLiczbePrzedmiotow() * 100 + (int)getStopienNaukowy();

	}

};





int main()
{

	Kierunek* kierunekA = new Kierunek("Scisly");
	Kierunek* kierunekB = new Kierunek("Human");
	Kierunek* kierunekC = new Kierunek("McDonald");
	
	
	Katedra* uczelniaA = new Katedra(("Politechnika"));
	Katedra* uczelniaB = new Katedra(("Uniwersytet"));

	Osoba* OsobaA = new Osoba("Kostyriusz", "Matyriusz", 22);
	Osoba* OsobaB = new Osoba("Adam", "Matyriusz", 22);
	Osoba* OsobaC = new Osoba("Malysz", "Matyriusz", 23);
	Osoba* OsobaD = new Osoba("Metejko", "Matyriusz", 26);
	Osoba* OsobaE = new Osoba("Boleslaw", "Matyriusz", 24);
	Osoba* OsobaF = new Osoba("Kostyriusz", "Matyriusz", 22);
	Osoba* OsobaG = new Osoba("Kamil", "Matyriusz", 27);
	Osoba* OsobaH = new Osoba("Dominik", "Matyriusz", 22);
	Osoba* OsobaI = new Osoba("Kornel", "Matyriusz", 28);
	Osoba* OsobaJ = new Osoba("Dawid", "Matyriusz", 22);

	Student* StudentA = new Student(*OsobaA,kierunekA,1,Studia::stacjonarne,Stopien::inzynierski);
	Student* StudentB = new Student(*OsobaB,kierunekB,2,Studia::stacjonarne,Stopien::magisterski);
	Student* StudentC = new Student(*OsobaC,kierunekC,3,Studia::niestacjonarne,Stopien::inzynierski);
	Student* StudentD = new Student(*OsobaD,kierunekB,4,Studia::stacjonarne,Stopien::doktorancki);
	Student* StudentE = new Student(*OsobaE,kierunekC,5,Studia::niestacjonarne,Stopien::inzynierski);
	Student* StudentF = new Student(*OsobaF,kierunekA,6,Studia::stacjonarne,Stopien::doktorancki);
	Student* StudentG = new Student(*OsobaG,kierunekB,7,Studia::stacjonarne,Stopien::inzynierski);
	Student* StudentH = new Student(*OsobaH,kierunekC,3,Studia::niestacjonarne,Stopien::inzynierski);
	Student* StudentI = new Student(*OsobaI,kierunekA,4,Studia::stacjonarne,Stopien::doktorancki);
	Student* StudentJ = new Student(*OsobaJ,kierunekA,5,Studia::niestacjonarne,Stopien::inzynierski);

	//Pracownik* PracA = new Pracownik(*OsobaA,uczelniaA,StopienNaukowy::dr);


}
#endif


#ifdef Uczonko 
#include <iostream>
using namespace std;


class Osoba {

public: 
	
	virtual void wizytowka()
{
	cout << "Osoba\n";
}

};

class Student : public Osoba {

public: 
	
	void wizytowka() override {

	cout << "Student\n";
}

};

class Absolwent : public Student {

public: 
	
	void wizytowka() override {

	cout << "Absolwent\n";
}

};

class Pracownik : public Osoba {

public: 
	
	void wizytowka() override {
	
	cout << "Pracownik\n";
}

};
		
class Gosc : public Osoba {

public: 
	
	void wizytowka() override {

	cout << "Gosc\n";
}

};


int main(void) 
{
	Osoba os;
	Student st;
	Pracownik pr;
	Gosc go;
	Absolwent ab;

	Osoba Osoby[5] = {};


}
#endif  


