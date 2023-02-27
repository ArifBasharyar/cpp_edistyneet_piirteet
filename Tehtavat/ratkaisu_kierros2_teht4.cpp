#include<iostream>
using namespace std;

bool prime_all(const int &x);
bool prime_half(const int &x);
bool prime_square_root(const int &x);

int main() {
	const int MAX = 10'000;
	int counter{};

	for (int i = 1; i <= MAX; i++) {
		if (prime_square_root(i)) {
			cout << i << " on alkuluku\n";
			counter += 1;
		}
	}
	int prc = (float)counter / (float)MAX * (float)100;

	cout << "\n" << counter << " lukua ovat alkulukuja.\n"
		<< "Eli " << prc << " prosenttia 10 000 luvusta ovat alkulukuja\n";

	return 0;
}

bool prime_all(const int &x) {
	if (x <= 1) {
		return false;
	}
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

bool prime_half(const int &x) {
	if (x <= 1) {
		return false;
	}
	for (int i = 2; i*2 <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

bool prime_square_root(const int &x) {
	if (x <= 1) {
		return false;
	}
	for (int i = 2; i*i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
