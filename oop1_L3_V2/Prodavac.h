#ifndef _prodavac_h_
#define _prodavac_h_
#include "Rukovalac.h"
#include "Lista.h"
#include "Artikal.h"

class Prodavac : public Rukovalac {
	string naziv;
	class Katalog {
	public:
		Artikal* a;
		double marza;
		int nabavka;
	};
	Lista <Katalog*> k;
public:
	Prodavac(string n) : naziv(n){}
	~Prodavac() {}

	double ProdajnaCena(int i) const { return k[i]->a->dohvNabavnuCenu() * k[i]->marza; }
	void Prosiri(Artikal* art, double m, int n);
	string dohvNaziv() const { return naziv; }
	void Obrada(Posiljka& p);
	void postaviDetalje(Posiljka& p, int ce, double c) override { Rukovalac::postaviDetalje(p, ce, c); };
	Prodavac* kopija() const override { return new Prodavac(*this); }
};

#endif

