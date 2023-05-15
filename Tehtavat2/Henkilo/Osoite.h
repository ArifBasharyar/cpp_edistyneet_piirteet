#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;

class Osoite {
    string katuosoite{};
    string postinumero{};
    string kunta{};
public:
    Osoite(const string &, const string &, const string &);
    Osoite();

    Osoite(const Osoite &rhs);
    Osoite &operator=(const Osoite &rhs);

    Osoite(Osoite &&rhs) noexcept;
    Osoite &operator=(Osoite &&rhs) noexcept;

    ~Osoite();

    void setKatuosoite(const string &);
    void setPostinumero(const string &);
    void setKunta(const string &);
    string getKatuosoite() const;
    string getPostinumero() const;
    string getKunta() const;
    void tulostaTiedot() const;
    void luoOsoite();
};
