#ifndef _rukovalac_h_
#define _rukovalac_h_
#include "Posiljka.h"

class Rukovalac {
public:
	friend class Posiljka;
	virtual void postaviDetalje(Posiljka& p, int ce, double c) = 0;
	virtual ~Rukovalac() {};
	virtual Rukovalac* kopija() const = 0;
};

#endif

