#ifndef _artikal_h_
#define _artikal_h_
#include <iostream>
using namespace std;

class Artikal {
protected:
	string naziv;
	int kod;
	double nabavnaCena;
public:
	Artikal(string na, int k, double nC): naziv(na), kod(k), nabavnaCena(nC){}

	string dohvNaziv() const { return naziv; }
	int dohvKod() const { return kod; }
	double dohvNabavnuCenu() const { return nabavnaCena; }

	friend bool operator==(const Artikal& art1, const Artikal& art2);
};

#endif

