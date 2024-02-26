#include <iostream>
#include <vector>

using namespace std;

vector<bool> Eratos(const int n) {
	vector<bool> primes(n + 1, true);

	for (int i = 2; i * i <= n; ++i) {
		if (primes[i]) {
			for (int j = i * i; j <= n; j += i)
				primes[j] = false;
		}
	}

	return primes;
}

int count_partition(const int n) {
	int cnt = 0;

	vector<bool> primes = Eratos(n);

	for (int i = 2; i <= n; ++i) {
		if(primes[i]) {
			if(primes[n - i])
				++cnt;
			if (n == 2 * i)
				++cnt;
		}
	}
	return cnt / 2;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; ++test_case) {
		int n;
		cin >> n;
		cout << count_partition(n) << "\n";
	}

	return 0;
}