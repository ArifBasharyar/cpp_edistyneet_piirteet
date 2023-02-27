#include<iostream>
using namespace std;

enum Triangle {
	Equilateral,
	Isocles,
	Scalene,
	Right,
	Impositionsible
};

Triangle check_triangle(float a, float b, float c, Triangle triangle);
void print_type(const Triangle triangle);

int main() {
	int a{}, b{}, c{};
	Triangle triangle{};

	cout << "Sivu 1: ";
	cin >> a;
	cout << "Sivu 2: ";
	cin >> b;
	cout << "Sivu 3: ";
	cin >> c;

	triangle = check_triangle(a, b, c, triangle);
	print_type(triangle);

	return 0;
}

Triangle check_triangle(float a, float b, float c, Triangle triangle) {
	if(a + b > c || a + c > b || b + c > a) {
		if((a * a + b * b == c * c) || (c * c + b * b == a * a) || (a * a + c * c == b * b)) {
			return Right;
		} else if(a == b && b == c && a == c) {
			return Equilateral;
		} else if(a == b || b == c || a == c) {
			return Isocles;
		} else {
			return Scalene;
		}
	} else {
		return Impositionsible;
	}
}

void print_type(const Triangle triangle) {
	switch(triangle) {
	case Equilateral:
		cout << "Kolmio on tasasivuinen.";
		break;
	case Isocles:
		cout << "Kolmio on tasakylkinen.";
		break;
	case Scalene:
		cout << "Kolmio on epäsäännollinen.";
		break;
	case Right:
		cout << "Kolmio on suorakulmainen.";
		break;
	case Impositionsible:
		cout << "Kolmio on mahdoton.";
		break;
	default:
		cout << "Kolmio on mahdoton.";
		break;
	}
}
