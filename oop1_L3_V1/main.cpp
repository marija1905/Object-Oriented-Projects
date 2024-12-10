#include <iostream>
#include "EPorukaSaT.h"

using namespace std;

int main() {
	try {
		Korisnik k1("Marko Markovic", "mm563@gmai.com"), k2("Pera Peric", "ppqw123@gmail.com");
		EPorukaSaT t(&k1, &k2, "Naslov");
		t.PostaviTekst("Ispis teksta sa zadatim naslovom.");
		cout << t;
	}
	catch (exception e) {
		cout << e.what();
	}
}