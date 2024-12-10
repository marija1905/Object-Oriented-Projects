#include "EPorukaSaT.h"
#include "Greska.h"

void EPorukaSaT::pisi(ostream& izlaz) const {
	EPoruka::pisi(izlaz);
	izlaz << endl;
	izlaz << tekst;
}

void EPorukaSaT::menjanjePoruke(string t) {
	if (s == POSLATA) throw PorukaJePoslata();
	tekst = t;
}

EPorukaSaT* EPorukaSaT::kopija() const {
	return new EPorukaSaT(*this);
}


ostream& operator<<(ostream& izlaz, const EPorukaSaT& ep) {
	ep.pisi(izlaz);
	return izlaz;
}
