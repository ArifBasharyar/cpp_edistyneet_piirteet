#include <iostream>
using namespace std;

// Indeksoiva lis‰ys
void lisaa(int a[], int b);
// Osoitinaritmetiikka tulostus
void tulosta(int *a, int b);
// Osoitinaritmetiikka vaihto
void vaihda(int *ptr1, int *ptr2);
// Osoitinaritmetiikka k‰‰ntˆ
void kaanna(int *a, int b);


int main() {
    const int KOKO = 10;
    int arr[KOKO]{};

    // Lis‰‰ luvut ja tulosta ne
    lisaa(arr, KOKO);
    tulosta(arr, KOKO);

    // K‰‰nn‰ luvut ja tulosta ne
    kaanna(arr, KOKO);
    tulosta(arr, KOKO);

    return 0;
}

void lisaa(int a[], int b) {
    for(int i = 0, j = 1; i < b; i++, j++) {
        a[i] += j;
    }
}

void tulosta(int *a, int b) {
    for(int i = 0; i < b; i++) {
        cout << *a++ << " ";
    }
    cout << endl;
}

void vaihda(int *ptr1, int *ptr2) {
    int tila = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tila;
}

void kaanna(int *a, int b) {
    for(int m = b - 1; m > 0; m--) {
        for(int i = 0; i < m; i++) {
            if(*(a + i) < *(a + i + 1)) {
                vaihda(&*(a + i), &*(a + i + 1));
            }
        }
    }
}
