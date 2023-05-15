#pragma once
#include <iostream>
#include <string>
#include "Osoite.h"

using std::string;
using std::cout;
using std::cin;

class Henkilo {
protected:
    string nimi{};
    int ika{};
    Osoite osoite{};
public:
    Henkilo();
    Henkilo(const string &, const int &, const Osoite &);

    Henkilo(const Henkilo &);
    Henkilo &operator=(const Henkilo &);

    Henkilo(Henkilo &&) noexcept;
    Henkilo &operator=(Henkilo &&) noexcept;

    ~Henkilo();

    void setNimi(const string &);
    void setIka(const int &);
    void setOsoite(const Osoite &);
    string getNimi() const;
    int getIka() const;
    Osoite getOsoite() const;
    virtual void tulostaTiedot() const;
    void luoHenkilo();
};
