#ifndef _obicnovozilo_h_
#define _obicnovozilo_h_
#include "Vozilo.h"

class ObicnoVozilo : public Vozilo{
public:
	double IzracunajCenu(Put& put, double startna = 120) override { return startna + put.DuzinaPuta() * 0.1; };
	void pisi(ostream& izlaz) const override;
	ObicnoVozilo* kopija() const override { return new ObicnoVozilo(*this); }
};

#endif
