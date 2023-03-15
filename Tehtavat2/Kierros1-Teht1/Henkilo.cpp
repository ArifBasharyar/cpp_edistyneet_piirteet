#include "henkilo.h"

void Henkilo::setNimi(const std::string _nimi) {
	nimi = _nimi;
}

void Henkilo::setIka(const unsigned int _ika) {
	ika = _ika;
}

std::string Henkilo::getNimi() {
	return nimi;
}

unsigned int Henkilo::getIka() {
	return ika;
}

void Henkilo::tulostaHenkilonTiedot() {
	std::cout << "Nimi: " << nimi << "\n" << "ika: " << ika << "\n";
}