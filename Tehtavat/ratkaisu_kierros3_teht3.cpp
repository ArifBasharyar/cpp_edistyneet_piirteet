#include<iostream>
using namespace std;

struct aika_ty {
	int tunti;
	int minuutti;
	int sekuntti;
};

void vastaus(int &syote, int a_raja, int y_raja);

int main() {
	// Käyttäjä aika
	aika_ty aika{};

	cout << "Anna tunnit: ";
	vastaus(aika.tunti, 0, 23);
	cout << "Anna minuutit: ";
	vastaus(aika.minuutti, 0, 59);
	cout << "Anna sekunnit: ";
	vastaus(aika.sekuntti, 0, 59);
	auto *aika_ptr = &aika;

	cout << "\nAika: " << aika.tunti << ":" << aika.minuutti << ":" << aika.sekuntti
		<< "\nAika_ptr: " << aika_ptr->tunti << ":" << aika_ptr->minuutti << ":" << aika_ptr->sekuntti << "\n";

	// Ennaltamääritetty aika
	aika_ty aika_oma = {6, 38, 53};
	auto aika_kopio = aika_oma;

	cout << "\nAika_oma: " << aika_oma.tunti << ":" << aika_oma.minuutti << ":" << aika_oma.sekuntti
		<< "\nAika_kopio: " << aika_kopio.tunti << ":" << aika_kopio.minuutti << ":" << aika_kopio.sekuntti << "\n";

	if ((aika_kopio.tunti == aika_oma.tunti) && (aika_kopio.minuutti == aika_oma.minuutti) && (aika_kopio.minuutti == aika_oma.minuutti)) {
		cout << "Sisallot ovat samat.\n";
	} else {
		cout << "Sisallot eivät ole samat.\n";
	}

	return 0;
}

void vastaus(int &syote, int a_raja, int y_raja) {
	while (!(cin >> syote) || (syote < a_raja || syote > y_raja)) {
		cin.clear();
		cin.ignore();
		cout << "Yrita uudestaan: ";
	}
}

