#include "henkilo.h"

Henkilo::Henkilo(
    const string &_nimi,
    const int &_ika,
    const Osoite &_osoite):
    nimi(_nimi),
    ika(_ika),
    osoite(_osoite) {
    //cout << "Henkilo-luokan 3 parametrinen rakentaja\n";
}

Henkilo::Henkilo():
    nimi(),
    ika(),
    osoite() {
    //cout << "Henkilo-luokan parametriton rakentaja\n";
}

Henkilo::Henkilo(const Henkilo &rhs):
    nimi(rhs.nimi),
    ika(rhs.ika),
    osoite(rhs.osoite) {
    //cout << "Henkilo-luokan kopio rakentaja\n";
}

Henkilo &Henkilo::operator=(const Henkilo &rhs) {
    if (&rhs != this) {
        nimi = rhs.nimi;
        ika = rhs.ika;
        osoite = rhs.osoite;
    }
    //cout << "Henkilo-luokan kopio sijoittaja\n";
    return *this;
}

Henkilo::Henkilo(Henkilo &&rhs) noexcept:
    nimi(std::move(rhs.nimi)),
    ika(std::move(rhs.ika)),
    osoite(std::move(rhs.osoite)) {
    //cout << "Henkilo-luokan liikuttava rakentaja\n";
}

Henkilo &Henkilo::operator=(Henkilo &&rhs) noexcept {
    if (&rhs != this) {
        nimi = std::move(rhs.nimi);
        ika = std::move(rhs.ika);
        osoite = std::move(rhs.osoite);
    }
    //cout << "Henkilo-luokan liikuttava sijoittaja\n";
    return *this;
}

Henkilo::~Henkilo() {
    //cout << "Henkilo-luokan tuhoaja\n";
}

void Henkilo::setNimi(const string &_nimi) {
    nimi = _nimi;
}

void Henkilo::setIka(const int &_ika) {
    ika = _ika;
}

void Henkilo::setOsoite(const Osoite &_osoite) {
    osoite = _osoite;
}

string Henkilo::getNimi()  const {
    return nimi;
}

int  Henkilo::getIka() const {
    return ika;
}

Osoite Henkilo::getOsoite() const {
    return osoite;
}

void Henkilo::tulostaTiedot() const {
    cout << "\nNimi: " << nimi
        << ", Ika: " << ika << '\n';
    osoite.tulostaTiedot();
}

void Henkilo::luoHenkilo() {
    cout << "\nAnna nimi: ";
    getline(cin, nimi);
    cout << "Anna ikä: ";
    cin >> ika;
    cin.clear();
    cin.ignore();
    osoite.luoOsoite();
}
