#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Henkilo.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;

class Opettaja: public Henkilo {
    string koulutusala{};
    vector<string> kurssit{};
public:
    Opettaja(
        const string &_nimi,
        const int &_ika,
        const Osoite &_osoite,
        const string &_koulutus);
    Opettaja();

    Opettaja(const Opettaja &rhs);
    Opettaja &operator=(const Opettaja &rhs);

    Opettaja(Opettaja &&rhs) noexcept;
    Opettaja &operator=(Opettaja &&rhs) noexcept;

    ~Opettaja();

    string getKoulutus() const;
    vector<string> getKurssit() const;

    void tulostaTiedot() const override;

    void setKoulutus(const string &_koulutus);
    void lisaaKurssi(const string &_kurssi);
    void poistaKurssi(const string &_kurssi);

    void luoOpettaja();
};

