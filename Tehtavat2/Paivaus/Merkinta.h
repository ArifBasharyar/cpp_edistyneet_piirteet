#pragma once
#include <iostream>
#include <string>
#include "Paivaus.h"

using std::string;
using std::cout;
using std::cin;
 
class Merkinta {
    Paivaus paivaus{};
    string asia{};
    bool muistutus{};
public:
    Merkinta(const Paivaus &_paivaus,
             const string &_asia,
             const bool &_muistutus);
    Merkinta(const Merkinta &m);
    Merkinta(Merkinta &&m) noexcept;
    Merkinta() {}
    ~Merkinta() {}

    void setPaivaus(const Paivaus &_paivaus);
    void setAsia(const string &_asia);
    void setMuistutus(const bool &_muistutus);
    Paivaus getPaivaus() const;
    string getAsia() const;
    bool getMuistutus() const;
    void tulostaMerkinta() const;
    void kysyTiedot();
};

 void doSomethingArvoparametri(Merkinta aKalenterimerkinta) {
    return;
}

 void doSomethingViittausparametri(const Merkinta &aKalenterimerkinta) {
    return;
}
