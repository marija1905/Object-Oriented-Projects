#ifndef _eporuka_h_
#define _eporuka_h_

#include "Korisnik.h"

class EPoruka {
protected:
	enum Stanje { U_PRIPREMI, POSLATA, PRIMLJENA };
	Stanje s;
	Korisnik* posiljalac, *primalac;
	string naslov;
	virtual void pisi(ostream& izlaz) const;
public:
	EPoruka(Korisnik* pos, Korisnik* prim, string na) {
		posiljalac = pos;
		primalac = prim;
		naslov = na;
		s = U_PRIPREMI;
	}
	EPoruka(const EPoruka& ep) {};
	EPoruka(EPoruka&& ep) {};
	EPoruka& operator=(const EPoruka& ep) { return *this; };
	EPoruka& operator=(EPoruka&& ep) { return *this; };
	virtual ~EPoruka(){}

	Korisnik* dohvPosiljalac() const { return posiljalac; }
	Korisnik* dohvPrimalac() const { return primalac; }
	string dohvNaslov() const { return naslov; }
	Stanje dohvStanje() const { return s; }

	virtual void posaljiPoruku() = 0;
	virtual EPoruka* kopija() const = 0;
	friend ostream& operator<<(ostream& izlaz, const EPoruka& ep);
};

#endif

