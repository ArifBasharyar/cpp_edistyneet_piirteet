#include "Paivaus.h"

void Paivaus::setPaiva(const u16 _paiva) {
    paiva = _paiva;
}

void Paivaus::setKuukausi(const u16 _kuukausi) {
    kuukausi = _kuukausi;
}

void Paivaus::setVuosi(const u16 _vuosi) {
    vuosi = _vuosi;
}

unsigned short Paivaus::getPaiva() const {
    return paiva;
}

unsigned short Paivaus::getKuukausi() const {
    return kuukausi;
}

unsigned short Paivaus::getVuosi() const {
    return vuosi;
}

void Paivaus::tulostaPaivays() const {
    cout << "Paivaus: " << paiva << "." << kuukausi << "." << vuosi << "\n";
}

void Paivaus::luo_uusi_paivaus() {
    cout << "\nAnna paiva: ";
    cin >> paiva;

    cout << "Anna kuukausi: ";
    cin >> kuukausi;

    cout << "Anna vuosi: ";
    cin >> vuosi;
}

void Paivaus::lis‰‰_paiva() {
    cout << "\nLisataan uusi paiva\n";

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