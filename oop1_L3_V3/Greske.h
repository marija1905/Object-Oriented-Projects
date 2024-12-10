#include <iostream>
#include <exception>

using namespace std;

class IsteTacke : public exception {
public:
	IsteTacke() : exception("*** Vec postoji zadata tacka. ***") {}
};
