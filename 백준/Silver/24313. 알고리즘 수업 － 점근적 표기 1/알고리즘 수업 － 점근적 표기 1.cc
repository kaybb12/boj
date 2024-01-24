#include <iostream>

using namespace std;

bool is_asympotic_notation(const int a1, const int a0, const int c, const int n0) {
	if (a1 * n0 + a0 <= c * n0 && a1 <= c)
		return true;
	else
		return false;
}

int main() {
	int a1, a0;
	cin >> a1 >> a0;
	int c;
	cin >> c;
	int n0;
	cin >> n0;

	cout << is_asympotic_notation(a1, a0, c, n0) << "\n";
	return 0;
}