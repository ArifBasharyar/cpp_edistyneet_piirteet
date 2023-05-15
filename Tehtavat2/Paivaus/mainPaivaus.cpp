#include "Merkinta.h"

int main() {
    Merkinta merkinta1;
    Merkinta merkinta2(Paivaus(12, 05, 2045),
                       "Muistuta minua jostain toisesta",
                       true);

    merkinta1.setPaivaus(Paivaus(31, 12, 1455));
    merkinta1.setAsia("Muistuta ensin jostain");
    merkinta1.setMuistutus(false);

    merkinta1.tulostaMerkinta();
    merkinta2.tulostaMerkinta();

    merkinta1.kysyTiedot();
    merkinta1.tulostaMerkinta();

    Merkinta merkinta3{merkinta1};
    merkinta3.tulostaMerkinta();

    doSomethingArvoparametri(merkinta2);
    doSomethingViittausparametri(merkinta3);
    merkinta3.tulostaMerkinta();

    return 0;
}
