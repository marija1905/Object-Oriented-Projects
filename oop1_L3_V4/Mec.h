#ifndef _mec_h_
#define _mec_h_
#include "Par.h"
#include "Tim.h"
#include "Greske.h"

class Mec {
	Par<Tim> mec;
	enum Ishod{POBEDA_DOMACIN, NERESENO, POBEDA_GOST};
	Ishod ish;
	int ind = 0;
	class Poeni {
	public:
		int pd;
		int pg;
	};
	Poeni* p;
	void pisi(ostream& izlaz) const;
public:
	Mec(Tim* d, Tim* g) {
		mec.postaviPok1(d);
		mec.postaviPok2(g);
	}


	Tim* dohvTim1() const { return mec.dohvPok1(); }
	Tim* dohvTim2() const { return mec.dohvPok2(); }
	Poeni* dohvPoene() const { return p; }
	void OdigrajMec();
	void Azuriraj();
	bool DaLiJeOdigran() const { return ind; }
	void FormirajPoene(Mec& m);
	friend ostream& operator<<(ostream& izlaz, const Mec& m);
};

#endif

