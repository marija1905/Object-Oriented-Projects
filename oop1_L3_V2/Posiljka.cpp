#include "Posiljka.h"
#include "Rukovalac.h"
#include "Greske.h"
int Posiljka::sind = 0;

Posiljka::Posiljka(const Posiljka& l) : ukcekanje(l.ukcekanje), ukcena(l.ukcena) {
	kopiraj(l);
}

Posiljka::Posiljka(Posiljka&& l): ukcekanje(l.ukcekanje), ukcena(l.ukcena) {
	premesti(l);
}

Posiljka& Posiljka::operator=(const Posiljka& l) {
	if (this != &l) {
		obrisi();
		kopiraj(l);
	}
	return *this;
}

Posiljka& Posiljka::operator=(Posiljka&& l) {
	if (this != &l) {
		obrisi();
		premesti(l);
	}
	return *this;
}

Posiljka& Posiljka::operator+=(Rukovalac& ru) {
	if (ukcekanje != 0 && ukcena != 0) throw DodajNovi();
	r += &ru;
	return *this;
}

Posiljka::Detalji& Posiljka::dohvDetalje(int i) const {
	if (ukcekanje == 0 && ukcena == 0) throw NijeIzracunato();
	Detalji* tren = prvi;
	int j = 0;
	while (j != i) {
		tren = tren->sled;
		j++;
	}
	return *tren;
}

void Posiljka::izracunajDetalje() const {
	Detalji* tren = prvi;
	for (int i = 0; i < r.dohvBr(); i++) {
		ukcekanje += tren->cekanje;
		ukcena += tren->cena;
		tren = tren->sled;
	}
}

ostream& operator<<(ostream& izlaz, const Posiljka& p) {
	return izlaz << "Posiljka" << "[" << p.ind << ", " << p.a->dohvNaziv() << "]";
}

void Posiljka::kopiraj(const Posiljka& l) {
	Detalji* tren = l.prvi;
	while (tren != nullptr) {
		Detalji* p = new Detalji(tren->cekanje, tren->cena);
		if (prvi == nullptr) {
			prvi = posl = p;
		}
		else {
			posl->sled = p;
			posl = posl->sled;
		}
		tren = tren->sled;
	}
}

void Posiljka::premesti(Posiljka& l) {
	prvi = l.prvi;
	posl = l.posl;
	l.prvi = nullptr;
}

void Posiljka::obrisi() {
	Detalji* stari = prvi;
	while (prvi) {
		prvi = prvi->sled;
		delete(stari);
		stari = prvi;
	}
	posl = nullptr;
}
