#include "Osoite.h"

Osoite::Osoite(
    const string &_katuosoite,
    const string &_postinumero,
    const string &_kunta):
    katuosoite(_katuosoite),
    postinumero(_postinumero),
    kunta(_kunta) {
    //cout << "Osoite-luokan 3 parametrinen rakentaja\n";
}

Osoite::Osoite():
    katuosoite(),
    postinumero(),
    kunta() {
    //cout << "Osoite-luokan parametriton rakentaja\n";
}

Osoite::Osoite(const Osoite &rhs):
    katuosoite(rhs.katuosoite),
    postinumero(rhs.postinumero),
    kunta(rhs.kunta) {
    //cout << "Osoite-luokan kopio rakentaja\n";
}

Osoite &Osoite::operator=(const Osoite &rhs) {
    if (&rhs != this) {
        katuosoite = rhs.katuosoite;
        postinumero = rhs.postinumero;
        kunta = rhs.kunta;
    }
    //cout << "Osoite-luokan kopio sijoittaja\n";
    return *this;
}

Osoite::Osoite(Osoite &&rhs) noexcept:
    katuosoite(std::exchange(rhs.katuosoite, "")),
    postinumero(std::exchange(rhs.postinumero, "")),
    kunta(std::exchange(rhs.kunta, "")) {
    //cout << "Osoite-luokan liikuttava rakentaja\n";
}

Osoite &Osoite::operator=(Osoite &&rhs) noexcept {
    if (&rhs != this) {
        katuosoite = std::exchange(rhs.katuosoite, katuosoite);
        postinumero = std::exchange(rhs.postinumero, postinumero);
        kunta = std::exchange(rhs.kunta, kunta);
    }
    //cout << "Osoite-luokan liikuttava sijoittaja\n";
    return *this;
}

Osoite::~Osoite() {
    //cout << "Osoite-luokan tuhoaja\n";
}

void Osoite::setKatuosoite(const string &_katuosoite) {
    katuosoite = _katuosoite;
}

void Osoite::setPostinumero(const string &_postinumero) {
    postinumero = _postinumero;
}

void Osoite::setKunta(const string &_kunta) {
    kunta = _kunta;
}

string Osoite::getKatuosoite() const {
    return katuosoite;
}

string Osoite::getPostinumero() const {
    return postinumero;
}

string Osoite::getKunta() const {
    return kunta;
}

void Osoite::tulostaTiedot() const {
    cout << "Katuosoite: " << katuosoite
        << ", Postinumero: " << postinumero
        << ", Kunta: " << kunta << '\n';
}

void Osoite::luoOsoite() {
    cout << "Anna katuosoite: ";
    getline(cin, katuosoite);
    cout << "Anna postinumero: ";
    getline(cin, postinumero);
    cout << "Anna kunta: ";
    getline(cin, kunta);
}
