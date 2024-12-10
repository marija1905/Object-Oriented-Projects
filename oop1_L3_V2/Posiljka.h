#ifndef _posiljka_h_
#define _posiljka_h_
#include <iostream>
#include "Artikal.h"
#include "Lista.h"

using namespace std;
class Rukovalac;

class Posiljka {
	Artikal* a;
	static int sind;
	int ind = ++sind;
	friend class Rukovalac;
	Lista<Rukovalac*> r;
	struct Detalji {
		int cekanje;
		double cena;
		Detalji* sled;
		Detalji(int c = 0, double ce = 0.0) : cekanje(c), cena(ce) { sled = nullptr; };
	};
	Detalji* prvi, *posl;
	void kopiraj(const Posiljka& l);
	void premesti(Posiljka& l);
	void obrisi();
	int& ukcekanje;
	double& ukcena;
	int pom = 0;
	double pom1 = 0.0;
public:
	friend class Prodavac;
	Posiljka(Artikal& art, int c = 0, double ce = 0.0): ukcekanje(pom), ukcena(pom1) {
		a = &art;
		prvi = nullptr;
		posl = nullptr;
	}
	Posiljka(const Posiljka& l);
	Posiljka(Posiljka&& l);
	Posiljka& operator=(const Posiljka& l);
	Posiljka& operator=(Posiljka&& l);
	~Posiljka() { obrisi(); }

	Posiljka& operator+=(Rukovalac& ru);

	Artikal& dohvArtikal() const { return *a; }
	int dohvInd() const { return ind; }
	Detalji& dohvDetalje(int i) const;

	void izracunajDetalje() const;

	friend ostream& operator<< (ostream & izlaz, const Posiljka & p);
};

#endif

