#include "Lista.h"
#include "Greske.h"
#include "Rukovalac.h"
#include "Prodavac.h"
#include <exception>

int main() {
	try {
		Artikal a("Cokolada", 123423, 125.99);
		Prodavac p("Prodavac");
		p.Prosiri(&a, 0.25, 3);
		Posiljka pos(a);
		pos += p;
		cout << pos;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}