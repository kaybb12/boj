#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime_num(const int n) {
	if (n == 1) {
		return false;
	}

	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0)
			return false;		
	}

	return true;
}

pair <int, int> find_prime_num(const int to, const int from) {
	vector<int> prime_nums;
	int sum = 0;

	for (int i = to; i <= from; ++i) {		
		if(is_prime_num(i)) {
			prime_nums.push_back(i);
			sum += i;
		}
	}

	if (sum == 0) {
		return { sum, 0 };
	}

	return { sum, prime_nums[0] };
}

int main() {
	int to, from;
	cin >> to >> from;

	auto [sum, min] = find_prime_num(to, from);

	if (sum == 0) {
		cout << -1 << "\n";
	}

	else {		
		cout << sum << "\n";
		cout << min << "\n"; 
	}

	return 0;
}