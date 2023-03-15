#include "Paivaus.h"

void Paivaus::setPaiva(const unsigned short _paiva) {
    paiva = _paiva;
}

void Paivaus::setKuukausi(const unsigned short _kuukausi) {
    kuukausi = _kuukausi;
}

void Paivaus::setVuosi(const unsigned short _vuosi) {
    vuosi = _vuosi;
}

unsigned short Paivaus::getPaiva() {
    return paiva;
}

unsigned short Paivaus::getKuukausi() {
    return kuukausi;
}

unsigned short Paivaus::getVuosi() {
    return vuosi;
}

void Paivaus::tulostaPaivays() {
    std::cout << "Paivaus: " << paiva << "." << kuukausi << "." << vuosi << "\n";
}

void Paivaus::luo_uusi_paivaus() {
    std::cout << "\nAnna paiva: ";
    std::cin >> paiva;

    std::cout << "Anna kuukausi: ";
    std::cin >> kuukausi;

    std::cout << "Anna vuosi: ";
    std::cin >> vuosi;
}

void Paivaus::lis‰‰_paiva() {
    std::cout << "\nLisataan uusi paiva\n";

    paiva += 1;
    if (paiva > 30) {
        kuukausi += 1;
        paiva = 1;
    }
    if (kuukausi > 12) {
        vuosi += 1;
        kuukausi = 1;
    }
}