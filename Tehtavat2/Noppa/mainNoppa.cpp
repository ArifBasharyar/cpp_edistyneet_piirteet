#include "Noppa.h"

int main() {
    Noppa monopoli(2);
    monopoli.heitaNoppaa();
    monopoli.kerroViimeisenHeitonLukema();

    monopoli.setNoppaLkm(5);
    monopoli.kerroViimeisenHeitonLukema();
    monopoli.heitaNoppaa();
    monopoli.kerroViimeisenHeitonLukema();

    return 0;
}
