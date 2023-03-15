#include "Paivaus.h"

int main() {

    Paivaus tanaan{};
    tanaan.setPaiva(15);
    tanaan.setKuukausi(03);
    tanaan.setVuosi(2023);
    unsigned short paiva1 = tanaan.getPaiva();
    unsigned short kuukausi1 = tanaan.getKuukausi();
    unsigned short vuosi1 = tanaan.getVuosi();
    tanaan.tulostaPaivays();

    Paivaus huomenna{};
    huomenna.setPaiva(16);
    huomenna.setKuukausi(03);
    huomenna.setVuosi(2023);
    unsigned short paiva2 = huomenna.getPaiva();
    unsigned short kuukausi2 = huomenna.getKuukausi();
    unsigned short vuosi2 = huomenna.getVuosi();
    huomenna.tulostaPaivays();

    Paivaus paivaus3{};
    paivaus3.luo_uusi_paivaus();
    paivaus3.tulostaPaivays();
    paivaus3.lis‰‰_paiva();
    paivaus3.tulostaPaivays();

    return 0;
}

