#ifndef _lista_h_
#define _lista_h_
#include <iostream>

using namespace std;
class NijeUOpsegu : public exception {
public:
	NijeUOpsegu() : exception("*** Indeks van opsega. ***") {}
};

template <typename T>

class Lista {
	struct Elem {
		T podatak;
		Elem* sled;
		Elem(const T& p, Elem* s = nullptr): podatak(p), sled(s){}
	};
	int br;
	Elem* prvi, * posl;
	mutable Elem* tek, * pret;
	void kopiraj(const Lista& l);
	void premesti(Lista& l);
public:
	Lista(Elem* pr = nullptr, Elem* po = nullptr, Elem* te = nullptr, Elem* pre = nullptr)
		: prvi(pr), posl(po), tek(te), pret(pre) {
		br = 0;
	}
	Lista(const Lista& l);
	Lista(Lista&& l);
	Lista& operator=(const Lista& l);
	Lista& operator=(Lista&& l);
	~Lista() { obrisi(); }

	Lista& operator+= (const T& p) {
		if (prvi == nullptr) {
			prvi = new Elem(p);
			posl = prvi;
			br++;
			return *this;
		}
		pret = posl;
		posl->sled = new Elem(p);
		posl = posl->sled;
		br++;
		return *this;
	};
	int dohvBr() const { return br; }

	T& operator[] (int i) {
		if (i > br - 1 || i < 0) throw NijeUOpsegu();
		tek = prvi;
		for (int j = 0; j < br; j++) {
			if (j == i) {
				return tek->podatak;
			}
			tek = tek->sled;
		}
	};
	T operator[](int i) const {
		if (i > br - 1 || i < 0) throw NijeUOpsegu();
		tek = prvi;
		for (int j = 0; j < br; j++) {
			if (j == i) {
				return tek->podatak;
			}
			tek = tek->sled;
		}
	};
	Lista& obrisi() {
		Elem* stari = prvi;
		while (prvi) {
			prvi = prvi->sled;
			delete(stari);
			stari = prvi;
		}
		posl = tek = pret = nullptr;
		br = 0;
		return *this;
	};
};


#endif


