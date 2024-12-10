#include <iostream>
#include <exception>

using namespace std;

class NijeDostigaoVr : public exception {
public:
	NijeDostigaoVr() : exception("*** Vrednost igraca je manja od minimalne. ***") {}
};

class NijeOdigran : public exception {
public:
	NijeOdigran() : exception("*** Mec nije odigran. ***") {}
};