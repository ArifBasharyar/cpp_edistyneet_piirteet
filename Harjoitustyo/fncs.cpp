#include "fncs.h"

bool search_within_string(
    const string *const str1,
    const string *const str2,
    size_t *const pos
) {
    // Tarkistaa koot
    if (str1->length() < str2->length())
        return false;

    // Etsii str2 str1:stä
    size_t temp = str1->find(*str2);

    // Jos kaikki mennyt hyvin muuttaa pos arvon ja palauttaa arvon true
    if (temp != string::npos) {
        *pos = temp;
        return true;
    }

    // Jos str2 ei löydy
    return false;
}

bool search_within_string(
    const string *const str1,
    const string *const str2
) {
    // Tarkista koot
    if (str1->length() < str2->length()) return false;

    // Etsi str2 str1:stä
    size_t temp = str1->find(*str2);

    // Jos kaikki mennyt hyvin palauttaa arvon true
    if (temp != string::npos)
        return true;

    // Jos str2 ei löydy
    return false;
}

void option_switch(
    string *const str,
    print_opt *const opt
) {
    // Käytetään stringiä ilman -o:ta
    str->erase(0, 2);

    // Haku merkit
    const string l = "l";
    const string o = "o";
    const string r = "r";
    const string i = "i";

    // Etsi komento argumentteja
    if (search_within_string(str, &l)) opt->l = true;
    if (search_within_string(str, &o)) opt->o = true;
    if (search_within_string(str, &r)) opt->r = true;
    if (search_within_string(str, &i)) opt->i = true;
}

void read_file(
    const string *const str1,
    const string *const str2,
    const print_opt *const opt
) {
    // Muuttujat
    std::ifstream infile(*str1);
    size_t line{}, occ{}, nocc{};
    string temp1{}, temp2{}, low_str{};
    if (opt->i) low_str = *str2;

    // Jos tiedostoa ei löydy
    if (!infile) throw - 1;

    // Jos halutaan, muuttaa haku stringin kirjaimet alemmaksi
    if (opt->i) std::transform(low_str.begin(), low_str.end(),
                               low_str.begin(), ::tolower);

    const auto print_line = [&]() {
        // Lisää haluttua laskuria yhdellä
        opt->r ? nocc += 1 : occ += 1;
        // Jos halutaan tulostaa rivinumero
        if (opt->l) std::cout << line << ":";
        // Tulostetaan haluttu rivi
        std::cout << temp1 << "\n";
    };

    // Etsii haku strigiä
    while (getline(infile, temp1)) {
        line += 1;

        // Jos halutaan etsii alennetuilla kirjaimilla haku stringiä
        if (opt->i) {
            // Käytetään temp2 jotta voidaan tulostaa alkuperäinen rivi temp1
            temp2 = temp1;
            std::transform(temp2.begin(), temp2.end(),
                           temp2.begin(), ::tolower);

            // Jos halutaan tulostaa rivi, kun alennettu haku string löytyy
            if (search_within_string(&temp2, &low_str) && !opt->r)
                print_line();

            // Jos halutaan tulostaa rivi, kun alennettua stringiä ei löydy
            else if (!search_within_string(&temp2, &low_str) && opt->r)
                print_line();

        } else {
            // Jos halutaan tulostaa rivi, kun haku string löytyy
            if (search_within_string(&temp1, str2) && !opt->r)
                print_line();

            // Jos halutaan tulostaa rivi, kun stringiä ei löydy
            else if (!search_within_string(&temp1, str2) && opt->r)
                print_line();
        }
    }

    // Jos halutaan tulostaa rivien määrä
    if (opt->o && !opt->r) std::cout << "\nOccurrences of lines containing \""
        << *str2 << "\": " << occ << "\n";
    if (opt->o && opt->r) std::cout << "\nOccurrences of lines NOT containing \""
        << *str2 << "\": " << nocc << "\n";

    infile.close();
}
