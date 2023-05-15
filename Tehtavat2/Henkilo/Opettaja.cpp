#include "Opettaja.h"

Opettaja::Opettaja(
    const string &_nimi,
    const int &_ika,
    const Osoite &_osoite,
    const string &_koulutus):
    Henkilo(_nimi, _ika, _osoite),
    koulutusala(_koulutus),
    kurssit() {
    //cout << "Opettaja-luokan 4 parametrinen rakentaja\n";
}

Opettaja::Opettaja():
    //Henkilo(),
    //koulutusala(),
    kurssit() {
    luoOpettaja();
    //cout << "Opettaja-luokan parametriton rakentaja\n";
}

Opettaja::Opettaja(const Opettaja &rhs):
    Henkilo(rhs.nimi, rhs.ika, rhs.osoite),
    koulutusala(rhs.koulutusala),
    kurssit(rhs.kurssit) {
    //cout << "Opettaja-luokan kopio rakentaja\n";
}

Opettaja &Opettaja::operator=(const Opettaja &rhs) {
    if (&rhs != this) {
        nimi = rhs.nimi;
        ika = rhs.ika;
        osoite = rhs.osoite;
        koulutusala = rhs.koulutusala;
        kurssit = rhs.kurssit;
    }
    //cout << "Opettaja-luokan kopio sijoittaja\n";
    return *this;
}

Opettaja::Opettaja(Opettaja &&rhs) noexcept:
    Henkilo(std::move(rhs.nimi), std::move(rhs.ika), std::move(rhs.osoite)),
    koulutusala(std::move(rhs.koulutusala)),
    kurssit(std::move(rhs.kurssit)) {
    //cout << "Opettaja-luokan liikuttava rakentaja\n";
}

Opettaja &Opettaja::operator=(Opettaja &&rhs) noexcept {
    if (&rhs != this) {
        nimi = std::move(rhs.nimi);
        ika = std::move(rhs.ika);
        osoite = std::move(rhs.osoite);
        koulutusala = std::move(rhs.koulutusala);
        kurssit = std::move(rhs.kurssit);
    }
    //cout << "Opettaja-luokan liikuttava sijoittaja\n";
    return *this;
}

Opettaja::~Opettaja() {
    //cout << "Opettaja-luokan tuhoaja\n";
}

string Opettaja::getKoulutus() const {
    return koulutusala;
}

vector<string> Opettaja::getKurssit() const {
    return kurssit;
}

void Opettaja::tulostaTiedot() const {
    cout << "\nNimi: " << nimi
        << ", Ika: " << ika << '\n';
    osoite.tulostaTiedot();
    cout << "Koulutusala: " << koulutusala
        << "\nKurssit:\n";
    for (const auto &i : kurssit)
        cout << i << '\n';
}

void Opettaja::setKoulutus(const string &_koulutus) {
    koulutusala = _koulutus;
}

void Opettaja::lisaaKurssi(const string &_kurssi) {
    kurssit.push_back(_kurssi);
}

void Opettaja::poistaKurssi(const string &_kurssi) {
    for (size_t i{}; i < kurssit.size(); ++i)
        if (kurssit[i] == _kurssi)
            kurssit.erase(kurssit.begin() + i);
}

void Opettaja::luoOpettaja() {
    luoHenkilo();
    cout << "Anna Koulutusala: ";
    getline(cin, koulutusala);
}
