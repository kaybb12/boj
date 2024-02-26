#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int count_set_num(const vector<int>& set_A, const vector<int>& set_B) {
	int cnt = 0;
	for (const auto b : set_B) {
		if (!binary_search(set_A.begin(), set_A.end(), b))
			++cnt;
	}

	for (const auto a : set_A) {
		if (!binary_search(set_B.begin(), set_B.end(), a))
			++cnt;
	}

	return cnt;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> set_A(n);
	vector<int> set_B(m);

	for (int i = 0; i < n; ++i)
		cin >> set_A[i];
	for (int i = 0; i < m; ++i)
		cin >> set_B[i];

	sort(set_A.begin(), set_A.end());
	sort(set_B.begin(), set_B.end());
	cout << count_set_num(set_A, set_B) << "\n";

	return 0;
}