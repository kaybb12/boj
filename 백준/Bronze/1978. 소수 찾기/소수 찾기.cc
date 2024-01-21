#include <iostream>
#include <vector>

using namespace std;

bool is_prime_num(const int num) {
	
	if (num == 1)
		return false;
	if (num == 2)
		return true;
	else {
		for (int i = 2; i < num; ++i) {
			if (num % i == 0)
				return false;
		}
	}
	
	return true;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int cnt = 0;

	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;

		if(is_prime_num(num))
			++cnt;
	}

	cout << cnt << "\n";

	return 0;
}