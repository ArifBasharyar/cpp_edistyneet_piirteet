#include <iostream>
using namespace std;

// Indeksoiva lis‰ys
void lisaa1(int a[], int b);
// Indeksoiva v‰hennys
void vahenna(int a[], int b);
// Osoitinaritmetiikka lis‰ys
void lisaa2(int *a, int b);
// Osoitinaritmetiikka tulostus
void tulosta(int *a, int b);

int main() {
    const int KOKO = 10;
    int arr[KOKO]{};

    // Tulosta ensimm‰inen kerta
    tulosta(arr, KOKO);

    // Lis‰‰ ja tulosta toinen kerta
    lisaa1(arr, KOKO);
    tulosta(arr, KOKO);

    // V‰henn‰ ja tulosta kolmas kerta
    cout << endl;
    vahenna(arr, KOKO);
    tulosta(arr, KOKO);

    // Lis‰‰ uudestaan ja tulosta nelj‰s kerta
    lisaa2(arr, KOKO);
    tulosta(arr, KOKO);

    return 0;
}

void lisaa1(int a[], int b) {
    for(int i = 0; i < b; i++) {
        a[i]++;
    }
}

void vahenna(int a[], int b) {
    for(int i = 0; i < b; i++) {
        a[i]--;
    }
}

void lisaa2(int *a, int b) {
    for(int i = 0; i < b; i++) {
        *a += 1;
        a++;
    }
}

void tulosta(int *a, int b) {
    for(int i = 0; i < b; i++) {
        cout << *a << " ";
        a++;
    }
    cout << endl;
}
