#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print_ascending(vector<int>& cnts) {
	for (int i = 1; i < 10001; ++i) {
		for (int j = 0; j < cnts[i]; ++j)
			cout << i << "\n";
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> cnts(10001);
	for (int i = 0; i < n; ++i) {
		int idx;
		cin >> idx;
		cnts[idx] += 1;
	}

	print_ascending(cnts);

	return 0;
}
