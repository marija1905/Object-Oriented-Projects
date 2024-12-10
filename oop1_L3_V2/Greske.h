#include <iostream>
#include <exception>

using namespace std;

class NijeIzracunato : public exception {
public:
	NijeIzracunato() : exception("*** Detalji posiljke nisu izracunati. ***") {}
};

class DodajNovi : public exception {
public:
	DodajNovi() : exception("*** Vec su izracunati detalji posiljke. ***") {}
};
