#ifndef _par_h_
#define _par_h_
#include <iostream>

using namespace std;

template <typename T>

class Par {
	T* pok1;
	T* pok2;
public:
	Par() = default;
	Par(T* po1, T* po2): pok1(po1), pok2(po2){}

	T* dohvPok1() const { return pok1; }
	T* dohvPok2() const { return pok2; }
	T* postaviPok1(T* po1) { pok1 = po1; po1 = nullptr; return pok1; }
	T* postaviPok2(T* po2) { pok2 = po2; po2 = nullptr; return pok2; }

	bool operator==(const Par& p) { return *p.dohvPok1() == *p.dohvPok2(); }
	friend ostream& operator<<(ostream& izlaz, const Par& t) {
		return izlaz << "[" << *t.dohvPok1() << "-" << *t.dohvPok2() << "]";
	}
};

#endif