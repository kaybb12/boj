#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int get_max_degree(const int day, const int bundle, const array<int, 100001>& sums) {
	int max_degree = INT_MIN;

	for (int i = bundle; i <= day; ++i) {
		max_degree = max(max_degree, (sums[i] - sums[i - bundle]));
	}

	return max_degree;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int day, bundle;
	array<int, 100001> sums;

	cin >> day >> bundle;

	for (int i = 1; i <= day; ++i) {
		int temp;
		cin >> temp;
		sums[i] = sums[i - 1] + temp;
	}

	cout << get_max_degree(day, bundle, sums) << "\n";

	return 0;
}