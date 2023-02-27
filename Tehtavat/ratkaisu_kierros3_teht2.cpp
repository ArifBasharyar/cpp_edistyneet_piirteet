#include<iostream>
using namespace std;

void sekunnit_ajaksi(const int *const x, int *const a, int *const b, int *const c);
void aika_sekunneiksi(int *const x, const int *const a, const int *const b, const int *const c);

int main() {
	const int X = 10'000;
	int a{}, b{}, c{}, y{};

	sekunnit_ajaksi(&X, &a, &b, &c);
	cout << X << " sekunttia on " << a << " tuntia, " << b << " minuuttia, ja " << c << " sekunttia.\n";
	
	aika_sekunneiksi(&y, &a, &b, &c);
	cout << "Joka on " << y << " sekunttia ";

	return 0;
}

void sekunnit_ajaksi(const int *const x, int *const a, int *const b, int *const c) {
	*a = *x / 3600;
	*b = (*x % 3600) / 60;
	*c = *x % 60;
}

void aika_sekunneiksi(int *const x, const int *const a, const int *const b, const int *const c) {
	*x = *a * 3600 + *b * 60 + *c;
}