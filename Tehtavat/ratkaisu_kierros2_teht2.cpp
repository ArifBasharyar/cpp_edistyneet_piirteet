#include<iostream>
#include<math.h>

using namespace std;

int main() {
	float ans{};

	cout << "Anna reaaliluku: ";
	cin >> ans;

	float ans_floor = floor(ans);
	float ans_ceil = ceil(ans);

	cout << "Luku " << ans << " sisaltyy valille " << ans_floor << " ja " << ans_ceil;

	return 0;
}
