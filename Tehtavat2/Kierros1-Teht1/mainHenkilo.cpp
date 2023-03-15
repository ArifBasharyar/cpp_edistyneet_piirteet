#include "henkilo.h"

int main() {

    Henkilo henkilo1;
    henkilo1.setNimi("James Bond");
    henkilo1.setIka(45);
    std::string nimi1 = henkilo1.getNimi();
    int ika1 = henkilo1.getIka();
    henkilo1.tulostaHenkilonTiedot();

    Henkilo henkilo2("esim", 22);
    henkilo2.setNimi("John Wick");
    henkilo2.setIka(55);
    std::string nimi2 = henkilo2.getNimi();
    int ika2 = henkilo2.getIka();
    henkilo2.tulostaHenkilonTiedot();

    std::cout << "\nIka 2: " << ika2;

    return 0;
}

