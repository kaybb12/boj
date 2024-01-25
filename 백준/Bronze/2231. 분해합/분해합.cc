#include <iostream>

using namespace std;

int get_constroduction(const int N) {

	for (int i = 0; i < N; ++i) {
		int sum = 0;
		for (int k = i; k != 0; k /= 10) {
			sum += k % 10;
		}
		if (sum + i == N) {
			return i;
		}
	}

	return 0;
}

int main() {
	int N;
	cin >> N;

	cout << get_constroduction(N) << "\n";

	return 0;
}