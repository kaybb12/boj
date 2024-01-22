#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void do_factorization(const int N) {
	int num = N;

	for (int i = 2; i <= sqrt(num); ++i) {
		while (num % i == 0) {
			cout << i << "\n";
			num /= i;
		}
	}

	if (num != 1)
		cout << num << "\n"; 
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	if (N == 1) 
		return 0;

	do_factorization(N);

	return 0;
}