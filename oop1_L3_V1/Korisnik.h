#ifndef _korisnik_h_
#define _korisnik_h_

#include <iostream>
using namespace std;

class Korisnik {
protected:
	string ime, e_adresa;
public:
	Korisnik(string i, string e): ime(i), e_adresa(e){}
	Korisnik(const Korisnik&) = delete;
	Korisnik& operator=(const Korisnik&) = delete;

	string dohvIme() const { return ime; }
	string dohvE_Adresu() const { return e_adresa; }
	friend ostream& operator<<(ostream& izlaz, const Korisnik& k);
};

#endif
