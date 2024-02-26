#include <iostream>
#include <vector>

using namespace std;

int Euclidean(const int a, const int b) {
	int temp = a % b;
	if (temp == 0)
		return b;
	else
		return Euclidean(b, temp);
}

int get_GCD(const vector<int>& dists) {
	int gcd = dists[0];
	
	for (int i = 0; i < dists.size(); ++i) {
		gcd = Euclidean(gcd, dists[i]);
	}

	return gcd;
}

int get_num_plus_tree(const vector<int>& trees) {
	vector<int> dists;
	for (int i = 0; i < trees.size() - 1; ++i) {
		dists.emplace_back(trees[i + 1] - trees[i]);
	}
	int gcd = get_GCD(dists);
	int cnt = 0;
	for (const auto dist : dists) {
		cnt += (dist / gcd) - 1;
	}

	return cnt;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> trees(n);
	for (int i = 0; i < n; ++i)
		cin >> trees[i];

	cout << get_num_plus_tree(trees) << "\n";

	return 0;
}