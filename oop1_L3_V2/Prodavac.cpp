#include "Prodavac.h"

void Prodavac::Prosiri(Artikal* art, double m, int n) {
	Katalog* obj = new Katalog();
	obj->a = art;
	obj->marza = m;
	obj->nabavka = n;
	k += obj;
}

void Prodavac::Obrada(Posiljka& p) {
	for (int i = 0; i < k.dohvBr(); i++) {
		p.ukcekanje += k[i]->nabavka;
		p.ukcena += ProdajnaCena(i);
	}
}

