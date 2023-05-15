#include<iostream>
using std::cout;
using std::cin;

struct aika_ty {
	int tunti;
	int minuutti;
	int sekuntti;
};

void vastaus(int &syote, int a_raja, int y_raja); 
void aika_vas(aika_ty *aika);
void sekunnit_ajaksi(const int *const x, int *const a, int *const b, int *const c);
int aika_sekunneiksi(const int *const a, const int *const b, const int *const c);
bool varmista_vahennettavyys(aika_ty *a, aika_ty *b);
aika_ty aikojen_erotus(aika_ty *a, aika_ty *b);

int main() {
	aika_ty aika1{};
	aika_ty aika2{};

	do {
		cout << "Aika 1:\n";
		aika_vas(&aika1);
		cout << "Aika 2:\n";
		aika_vas(&aika2);
		cout << "\n";
	} while (varmista_vahennettavyys(&aika1, &aika2));

	const auto aika3 = aikojen_erotus(&aika1, &aika2);
	cout << "Aika erotus: " << aika3.tunti << ":" << aika3.minuutti << ":" << aika3.sekuntti << "\n";

	return 0;
}

void vastaus(int &syote, int a_raja, int y_raja) {
	while (!(cin >> syote) || (syote < a_raja || syote > y_raja)) {
		cin.clear();
		cin.ignore();
		cout << "Yrita uudestaan: ";
	}
}

void aika_vas(aika_ty *aika) {
	cout << "Anna tunnit: ";
	vastaus(aika->tunti, 0, 23);
	cout << "Anna minuutit: ";
	vastaus(aika->minuutti, 0, 59);
	cout << "Anna sekunnit: ";
	vastaus(aika->sekuntti, 0, 59);
}

void sekunnit_ajaksi(const int *const x, int *const a, int *const b, int *const c) {
	*a = *x / 3600;
	*b = (*x % 3600) / 60;
	*c = *x % 60;
}

int aika_sekunneiksi(const int *const a, const int *const b, const int *const c) {
	return *a * 3600 + *b * 60 + *c;
}

bool varmista_vahennettavyys(aika_ty *a, aika_ty *b) {
	if (aika_sekunneiksi(&a->tunti, &a->minuutti, &a->sekuntti) > aika_sekunneiksi(&b->tunti, &b->minuutti, &b->sekuntti)) {
		return true;
	}
	return false;
}

aika_ty aikojen_erotus(aika_ty *a, aika_ty *b) {
	const int n = aika_sekunneiksi(&b->tunti, &b->minuutti, &b->sekuntti) - aika_sekunneiksi(&a->tunti, &a->minuutti, &a->sekuntti);
	int x{}, y{}, z{};

	sekunnit_ajaksi(&n, &x, &y, &z);
	return {x, y, z};
}