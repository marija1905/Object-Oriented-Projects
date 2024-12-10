#include "Igrac.h"

bool operator==(const Igrac& ig1, const Igrac& ig2) {
    return (ig1.ime == ig2.ime && ig1.vr == ig1.vr);
}

ostream& operator<<(ostream& izlaz, const Igrac& ig) {
    return izlaz << ig.ime << "#" << ig.vr;
}
