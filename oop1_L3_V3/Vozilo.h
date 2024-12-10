#ifndef _vozilo_h_
#define _vozilo_h_
#include <iostream>
#include "Put.h"

using namespace std;

class Vozilo {
	string model;
protected:
	virtual void pisi(ostream& izlaz) const;
public:
	Vozilo(string m): model(m){}
	virtual double IzracunajCenu(Put& put, double startna) = 0;
	friend ostream& operator<<(ostream& izlaz, const Vozilo& v);
	virtual Vozilo* kopija() const = 0;

};

#endif

