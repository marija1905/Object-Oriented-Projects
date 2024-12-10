#include "Korisnik.h"

ostream& operator<<(ostream& izlaz, const Korisnik& k) {
	return izlaz << "(" << k.ime << ")" << k.e_adresa;
}
