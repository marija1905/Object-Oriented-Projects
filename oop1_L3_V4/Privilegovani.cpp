#include "Privilegovani.h"
#include "Greske.h"

void Privilegovani::PrikljuciIgraca(int i, const Igrac& ig1) {
	if (ig1.vr < min) throw NijeDostigaoVr();
	Tim::PrikljuciIgraca(i, ig1);
}

void Privilegovani::pisi(ostream& izlaz) const {
	Tim::pisi(izlaz);
	izlaz << "(" << min << ")";
}

ostream& operator<<(ostream& izlaz, const Privilegovani& p) {
	p.pisi(izlaz);
	return izlaz;
}
