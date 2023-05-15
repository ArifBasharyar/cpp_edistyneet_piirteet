#pragma once
#include <iostream>
#include <string>

using u16 = std::uint16_t;
using std::cout;
using std::cin;

class Paivaus {
    u16 paiva{};
    u16 kuukausi{};
    u16 vuosi{};
public:
    Paivaus(
        const u16 _paiva, 
        const u16 _kuukausi, 
        const u16 _vuosi):
        paiva(_paiva),
        kuukausi(_kuukausi),
        vuosi(_vuosi) {};
    Paivaus() {};
    ~Paivaus() {};

    void setPaiva(const u16 _paiva);
    void setKuukausi(const u16 _kuukausi);
    void setVuosi(const u16 _vuosi);
    unsigned short getPaiva() const;
    unsigned short getKuukausi() const;
    unsigned short getVuosi() const;
    void tulostaPaivays() const;
    void luo_uusi_paivaus();
    void lis‰‰_paiva();
};
