#include "Vozilo.h"

void Vozilo::pisi(ostream& izlaz) const {
	izlaz << model;
}

double Vozilo::IzracunajCenu(Put& put, double startna) {
	return startna + put.DuzinaPuta() * 0.1;
	
}

ostream& operator<<(ostream& izlaz, const Vozilo& v) {
	v.pisi(izlaz);
	return izlaz;
}
