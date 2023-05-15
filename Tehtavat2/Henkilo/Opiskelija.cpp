#include "Opiskelija.h"

Opiskelija::Opiskelija(
    const string &_nimi,
    const int &_ika,
    const Osoite &_osoite,
    const string &_nro,
    const int &_pisteet):
    Henkilo(_nimi, _ika, _osoite),
    opNro(_nro),
    opintopisteet(_pisteet),
    suoritetutKurssit() {
    //cout << "Opiskelija-luokan 5 parametrinen rakentaja\n";
}

Opiskelija::Opiskelija():
    //Henkilo(),
    //opNro(),
    //opintopisteet(),
    suoritetutKurssit() {
    luoOpiskelija();
    //cout << "Opiskelija-luokan parametriton rakentaja\n";
}

Opiskelija::Opiskelija(const Opiskelija &rhs):
    Henkilo(rhs.nimi, rhs.ika, rhs.osoite),
    opNro(rhs.opNro),
    opintopisteet(rhs.opintopisteet),
    suoritetutKurssit(rhs.suoritetutKurssit) {
    //cout << "Opiskelija-luokan kopio rakentaja\n";
}

Opiskelija &Opiskelija::operator=(const Opiskelija &rhs) {
    if (&rhs != this) {
        nimi = rhs.nimi;
        ika = rhs.ika;
        osoite = rhs.osoite;
        opNro = rhs.opNro;
        opintopisteet = rhs.opintopisteet;
        suoritetutKurssit = rhs.suoritetutKurssit;
    }
    //cout << "Opiskelija-luokan kopio sijoittaja\n";
    return *this;
}

Opiskelija::Opiskelija(Opiskelija &&rhs) noexcept:
    Henkilo(std::move(rhs.nimi), std::move(rhs.ika), std::move(rhs.osoite)),
    opNro(std::move(rhs.opNro)),
    opintopisteet(std::move(rhs.opintopisteet)),
    suoritetutKurssit(std::move(rhs.suoritetutKurssit)) {
    //cout << "Opiskelija-luokan liikuttava rakentaja\n";
}

Opiskelija &Opiskelija::operator=(Opiskelija &&rhs) noexcept {
    if (&rhs != this) {
        nimi = std::move(rhs.nimi);
        ika = std::move(rhs.ika);
        osoite = std::move(rhs.osoite);
        opNro = std::move(rhs.opNro);
        opintopisteet = std::move(rhs.opintopisteet);
        suoritetutKurssit = std::move(rhs.suoritetutKurssit);
    }
    //cout << "Opiskelija-luokan liikuttava sijoittaja\n";
    return *this;
}

Opiskelija::~Opiskelija() {
    //cout << "Opettaja-luokan tuhoaja\n";
}

string Opiskelija::getOpNro() const {
    return opNro;
}

vector<string> Opiskelija::getKurssit() const {
    return suoritetutKurssit;
}

int Opiskelija::getOpintoPisteet() const {
    return opintopisteet;
}

void Opiskelija::tulostaTiedot() const {
    cout << "\nNimi: " << nimi
        << ", Ika: " << ika << '\n';
    osoite.tulostaTiedot();
    cout << "OpNro: " << opNro <<
        ", OpPisteet: " << opintopisteet
        << "\nSuoritetut kurssit:\n";
    for (const auto &i : suoritetutKurssit)
        cout << i << '\n';
}

void Opiskelija::setOpNro(const string &_nro) {
    opNro = _nro;
}

void Opiskelija::lisaaKurssi(const string &_kurssi) {
    suoritetutKurssit.push_back(_kurssi);
}

void Opiskelija::poistaKurssi(const string &_kurssi) {
    for (size_t i{}; i < suoritetutKurssit.size(); ++i)
        if (suoritetutKurssit[i] == _kurssi)
            suoritetutKurssit.erase(
                suoritetutKurssit.begin() + i);
}

void Opiskelija::lisaaPisteita(const int &_pisteet) {
    opintopisteet += _pisteet;
}

void Opiskelija::luoOpiskelija() {
    luoHenkilo();
    cout << "Anna opiskelijanumero: ";
    getline(cin, opNro);
    cout << "Anna opintopisteet: ";
    cin >> opintopisteet;
    cin.clear();
    cin.ignore();
}
