#ifndef _eporukasat_h_
#define _eporukasat_h_
#include "EPoruka.h"

class EPorukaSaT : public EPoruka{
	string tekst;
	void pisi(ostream& izlaz) const override;
public:
	EPorukaSaT(Korisnik* pos, Korisnik* prim, string na, string t = "") : EPoruka(pos, prim, na) { tekst = t; }
	~EPorukaSaT() {}

	void PostaviTekst(string t) { tekst = t; }
	void posaljiPoruku() override { s = POSLATA; };
	void menjanjePoruke(string t);
	friend ostream& operator<<(ostream& izlaz, const EPorukaSaT& ep);
	EPorukaSaT* kopija() const override;
};

#endif

