#ifndef _privilegovani_h_
#define _privilegovani_h_
#include "Tim.h"

class Privilegovani : public Tim{
	int min;
	void pisi(ostream& izlaz) const;
public:
	Privilegovani(string n, int m, int min) : Tim(n, m) {
		this->min = min;
	}
	void PrikljuciIgraca(int i, const Igrac& ig1) override;
	friend ostream& operator<<(ostream& izlaz, const Privilegovani& p);
};

#endif

