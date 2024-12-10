#ifndef _vremenskaoznaka_h_
#define _vremenskaoznaka_h_

#include <iostream>
using namespace std;

class VremenskaOznaka {
	int godina, mesec, dan, sat, minut;
	int BrDanaUMesecu(int mes) const;
public:
	VremenskaOznaka(int g, int mes, int d, int s, int m);
	friend ostream& operator<<(ostream& izlaz, const VremenskaOznaka& vo);
};

#endif

