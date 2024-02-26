#include <iostream>
#include <vector>

using namespace std;

bool is_prime_num(unsigned int n) {
	if (n == 0 || n == 1)
		return false;

	for (unsigned int i = 2; i * i <= n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

unsigned int get_prime_num(unsigned int n) {
	while (!is_prime_num(n)) {
		++n;
	}

	return n;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; ++test_case) {
		unsigned int n;
		cin >> n;
		cout << get_prime_num(n) << "\n";
	}

	return 0;
}