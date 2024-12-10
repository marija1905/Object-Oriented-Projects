#include "Put.h"

Put& Put::operator+=(Tacka& t) {
	for (int i = 0; i < lista.dohvBr(); i++) {
		if (lista[i] == t) throw IsteTacke();
	}
	lista += t;
	return *this;
}

double Put::DuzinaPuta() {
	double duzina = 0;
	for (int i = 0; i < lista.dohvBr() - 1; i++) {
		duzina +=  (lista[i]).udaljenost(lista[i + 1]);
	}
	return duzina;
}

ostream& operator<<(ostream& izlaz, const Put& p) {
	for (int i = 0; i < p.lista.dohvBr(); i++) {
		cout << p.lista[i];
		i == p.lista.dohvBr() - 1 ? cout << "" : cout << endl;
	}
	return izlaz;
}
