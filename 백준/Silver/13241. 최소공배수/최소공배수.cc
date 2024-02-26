#include <iostream>

using namespace std;

using ll = long long;

ll get_GCD(ll a, ll b) {
	if (a > b) {
		while (b != 0) {
			ll temp;
			temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}
	else {
		while (a != 0) {
			ll temp;
			temp = b % a;
			b = a;
			a = temp;
		}
		return b;
	}
}

inline ll get_LCM(const ll a, const ll b) {
	ll GCD = get_GCD(a, b);
	return a * b / GCD; 
}

int main() {
	ll a, b;
	cin >> a >> b;

	cout << get_LCM(a, b) << "\n";

	return 0;
}