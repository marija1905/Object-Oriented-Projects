#include "Tacka.h"

bool operator==(const Tacka& t1, const Tacka& t2) {
    return t1.x == t2.x && t1.y == t2.y;
}

ostream& operator<<(ostream& izlaz, const Tacka& t) {
    return izlaz << "(" << t.x << "," << t.y << ")";
}

double Tacka::udaljenost(const Tacka& t2) {
    return sqrt(pow(x - t2.x, 2) + pow(y - t2.y, 2));
}
