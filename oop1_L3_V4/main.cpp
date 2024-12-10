#include "Mec.h"
#include "Igrac.h"
#include "Privilegovani.h"
int main() {
	try {
		Igrac i1("Klay Thompson", 15000), i2("Stephen Curry", 20000), i3("Michael Jordan", 25000), i4("Nikola Jokic", 17000), i5("Luka Doncic", 21000);
		Tim t1("Tim1", 3), t2("Tim2", 3);
		t1.PrikljuciIgraca(0, i1);
		t1.PrikljuciIgraca(1, i2);
		t2.PrikljuciIgraca(0, i3);
		t2.PrikljuciIgraca(1, i4);
		Tim t3("Tim3", 3);
		t3.PrikljuciIgraca(1, i3);
		t3.PrikljuciIgraca(0, i5);
		Mec m1(&t1, &t2), m2(&t1, &t3);
		m1.OdigrajMec();
		m2.OdigrajMec();
		cout << m1 << endl <<m2;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

}