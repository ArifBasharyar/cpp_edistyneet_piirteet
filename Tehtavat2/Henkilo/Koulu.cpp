#include "Koulu.h"

Koulu::Koulu():
    opettajat(),
    opiskelijat(),
    koulunNimi() {}

Koulu::Koulu(const Koulu &rhs):
    opettajat(rhs.opettajat),
    opiskelijat(rhs.opiskelijat),
    koulunNimi(rhs.koulunNimi) {}

Koulu &Koulu::operator=(const Koulu &rhs) {
    if (&rhs != this) {
        opettajat = rhs.opettajat;
        opiskelijat = rhs.opiskelijat;
        koulunNimi = rhs.koulunNimi;
    }
    return *this;
}

Koulu::Koulu(Koulu &&rhs) noexcept:
    opettajat(std::move(rhs.opettajat)),
    opiskelijat(std::move(rhs.opiskelijat)),
    koulunNimi(std::move(rhs.koulunNimi)) {}

Koulu &Koulu::operator=(Koulu &&rhs) noexcept {
    if (&rhs != this) {
        opettajat = std::move(rhs.opettajat);
        opiskelijat = std::move(rhs.opiskelijat);
        koulunNimi = std::move(rhs.koulunNimi);
    }
    return *this;
}

Koulu::~Koulu() {}

vector<Sptr<Opettaja>> Koulu::getOpettajat() const {
    return opettajat;
}

vector<Sptr<Opiskelija>> Koulu::getOpiskelijat() const {
    return opiskelijat;
}

string Koulu::getKoulunNimi() const {
    return koulunNimi;
}

void Koulu::setOpettajat(const vector<Sptr<Opettaja>> &val) {
    opettajat = val;
}

void Koulu::setOpiskelijat(const vector<Sptr<Opiskelija>> &val) {
    opiskelijat = val;
}

void Koulu::setKoulunNimi(const string &val) {
    koulunNimi = val;
}

void Koulu::lisaaOpettaja() {
    opettajat.push_back(std::make_shared<Opettaja>(Opettaja{}));
}

void Koulu::lisaaOpiskelija() {
    opiskelijat.push_back(std::make_shared<Opiskelija>(Opiskelija{}));
}

void Koulu::tulostaOpettajat() const {
    for (const auto &i : opettajat)
        i->tulostaTiedot();
}

void Koulu::tulostaOpiskelijat() const {
    for (const auto &i : opiskelijat)
        i->tulostaTiedot();
}

void Koulu::tulostaKaikkiTiedot() const {
    cout << "\nKoulu: " << koulunNimi
        << "\nOpettajien määrä: " << opettajat.size()
        << "\nOpiskelijoiden määrä: " << opiskelijat.size()
        << '\n';
    tulostaOpettajat();
    tulostaOpiskelijat();
}