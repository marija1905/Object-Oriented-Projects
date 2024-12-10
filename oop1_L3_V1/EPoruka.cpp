#include "EPoruka.h"

void EPoruka::pisi (ostream& izlaz) const {
	izlaz << naslov << endl;
	izlaz << *posiljalac << endl << *primalac;
}

ostream& operator<<(ostream& izlaz, const EPoruka& ep) {
	ep.pisi(izlaz);
	return izlaz;
}


