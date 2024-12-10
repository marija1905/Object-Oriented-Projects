#include "Put.h"
#include "ObicnoVozilo.h"

int main() {
	try {
		Put put;
		Tacka t1(1, 2), t2(2, 3), t3(4, 5);
		put += t1;
		put += t2;
		put += t3;
		cout << put.DuzinaPuta() << endl;
		cout << put;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}