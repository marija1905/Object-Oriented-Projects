#pragma once

#include <exception>

using namespace std;

class NePostojiTekuci : public exception {
public:
	NePostojiTekuci() : exception("*** Ne postoji tekuci. ***") {};
};
class PorukaJePoslata : public exception {
public:
	PorukaJePoslata() : exception("*** Nije moguce izmeniti tekst poslate poruke. ***") {};
};