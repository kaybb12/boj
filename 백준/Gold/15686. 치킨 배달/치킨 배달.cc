#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
using MAP = vector<vector<int>>;
using Point = pair<int, int>;

void print(vector<int>& vec) {
	for (auto v : vec) {
		cout << v << " ";
	}
	cout << '\n';
}

void print_vec(vector<vector<int>>& vec) {
	for (auto ve : vec) {
		for (auto v : ve) {
			cout << v << " ";
		}
		cout << "\n";
	}
}

void make_permutations(int st, int m, int size, vector<int>& permutation, vector<vector<int>>& permutations) {
	if (permutation.size() >= m) {
		permutations.emplace_back(permutation);
		//print(permutation);
		return;
	}

	for (int i = st; i < size; ++i) {
		permutation.push_back(i);
		make_permutations(i + 1, m, size, permutation, permutations);
		permutation.pop_back();
	}

	return;
}

int get_chicken_distance(int m, vector<Point>& homes, vector<Point>& chickens, MAP& Map) {
	int res = 0;

	if (m < chickens.size()) {
		vector<int> permutation;
		vector<vector<int>> permutations;
		make_permutations(0, m, chickens.size(), permutation, permutations);
		//print_vec(permutations);
		res = INT_MAX;
		for (auto& per : permutations) {
			int temp1 = 0;
			for (auto h : homes) {
				int temp2 = INT_MAX;
				for (auto i : per) {
					int y = abs(h.first - chickens[i].first);
					int x = abs(h.second - chickens[i].second);
					temp2 = min(temp2, y + x);
				}
				temp1 += temp2;
			}
			res = min(temp1, res);
		}
	}
	else {
		for (int i = 0; i < homes.size(); ++i) {
			int temp = INT_MAX;
			for (int j = 0; j < chickens.size(); ++j) {
				int y = abs(homes[i].first - chickens[j].first);
				int x = abs(homes[i].second - chickens[j].second);
				temp = min(temp, x + y);
			}
			res += temp;
		}
	}

	return res;
}

int main() {
	int n, m;
	cin >> n >> m;

	MAP Map(n + 1, vector<int>(n + 1, 0));
	vector<Point> homes;
	vector<Point> chickens;
	for (int r = 1; r <= n; ++r) {
		for (int c = 1; c <= n; ++c) {
			cin >> Map[r][c];
			if (Map[r][c] == 1) {
				homes.emplace_back(r, c);
			}
			if (Map[r][c] == 2) {
				chickens.emplace_back(r, c);
			}
		}
	}

	int ans = get_chicken_distance(m, homes, chickens, Map);

	cout << ans << "\n";
}