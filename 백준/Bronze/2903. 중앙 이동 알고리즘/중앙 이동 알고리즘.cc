#include <iostream>
#include <vector>

using namespace std;

int is_save_dot(const int N) {
	int dot = 2;

	for (int i = 1; i <= N; ++i) {
		dot = 2 * dot - 1;
	}

	return dot * dot;
} 

int main() {
	int N;
	cin >> N;
	cout << is_save_dot(N) << "\n";

	return 0;
}