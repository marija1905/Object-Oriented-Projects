#include "Tim.h"

void Tim::pisi(ostream& izlaz) const {
	izlaz << naziv << "[";
	for (int i = 0; i < br; i++) {
		izlaz << *igraci[i];
		i == br - 1 ? izlaz << "]" : izlaz << ",";
	}
}

void Tim::kopiraj(const Tim& t) {
	naziv = t.naziv;
	maks = t.maks;
	br = t.br;
	igraci = new Igrac * [maks];
	for (int i = 0; i < maks; i++) igraci[i] = new Igrac[maks];
	for (int i = 0; i < maks; i++) {
		igraci[i]->ime = "";
		igraci[i]->vr = 0;
	}
	for (int i = 0; i < maks; i++) {
		igraci[i]->ime = t.igraci[i]->ime;
		igraci[i]->vr = t.igraci[i]->vr;
	}
}

void Tim::premesti(Tim& t) {
	naziv = t.naziv;
	maks = t.maks;
	br = t.br;
	igraci = t.igraci;
	t.igraci = nullptr;
}

void Tim::obrisi() {
	delete[] igraci;
}

Tim::Tim(const Tim& t) {
	kopiraj(t);
}

Tim::Tim(Tim&& t) {
	premesti(t);
}

Tim& Tim::operator=(const Tim& t) {
	if (this != &t) {
		obrisi();
		kopiraj(t);
	}
	return *this;
}

Tim& Tim::operator=(Tim&& t) {
	if (this != &t) {
		obrisi();
		premesti(t);
	}
	return *this;
}

void Tim::PrikljuciIgraca(int i,const Igrac& ig1) {
	igraci[i]->ime = ig1.ime;
	igraci[i]->vr = ig1.vr;
	br++;
}

Igrac& Tim::operator[](int i) {
	return *igraci[i];
}

Igrac Tim::operator[](int i) const
{
	return *igraci[i];
}

double Tim::VrednostTima() const {
	double svr = 0;
	for (int i = 0; i < br; i++) {
		svr += igraci[i]->vr;
	}
	return svr / br;
}

bool operator==(const Tim& t1, const Tim& t2) {
	if (t1.naziv == t2.naziv && t1.maks == t2.maks) {
		for (int i = 0; i < t1.maks - 1; i++) {
			if (!(t1.igraci[i] == t2.igraci[i])) {
				return false;
			}
		}
		return true;
	}
	return false;
}

ostream& operator<<(ostream& izlaz, const Tim& t) {
	t.pisi(izlaz);
	return izlaz;
}
