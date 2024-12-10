#ifndef _tacka_h_
#define _tacka_h_
#include <iostream>
#include <cmath>

using namespace std;

class Tacka {
	int x, y;
public:
	Tacka(int x1 = 0, int y1 = 0): x(x1), y(y1){}
	double udaljenost(const Tacka& t2);
	friend bool operator==(const Tacka& t1, const Tacka& t2);
	friend ostream& operator<<(ostream& izlaz, const Tacka& t);
};

#endif

