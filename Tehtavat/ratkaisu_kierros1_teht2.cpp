#include <iostream>
using namespace std;

void vaihda1(int *ptr1, int *ptr2);
void vaihda2(int &ref1, int &ref2);

int main() {
    int a = 1, b = 2, c = 3, d = 4;
    
    cout << a << "\t" << b << endl;
    vaihda1(&a, &b);
    cout << a << "\t" << b << endl << endl;

    cout << c << "\t" << d << endl;
    vaihda2(c, d);
    cout << c << "\t" << d;

    return 0;
}

void vaihda1(int *ptr1, int *ptr2) {
    int tila = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tila;
}

void vaihda2(int &ref1, int &ref2) {
    int tila = ref1;
    ref1 = ref2;
    ref2 = tila;
}
