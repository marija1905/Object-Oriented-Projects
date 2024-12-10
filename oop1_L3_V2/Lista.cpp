#include "Lista.h"
#include "Greske.h"


template<typename T>
void Lista<T>::kopiraj(const Lista& l) {
	prvi = tek = posl = pret = nullptr;
	Elem* tren = l.prvi;
	while (tren != nullptr) {
		Elem* p = new Elem(tren->podatak);
		if (prvi == nullptr) {
			posl = prvi = p;
		}
		else {
			posl = posl->sled = p;
		}
		if (tren == l.tek) tek = p;
		if (tren == l.pret) pret = p;
		tren = tren->sled;
	}
}

template<typename T>
void Lista<T>::premesti(Lista& l) {
	prvi = l.prvi;
	posl = l.posl;
	l.prvi = nullptr;
}

template<typename T>
Lista<T>::Lista(const Lista& l) {
	kopiraj(l);
}

template<typename T>
Lista<T>::Lista(Lista&& l) {
	premesti(l);
}

template<typename T>
Lista<T> &Lista<T>::operator=(const Lista& l) {
	if (this != &l) {
		obrisi();
		kopiraj(l);
	}
	return *this;
}

template<typename T>
Lista<T> &Lista<T>::operator=(Lista&& l) {
	if (this != &l) {
		obrisi();
		premesti(l);
	}
	return *this;
}

