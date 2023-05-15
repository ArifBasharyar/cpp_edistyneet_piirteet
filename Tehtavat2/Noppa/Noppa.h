#pragma once
#include <random>
#include <iostream>

#define u16 unsigned short

class Noppa {
private:
    u16 noppa_lkm{};
    u16 noppa1{};
    u16 noppa2{};
    u16 noppa3{};
    u16 noppa4{};
    u16 noppa5{};

    u16 getRandArvo();

public:
    Noppa();
    Noppa(u16 lkm);
    ~Noppa() {}
    u16 getViimeisinLukema();
    void heitaNoppaa();
    void kerroViimeisenHeitonLukema();
    u16 getNoppaLkm();
    void setNoppaLkm(u16 lkm);
};
