#include<iostream>
using namespace std;

int min(int x, int y);
int min(int x, int y, int z);
int min(int x, int y, int z, int w);
void vastaus(int &syote, int a_raja, int y_raja);

int main() {
	int x{}, *ans{};

	cout << "Montako lukua haluat verrata? MIN 2 ja MAX 4 kertaa.\n";
	vastaus(x, 2, 4);
	ans = new int[x];

	for (int i = 0; i < x; i++) {
		cout << "Anna " << i+1 << ". luku: ";
		vastaus(ans[i], INT_MIN, INT_MAX);
	}

	switch (x) {
	case 2:
		cout << min(ans[0], ans[1]);
		break;
	case 3:
		cout << min(ans[0], ans[1], ans[2]);
		break;
	case 4:
		cout << min(ans[0], ans[1], ans[2], ans[3]);
		break;
	default:
		cout << "Ei käy";
		break;
	}

	delete[] ans;

	return 0;
}

int min(int x, int y) {
	if (x < y) return x;
	return y;
}

int min(int x, int y, int z) {
	int a = min(x, y);
	return min(a, z);
}

int min(int x, int y, int z, int w) {
	int a = min(x, y);
	int b = min(z, w);
	return min(a, b);
}

void vastaus(int &syote, int a_raja, int y_raja) {
	while (!(cin >> syote) || (syote < a_raja || syote > y_raja)) {
		cin.clear();
		cin.ignore();
		cout << "\nYrita uudestaan: ";
	}
}
