#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Henkilo.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;

class Opiskelija: public Henkilo {
    string opNro{};
    vector<string> suoritetutKurssit{};
    int opintopisteet{};
public:
    Opiskelija(
        const string &_nimi,
        const int &_ika,
        const Osoite &_osoite,
        const string &_nro,
        const int &_pisteet);
    Opiskelija();

    Opiskelija(const Opiskelija &rhs);
    Opiskelija &operator=(const Opiskelija &rhs);

    Opiskelija(Opiskelija &&rhs) noexcept;
    Opiskelija &operator=(Opiskelija &&rhs) noexcept;

    ~Opiskelija();

    string getOpNro() const;
    vector<string> getKurssit() const;
    int getOpintoPisteet() const;

    void tulostaTiedot() const override;

    void setOpNro(const string &_nro);
    void lisaaKurssi(const string &_kurssi);
    void poistaKurssi(const string &_kurssi);
    void lisaaPisteita(const int &_pisteet = 1);

    void luoOpiskelija();
};

