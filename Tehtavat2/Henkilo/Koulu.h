#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "Opettaja.h"
#include "Opiskelija.h"

using std::string;
using std::vector;
using std::cout;
template<typename T> using Sptr = std::shared_ptr<T>;

//Sptr<int> a{};
class Koulu {
    vector<Sptr<Opettaja>> opettajat{};
    vector<Sptr<Opiskelija>> opiskelijat{};
    string koulunNimi{};
public:
    Koulu();

    Koulu(const Koulu &rhs);
    Koulu &operator=(const Koulu &rhs);

    Koulu(Koulu &&rhs) noexcept;
    Koulu &operator=(Koulu &&rhs) noexcept;

    ~Koulu();

    vector<Sptr<Opettaja>> getOpettajat() const;
    vector<Sptr<Opiskelija>> getOpiskelijat() const;
    string getKoulunNimi() const;

    void setOpettajat(const vector<Sptr<Opettaja>> &val);
    void setOpiskelijat(const vector<Sptr<Opiskelija>> &val);
    void setKoulunNimi(const string &val);

    void lisaaOpettaja();
    void lisaaOpiskelija();

    void tulostaOpettajat() const;
    void tulostaOpiskelijat() const;
    void tulostaKaikkiTiedot() const;
};
