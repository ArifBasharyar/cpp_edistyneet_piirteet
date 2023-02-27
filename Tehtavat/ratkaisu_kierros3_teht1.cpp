#include<iostream>
using namespace std;

void sekunnit_ajaksi(const int &x, int *const a, int *const b, int *const c) {
	*a = x / 3600;
	*b = (x % 3600) / 60;
	*c = x % 60;
}

int main() {
	const int X = 10'000;
	int a{}, b{}, c{};
	sekunnit_ajaksi(X, &a, &b, &c);
	cout << X << " sekunttia on " << a << " tuntia, " << b << " minuuttia, ja " << c << " sekunttia.\n";

	return 0;
}