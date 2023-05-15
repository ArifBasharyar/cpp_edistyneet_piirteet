#include "Merkinta.h"

Merkinta::Merkinta(
    const Paivaus &_paivaus,
    const string &_asia,
    const bool &_muistutus):
    paivaus(_paivaus),
    asia(_asia),
    muistutus(_muistutus) {}

Merkinta::Merkinta(const Merkinta &m):
    asia(m.asia),
    muistutus(m.muistutus) {
    paivaus.luo_uusi_paivaus();
}

Merkinta::Merkinta(Merkinta &&m) noexcept:
    asia(std::exchange(m.asia, "")),
    muistutus(std::exchange(m.muistutus, false)) {
    paivaus.luo_uusi_paivaus();
}

void Merkinta::setPaivaus(const Paivaus &_paivaus) {
    paivaus = _paivaus;
}

void Merkinta::setAsia(const string &_asia) {
    asia = _asia;
}

void Merkinta::setMuistutus(const bool &_muistutus) {
    muistutus = _muistutus;
}

Paivaus Merkinta::getPaivaus() const {
    return paivaus;
}

string Merkinta::getAsia() const {
    return asia;
}

bool Merkinta::getMuistutus() const {
    return muistutus;
}

void Merkinta::tulostaMerkinta() const {
    paivaus.tulostaPaivays();
    cout << "Asia: " << asia
        << ", Muistutus: " << muistutus << "\n";
}

void Merkinta::kysyTiedot() {
    paivaus.luo_uusi_paivaus();

    cin.ignore();
    cin.clear();

    cout << "Anna asia: ";
    getline(cin, asia);

    cout << "Onko muistutus totta: ";
    cin >> muistutus;
}
