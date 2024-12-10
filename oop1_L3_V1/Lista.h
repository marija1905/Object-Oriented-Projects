#ifndef _lista_h_
#define _lista_h_

#include <iostream>
#include "Greska.h"
using namespace std;

template<typename T>

class Lista {
	struct Elem {
		T podatak;
		Elem* sled;
		Elem(const T& p, Elem* s = nullptr): podatak(p), sled(s) {}
	};
	Elem* prvi;
	Elem* posl;
	mutable Elem* tek, *pret;
	int brojElemenata;
	void kopiraj(const Lista& l);
	void premesti(Lista& l);
public:
	Lista() {prvi = nullptr; posl = nullptr; tek = nullptr; pret = nullptr; brojElemenata = 0}
	Lista(const Lista& l) {
		kopiraj(l);
	};

	Lista(Lista&& l) {
		premesti(l);
	};

	Lista& operator=(const Lista& l) {
		if (this != &l) {
			obrisi();
			kopiraj(l);
		}
		return *this;
	};
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			obrisi();
			premesti(l);
		}
		return *this;
	};

	~Lista() { obrisi(); };

	Lista& dodajElement(const T& p) {
		if (prvi == nullptr) {
			prvi = new Elem(p);
			posl = prvi;
		}
		else {
			posl->sled = new Elem(p);
			posl = posl->sled;
		}
		brojElemenata++;
		return *this;
	};

	int DohvBrojElemenata() const { return brojElemenata; };

	Lista& postaviNaPrvi() { tek = prvi; pret = nullptr; return *this; };

	const Lista& postaviNaPrvi() const { tek = prvi; pret = nullptr; return *this; };

	Lista& predjiNaSledeci() {
		pret = tek; 
		if (tek != nullptr) tek = tek->sled;
		return *this;
	}

	const Lista& predjiNaSledeci() const {
		pret = tek;
		if (tek != nullptr) tek = tek->sled;
		return *this;
	}

	bool ImaTekuci() { return tek != nullptr; }

	T& dohvTekuci() {
		if (tek == nullptr) throw NePostojiTekuci();
		return this->tek;

	}

	const T& dohvTekuci() const {
		if (tek == nullptr) throw NePostojiTekuci();
		return this->tek;

	}

	Lista& obrisi() {
		while (prvi) {
			Elem* stari = prvi;
			prvi = prvi->sled;
			delete(stari);
		}
		posl = pret = tek = nullptr;
		brojElemenata = 0;
		return *this;
	};

};

#endif


