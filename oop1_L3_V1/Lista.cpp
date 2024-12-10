#include "Lista.h"

template<typename T>
void Lista<T>::kopiraj(const Lista& l) {
	prvi = posl = tek = pret = nullptr;
	Elem* p = l.prvi;
	while (p) {
		Elem* n = new Elem(p->podatak);
		if (prvi == nullptr) {
			posl = prvi = n;
		}
		else {
			posl = posl->sled = n;
		}
		if (p == l.tek) tek = n;
		if (p == l.pret) pret = n;
	}
}

template<typename T>
void Lista<T>::premesti(Lista& l) {
	prvi = l.prvi;
	posl = l.posl;
	l.prvi = nullptr;
}


