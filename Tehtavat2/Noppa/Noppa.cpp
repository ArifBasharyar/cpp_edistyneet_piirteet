#include "Noppa.h"

u16 Noppa::getRandArvo() {
    return std::rand() % 6 + 1;
}

Noppa::Noppa() {
    srand(time(nullptr));
    noppa1 = getRandArvo();
    noppa_lkm = 1;
}

Noppa::Noppa(u16 lkm): noppa_lkm(lkm) {
    srand(time(nullptr));
    noppa1 = getRandArvo();
    noppa_lkm = lkm;

    if (lkm > 1)
        noppa2 = getRandArvo();
    if (lkm > 2)
        noppa3 = getRandArvo();
    if (lkm > 3)
        noppa4 = getRandArvo();
    if (lkm > 4)
        noppa5 = getRandArvo();
}

u16 Noppa::getViimeisinLukema() {
    return noppa1 + noppa2 + noppa3 + noppa4 + noppa5;
}

void Noppa::heitaNoppaa() {
    noppa1 = getRandArvo();

    if (noppa_lkm > 1)
        noppa2 = getRandArvo();
    if (noppa_lkm > 2)
        noppa3 = getRandArvo();
    if (noppa_lkm > 3)
        noppa4 = getRandArvo();
    if (noppa_lkm > 4)
        noppa5 = getRandArvo();
}

void Noppa::kerroViimeisenHeitonLukema() {
    std::cout << "Viimeisin heitto: " << getViimeisinLukema()
        << ". Heitetty " << noppa_lkm << " nopalla." << "\n";
}

u16 Noppa::getNoppaLkm() {
    return noppa_lkm;
}

void Noppa::setNoppaLkm(u16 lkm) {
    noppa_lkm = lkm;

    // Jos noppa_lkm kasvaa
    if (lkm > 1
        && noppa2 == 0)
        noppa2 = getRandArvo();
    if (lkm > 2
        && noppa3 == 0)
        noppa3 = getRandArvo();
    if (lkm > 3
        && noppa4 == 0)
        noppa4 = getRandArvo();
    if (lkm > 4
        && noppa5 == 0)
        noppa5 = getRandArvo();

    // Jos noppa_lkm laskee
    if (lkm < 5
        && noppa5 != 0)
        noppa5 = 0;
    if (lkm < 4
        && noppa4 != 0)
        noppa4 = 0;
    if (lkm < 3
        && noppa3 != 0)
        noppa3 = 0;
    if (lkm < 2
        && noppa2 != 0)
        noppa2 = 0;
}