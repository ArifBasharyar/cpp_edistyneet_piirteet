#include <iostream>
using namespace std;


int main() {
    int p = 7;
    int *ptr = &p;

    cout << "muuttuja_p = " << ptr << endl
        << "muuttuja = " << p << endl
        << "&muuttuja_p = " << &ptr << endl
        << "&muuttuja = " << &p << endl
        << "*&muuttuja = " << *&p << endl
        << "&*muuttuja_p = " << &*ptr << endl
        << "sizeof(muuttuja) = " << sizeof(p) << endl
        << "sizeof(muuttuja_p) = " << sizeof(ptr) << endl;

    ptr = nullptr;
    cout << *ptr;

    return 0;
}
