#ifndef _tim_h_
#define _tim_h_
#include "Igrac.h"

class Tim {
protected:
	string naziv;
	int maks;
	Igrac** igraci;
	int br = 0;
	virtual void pisi(ostream& izlaz) const;
	void kopiraj(const Tim& t);
	void premesti(Tim& t);
	void obrisi();
public:
	friend class Mec;
	Tim(string n, int m) : naziv(n), maks(m) {
		igraci = new Igrac*[maks];
		for (int i = 0; i < maks; i++) igraci[i] = new Igrac[maks];
		for (int i = 0; i < maks; i++) {
			igraci[i]->ime = ""; 
			igraci[i]->vr = 0; 
		} 
	}
	Tim(const Tim& t);
	Tim(Tim&& t);
	Tim& operator=(const Tim& t);
	Tim& operator=(Tim&& t);
	~Tim() { obrisi(); }

	virtual void PrikljuciIgraca(int i, const Igrac& ig1);
	int dohvBrIgraca() { return br; }
	Igrac& operator[](int i);
	Igrac operator[](int i) const;
	double VrednostTima() const;
	friend bool operator==(const Tim& t1, const Tim& t2);
	friend ostream& operator<<(ostream& izlaz, const Tim& t);
};

#endif
