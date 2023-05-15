#include <string>
#include <iostream>
#include <conio.h>
#include "Koulu.h"

using std::cout;
using std::cin;
using std::string;

string getString(const std::string_view str) {
    cout << str;
    string tmp{}; 
    cin.clear(); 
    cin.ignore();
    getline(cin, tmp); 
    cin.clear();
    return tmp;
};

struct Valikko {
    char val{'0'};

    void set() {
        cout
            << "\nValikko 1: Lisää uusi opettaja."
            << "\nValikko 2: Lisää opettajalle uusi kurssi."
            << "\nValikko 3: Lisää uusi opiskelija."
            << "\nValikko 4: Lisää opiskelijalle uusi kurssi."
            << "\nValikko 5: Tulosta opettajat."
            << "\nValikko 6: Tulosta opiskelijat."
            << "\nValikko 7: Tulosta koulun tiedot.";

        val = _getch();
        system("cls");
    }
};

int main() {
    setlocale(LC_ALL, "fi_FI");
    Koulu koulu{};
    Valikko valikko{};
    string tmp{};

    koulu.setKoulunNimi(getString("Anna koulun nimi: "));
    system("cls");

    while (true) {
        switch (valikko.val) {
        case '0':
            cout << "Valikko 0\n" << "\nMihin valikkoon haluat siirtyä?";
            valikko.set();
            break;
        case '1':
            cout << "Valikko 1\n";
            koulu.lisaaOpettaja();
            valikko.set();
            break;
        case '2':
            cout << "Valikko 2\n";
            tmp = getString("Anna valittavan opettajan nimi: ");
            for (const auto &x : koulu.getOpettajat())
              if (x->getNimi().find(tmp) == 0)
                    x->lisaaKurssi(getString("Anna lisättävän kurssin nimi: "));
            valikko.set();
            break;
        case '3':
            cout << "Valikko 3\n";
            koulu.lisaaOpiskelija();
            valikko.set();
            break;
        case '4':
            cout << "Valikko 4\n";
            tmp = getString("Anna valittavan opiskelijan nimi: ");
            for (const auto &x : koulu.getOpiskelijat())
                if (x->getNimi().find(tmp) == 0)
                    x->lisaaKurssi(getString("Anna lisättävän kurssin nimi: "));
            valikko.set();
            break;
        case '5':
            cout << "Valikko 5\n";
            koulu.tulostaOpettajat();
            valikko.set();
            break;
        case '6':
            cout << "Valikko 6\n";
            koulu.tulostaOpiskelijat();
            valikko.set();
            break;
        case '7':
            cout << "Valikko 7\n";
            koulu.tulostaKaikkiTiedot();
            valikko.set();
            break;
        default:
            cout << "Lopetetaan ohjelma\n";
            return 0;
            break;
        }
    }
    return 0;
}