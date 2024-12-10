#include "Mec.h"

void Mec::OdigrajMec() {
	if (mec.dohvPok1()->VrednostTima() > mec.dohvPok2()->VrednostTima()) ish = POBEDA_DOMACIN;
	else {
		if (mec.dohvPok1()->VrednostTima() < mec.dohvPok2()->VrednostTima()) ish = POBEDA_GOST;
		else ish = NERESENO;
	}
	ind++;
}

void Mec::Azuriraj() {
	if (ind != 0 && ish != NERESENO) {
		if (ish == POBEDA_DOMACIN) {
			for (int i = 0; i < mec.dohvPok1()->dohvBrIgraca(); i++) {
				mec.dohvPok1()->igraci[i]->PovecajVr(10);
			}
			for (int i = 0; i < mec.dohvPok2()->dohvBrIgraca(); i++) {
				mec.dohvPok2()->igraci[i]->SmanjiVr(10);
			}
		}
		else {
			for (int i = 0; i < mec.dohvPok1()->dohvBrIgraca(); i++) {
				mec.dohvPok1()->igraci[i]->SmanjiVr(10);
			}
			for (int i = 0; i < mec.dohvPok2()->dohvBrIgraca(); i++) {
				mec.dohvPok2()->igraci[i]->PovecajVr(10);
			}
		}
	}
}

void Mec::FormirajPoene(Mec& m) {
	if (!ind) throw NijeOdigran();
	if (ish == POBEDA_DOMACIN) m.p->pd = 3;
	else {
		if (ish == POBEDA_GOST) m.p->pg = 3;
		else {
			m.p->pd = 1;
			m.p->pg = 1;
		}
	}
}

void Mec::pisi(ostream& izlaz) const {
	if (ind != 0) {
		izlaz << mec;
		if (ish == 0) izlaz << "POBEDA_DOMACIN";
		else {
			if (ish == 1) izlaz << "NERESENO";
			else izlaz << "POBEDA_GOST";
		}
	}

}

ostream& operator<<(ostream& izlaz, const Mec& m) {
	m.pisi(izlaz);
	return izlaz;
}
