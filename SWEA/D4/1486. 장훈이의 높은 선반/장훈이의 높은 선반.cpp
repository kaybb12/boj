#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

void print(vector<vector<int>>& vec) {
	for (auto ve : vec) {
		for (auto v : ve) {
			cout << v << " ";
		}
		cout << "\n";
	}
}

int get_sum(vector<int>& vec) {
	int sum = 0;
	for (auto v : vec) {
		sum += v;
	}

	return sum;
}

void dfs(int now, int target, vector<int>& heights, vector<int>& temps, vector<vector<int>>& permus) {
	if (temps.size() >= target) {
		permus.emplace_back(temps);
		return;
	}

	for (int i = now; i < heights.size(); ++i) {
		temps.push_back(heights[i]);
		dfs(i + 1, target, heights, temps, permus);
		temps.pop_back();
	}
}

void dfs2(int now, int summ, int target, int& res, vector<int>& heights, vector<int>& dat) {
	if (summ >= target) {
		res = min(res, summ - target);
		return;
	}

	for (int i = now; i < heights.size(); ++i) {

		summ += heights[i];

		dfs2(i + 1, summ, target, res, heights, dat);

		summ -= heights[i];
	}
}

int get_min(vector<int>& heights, int target) {
	int res = INT_MAX;
	
	/*
	vector<vector<int>> permus;
	for (int i = 1; i <= heights.size(); ++i) {
		vector<int> temps;
		dfs1(0, i, heights, temps, permus);
	}

	//print(permus);
	
	for (auto p : permus) {
		int sum1 = get_sum(p);
		if (sum1 >= target) {
			int temp = abs(target - sum1);
			res = min(res, temp);
		}
	}*/

	vector<int> dat(200000);
	dfs2(0, 0, target, res, heights, dat);

	return res;
}


int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n, b;
		cin >> n >> b;
		vector<int> heigts(n);
		for (int i = 0; i < heigts.size(); ++i) {
			cin >> heigts[i];
		}

		sort(heigts.begin(), heigts.end());
		int ans = get_min(heigts, b);

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}