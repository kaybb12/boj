#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
/*
vector<int> get_idxs(vector<ll>& nums) {
	vector<int> idxs(nums.size());
	vector<ll> temps = nums;

	sort(temps.begin(), temps.end());
	temps.erase(unique(temps.begin(), temps.end()), temps.end());

	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 0; j < temps.size(); ++j) {
			if (nums[i] == temps[j]) {
				idxs[i] = j;
				break;
			}
		}
	}

	return idxs;
}*/

vector<int> get_idxs_1(const vector<ll>& nums) {
	vector<int> idxs(nums.size());
	vector<ll> temps = nums;

	sort(temps.begin(), temps.end());
	temps.erase(unique(temps.begin(), temps.end()), temps.end());

	for (int i = 0; i < nums.size(); ++i) {
		auto idx = lower_bound(temps.begin(), temps.end(), nums[i]);
		idxs[i] = idx - temps.begin();
	}

	return idxs;
}

void print (const vector<int>& vec) {
	for (const auto& v : vec)
		cout << v << " ";
	cout << "\n";
}

int main() {
	int n;
	cin >> n;
	vector<ll> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i]; 
	}

	vector<int> idxs = get_idxs_1(nums);
	print(idxs);
}