#include <array>
#include <iostream>
#include <vector>

using namespace std;

using Point = pair<int, int>;
using Matrix = vector<vector<int>>;

int get_max(const vector<Point>& package, const int max_weight) {
	Matrix bag(105, vector<int>(100005));

	for (int i = 1; i <= package.size(); ++i) {
		for (int j = 1; j <= max_weight; ++j) {
			auto [ weight, price ] = package[i];

			if (weight <= j) {
				if ((price + bag[i - 1][j - weight]) > bag [i - 1][j])
					bag[i][j] = price + bag[i - 1][j - weight];
				else
					bag[i][j] = bag[i - 1][j];
			}
			else
				bag[i][j] = bag[i - 1][j];
		}
	}

	return bag[package.size()][max_weight];
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<Point> package;
	package.emplace_back(0, 0);

	for (int i = 0; i < n; ++i) {
		int w, v;
		cin >> w >> v;
		package.emplace_back(w, v);
	}

	cout << get_max(package, k) << "\n";

	return 0;
}