#include "Rukovalac.h"
#include "Posiljka.h"

void Rukovalac::postaviDetalje(Posiljka& p, int ce, double c) {
	Posiljka::Detalji* tren = p.Posiljka::prvi;
	Posiljka::Detalji* pre = tren;
	for (int i = 0; i < p.r.dohvBr(); i++) {
		if (i == p.r.dohvBr() - 1) {
			if (tren == nullptr) {
				tren = new Posiljka::Detalji(ce, c);
				if (pre == nullptr) pre = tren;
				else pre->sled = tren;
				p.Posiljka::prvi = tren;
			}
			pre = p.Posiljka::posl;
			tren = tren->sled;
		}
	}
}
