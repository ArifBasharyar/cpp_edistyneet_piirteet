#pragma once
#include <iostream>
#include <string>

class Paivaus {
private:
    unsigned short paiva{};
    unsigned short kuukausi{};
    unsigned short vuosi{};

public:
    Paivaus(
        unsigned short _paiva,
        unsigned short _kuukausi,
        unsigned short _vuosi)
        : paiva(_paiva),
        kuukausi(_kuukausi),
        vuosi(_vuosi) {};
    Paivaus() {};
    ~Paivaus() {};

    void setPaiva(const unsigned short _paiva);
    void setKuukausi(const unsigned short _kuukausi);
    void setVuosi(const unsigned short _vuosi);
    unsigned short getPaiva();
    unsigned short getKuukausi();
    unsigned short getVuosi();
    void tulostaPaivays();
    void luo_uusi_paivaus();
    void lis‰‰_paiva();

};
