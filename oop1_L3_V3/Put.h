#ifndef _put_h_
#define _put_h_
#include "Tacka.h"
#include "Lista.h"
#include "Greske.h"

class Put {
	Lista<Tacka> lista;
public:
	Put& operator+=(Tacka& t);
	double DuzinaPuta();
	friend ostream& operator<<(ostream& izlaz, const Put& p);
};

#endif

