#ifndef _igrac_h_
#define _igrac_h_
#include <iostream>

using namespace std;

class Igrac {
	string ime;
	int vr;
public:
	friend class Tim;
	friend class Privilegovani;
	Igrac(string im = "", int v = 1000) : ime(im), vr(v) {}

	int dohvVr() { return vr; }
	double SmanjiVr(double procenat) { return vr - vr * procenat; }
	double PovecajVr(double procenat) { return vr + vr * procenat; }
	friend bool operator==(const Igrac& ig1, const Igrac& ig2);
	friend ostream& operator<<(ostream& izlaz, const Igrac& ig);
};

#endif

