#include "VremenskaOznaka.h"
#include <iomanip>

ostream& operator<<(ostream& izlaz, const VremenskaOznaka& vo) {
	return izlaz << setw(2) << setfill('0') << vo.dan << "." 
		<< setw(2) << setfill('0') << vo.mesec << "." 
		<< vo.godina << "-" << setw(2) << setfill('0') << vo.sat << ":" 
		<< setw(2) << setfill('0') << vo.minut;
}

int VremenskaOznaka::BrDanaUMesecu(int mes) const{
	switch(mes) {
	case 1:case 3:case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 2:
		if (!(godina % 400 == 0 || (godina % 4 == 0 && godina % 100 != 0)))
			return 28;
		return 29;
	case 4: case 6: case 9: case 11:
		return 30;
	}
}

VremenskaOznaka::VremenskaOznaka(int g, int mes, int d, int s, int m) {
	godina = g;
	mesec = mes;
	dan = d;
	sat = s;
	minut = m;
	if (mesec > 12 || mesec < 1) mesec = 1;
	if (dan < 1 || dan > BrDanaUMesecu(mesec)) dan = 1;
	if (sat > 23 || sat < 0) sat = 0;
	if (minut < 0 || minut > 59) minut = 0;
}
